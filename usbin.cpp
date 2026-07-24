#include <windows.h>
#include <dbt.h>
#include <iostream>

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    switch (uMsg)
    {
    case WM_DEVICECHANGE:
    {
        switch (wParam)
        {
        case DBT_DEVICEARRIVAL:
            std::cout << "Device Connected!" << std::endl;
            break;

        case DBT_DEVICEREMOVECOMPLETE:
            std::cout << "Device Removed!" << std::endl;
            break;
        }
        break;
    }
    }
    return DefWindowProc(hwnd, uMsg, wParam, lParam);
}

int main()
{
    HINSTANCE hInstance = GetModuleHandle(NULL);

    const char CLASS_NAME[] = "DeviceMonitor";

    WNDCLASS wc = {};
    wc.lpfnWndProc = WindowProc;
    wc.hInstance = hInstance;
    wc.lpszClassName = CLASS_NAME;

    RegisterClass(&wc);

    HWND hwnd = CreateWindowEx(
        0,
        CLASS_NAME,
        "Device Monitor",
        0,
        0, 0, 0, 0,
        HWND_MESSAGE,     // Message-only window
        NULL,
        hInstance,
        NULL);

    if (!hwnd)
    {
        std::cout << "Failed to create window." << std::endl;
        return 1;
    }

    std::cout << "Monitoring USB devices..." << std::endl;

    MSG msg;
    while (GetMessage(&msg, NULL, 0, 0))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return 0;
}
