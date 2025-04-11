#include<bits/stdc++.h>
using namespace std;

int main() {
    queue<string>qu;
    qu.push("A");
    qu.push("B");
    qu.push("C");
    qu.push("D");

    cout<<qu.back()<<endl;

    while(!qu.empty()) {
        cout<< "Now size: " << qu.size() << endl;
        string top = qu.front();
        qu.pop();
        cout << top << endl;
    }
}