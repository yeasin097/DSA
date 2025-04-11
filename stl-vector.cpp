#include<bits/stdc++.h>
using namespace std;

int main() {
    vector<int>vect;
    int n;
    cin>>n;
    while(n--) {
        int x; cin>>x;
        vect.push_back(x);
    }

    for(auto it:vect) {
        cout<< it << endl;
    }

    cout << "Front: " << vect.front() << endl;
    cout << "Back: "<< vect.back() << endl;
    cout << "at 2nd index at: "<< vect.at(2) << endl;

    int last_index = vect.size() - 1;

    vect[last_index]=4;

    cout << "Now Back: "<< vect.back() << endl;

    vect.pop_back();

    cout << "SIZE NOW: " << vect.size() << endl;



    /*
    Front: 1
    Back: 3
    2 at: 3
    Now Back: 4
    */
}