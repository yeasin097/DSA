#include<bits/stdc++.h>
using namespace std;

void dijkstra(vector<vector<int>> &graph, vector<vector<int>> &cost, int source) {
    queue<int> q;
    q.push(source);

    vector<int> dist(graph.size(), INT_MAX);
    dist[source]=0;

    while (!q.empty()){
        int u=q.front();
        q.pop();

        for(int i=0; i<graph[u].size(); i++){
            int v=graph[u][i];
            int w=cost[u][i];

            if(dist[u]+w < dist[v] && dist[u]!=INT_MAX){
                dist[v]=dist[u]+w;
                q.push(v);
            }
        }

    }

    cout<<"Distance from source node " << source << " to all other nodes: " << endl;

    for(int i=0; i<dist.size(); i++) {
        if(dist[i]==INT_MAX) {
            cout << "INF" << endl;
        }
        else {
            cout << dist[i] << endl;
        }
    }
}


int main() {
    int edges, nodes;
    cin >> nodes >> edges;

    vector<vector<int>> graph(nodes+1);
    vector<vector<int>> cost(nodes+1);


    
    for(int i=0; i<edges; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back(v);
        cost[u].push_back(w);
    }

    dijkstra(graph, cost, 1);
}



