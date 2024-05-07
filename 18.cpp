#include<bits/stdc++.h>
using namespace std;

void dijkstra(vector<vector<pair<int, int>>>& adj, int src, int n) {
    vector<int> dist(n, INT_MAX);
    dist[src] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, src});

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();
        for (auto edge : adj[u]) {
            int v = edge.first;
            int weight = edge.second;
            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
            }
        }
    }

    for (int i = 0; i < n; i++) {
        cout << "Distance from " << src << " to " << i << " is " << dist[i] << "\n";
    }
}

int main() {
    int n;
    cin >> n;
    vector<vector<pair<int, int>>> adj(n);

    // read the adjacency list
    for (int i = 0; i < n; i++) {
        int m;
        cin >> m;
        for (int j = 0; j < m; j++) {
            int v, weight;
            cin >> v >> weight;
            adj[i].push_back({v, weight});
        }
    }

    int src;
    cin >> src;

    dijkstra(adj, src, n);

    return 0;
}