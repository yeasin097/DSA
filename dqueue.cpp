#include<bits/stdc++.h>
using namespace std;

int main() {
    deque<string>qu;
    qu.push_front("C");
    qu.push_front("B");
    qu.push_front("A");
    qu.push_back("D");


    while(!qu.empty()) {
        cout<< "Now size: " << qu.size() << endl;
        string top = qu.front();
        qu.pop_front();
        cout << top << endl;

        cout<< "Now size: " << qu.size() << endl;
        string back = qu.back();
        qu.pop_back();
        cout << back << endl;
    }
}