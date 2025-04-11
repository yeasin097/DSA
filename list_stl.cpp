#include<bits/stdc++.h>
using namespace std;

int main() {
    list<string>students;

    students.push_back("1904097");
    students.push_front("1904096");
    students.push_back("1904098");

    for(auto it:students) {
        cout << it << endl;
    }

    // cout << students[0] << endl; cant possible. list item can not acccess by index

    students.pop_back();
    students.pop_front();

    for(auto it:students) {
        cout << it << endl;
    }


}