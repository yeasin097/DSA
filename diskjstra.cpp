#include <bits/stdc++.h>
using namespace std;

#define INF 1e6

void dijkstra(int cost[][100], int root, int nodes) {
    bool visited[nodes];
    int dist[nodes];

    for (int i = 0; i < nodes; i++) {
        dist[i] = INF;
        visited[i] = false;
    }

    dist[root] = 0;

    for (int count = 0; count < nodes - 1; count++) {
        int u = -1;

        // Find the unvisited node with the smallest distance
        for (int i = 0; i < nodes; i++) {
            if (!visited[i] && (u == -1 || dist[i] < dist[u])) {
                u = i;
            }
        }

        if (dist[u] == INF) break; // Remaining nodes are unreachable

        visited[u] = true;

        // Relax adjacent nodes
        for (int v = 0; v < nodes; v++) {
            if (!visited[v] && cost[u][v] != INF && dist[u] + cost[u][v] < dist[v]) {
                dist[v] = dist[u] + cost[u][v];
            }
        }
    }

    // Print distances
    for (int i = 0; i < nodes; i++) {
        cout << "Distance from " << root << " to " << i << " is: ";
        if (dist[i] == INF)
            cout << "INF\n";
        else
            cout << dist[i] << "\n";
    }
}

int main() {
    freopen("../input.txt", "r", stdin);

    int nodes, edges;
    cin >> nodes >> edges;

    int cost[100][100];

    for (int i = 0; i < nodes; i++) {
        for (int j = 0; j < nodes; j++) {
            cost[i][j] = INF;
        }
        cost[i][i] = 0;
    }

    for (int i = 0; i < edges; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        cost[u][v] = w;
    }

    dijkstra(cost, 0, nodes);
}
