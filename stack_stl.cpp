#include<bits/stdc++.h>
using namespace std;

int main() {
    stack<string>stak;
    stak.push("A");
    stak.push("B");
    stak.push("C");
    stak.push("D");

    while(!stak.empty()) {
        cout<< "Now size: " << stak.size() << endl;
        string top = stak.top();
        stak.pop();
        cout << top << endl;
    }
}