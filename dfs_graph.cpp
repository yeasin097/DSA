#include<bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>>&graph,int levels[], int nodes, int root) {
    for(int i=0; i<nodes; i++) {
        levels[i]=-1;
    }

    levels[root]=0;
    stack<int>stk;
    stk.push(root);

    while(!stk.empty()) {
        int node = stk.top();
        stk.pop();

        for(int i=0; i<graph[node].size(); i++) {
            int adjacent = graph[node][i];

            if(levels[adjacent]==-1) {
                levels[adjacent]=levels[node]+1;
                stk.push(adjacent);
            }
            else if(levels[adjacent]!=-1 && levels[adjacent]>levels[node]+1) {
                levels[adjacent]=levels[node]+1;
                stk.push(adjacent);
            }
        }
    }
}


int main() {
    freopen("../input.txt", "r", stdin);

    int nodes,edges;
    cin>>nodes>>edges;

    vector<vector<int>>graph(nodes);

    for(int i=0; i<edges; i++) {
        int node, neighbour;
        cin>>node>>neighbour;
        graph[node].push_back(neighbour);
        graph[neighbour].push_back(node);
        
    }

    int levels[nodes];

    dfs(graph, levels, nodes, 7);

    for(int i=0; i<nodes; i++) {
        cout<< i << "th Node level is = "<<  levels[i] << endl;
    }
}