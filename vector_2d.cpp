#include<bits/stdc++.h>
using namespace std;

int main() {
    int n=4;
    vector<vector<int>>vect_2d(n);

    
    for(int i=0; i<n; i++) {
        for(int j=0; j<=i; j++) {
            vect_2d[i].push_back(j);
        }
    }

    for(int i=0; i<n; i++) {
        for(int j=0; j<vect_2d[i].size(); j++) {
            cout << vect_2d[i][j] << " ";
        }
        cout<<endl;
    }
}