#include <windows.h>

HHOOK keyboardHook = nullptr;
bool injecting = false;

void SendWindowsKey(bool keyDown)
{
    INPUT input = {};
    input.type = INPUT_KEYBOARD;
    input.ki.wVk = VK_LWIN;

    if (!keyDown)
        input.ki.dwFlags = KEYEVENTF_KEYUP;

    injecting = true;
    SendInput(1, &input, sizeof(INPUT));
    injecting = false;
}

LRESULT CALLBACK KeyboardProc(int nCode, WPARAM wParam, LPARAM lParam)
{
    if (nCode >= 0 && !injecting)
    {
        KBDLLHOOKSTRUCT* p = (KBDLLHOOKSTRUCT*)lParam;

        if (p->vkCode == VK_LMENU) // Left Alt
        {
            if (wParam == WM_KEYDOWN || wParam == WM_SYSKEYDOWN)
                SendWindowsKey(true);
            else if (wParam == WM_KEYUP || wParam == WM_SYSKEYUP)
                SendWindowsKey(false);

            return 1; // Block the original Left Alt key
        }
    }

    return CallNextHookEx(keyboardHook, nCode, wParam, lParam);
}

int WINAPI WinMain(HINSTANCE hInstance,
                   HINSTANCE,
                   LPSTR,
                   int)
{
    ShowWindow(GetConsoleWindow(), SW_HIDE);
    keyboardHook = SetWindowsHookEx(
        WH_KEYBOARD_LL,
        KeyboardProc,
        GetModuleHandle(NULL),
        0);

    if (!keyboardHook)
        return 1;

    MSG msg;
    while (GetMessage(&msg, NULL, 0, 0))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    UnhookWindowsHookEx(keyboardHook);
    return 0;
}
