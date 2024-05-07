#include<bits/stdc++.h>
using namespace std;

struct Edge {
    int u, v, weight;
    bool operator<(Edge const& other) {
        return weight < other.weight;
    }
};

vector<int> tree_id;
int cost = 0;
vector<Edge> result;

void kruskal(vector<Edge>& edges, int n) {
    sort(edges.begin(), edges.end());
    for (Edge e : edges) {
        if (tree_id[e.u] != tree_id[e.v]) {
            cost += e.weight;
            result.push_back(e);
            int old_id = tree_id[e.u], new_id = tree_id[e.v];
            for (int i = 0; i < n; i++) {
                if (tree_id[i] == old_id) tree_id[i] = new_id;
            }
        }
    }
}

int main() {
    int n;
    cin >> n;
    vector<vector<pair<int, int>>> adj_list(n);
    vector<Edge> edges;

    // read the adjacency list
    for (int i = 0; i < n; i++) {
        int m;
        cin >> m;
        for (int j = 0; j < m; j++) {
            int v, weight;
            cin >> v >> weight;
            adj_list[i].push_back({v, weight});
            if (i < v) {
                edges.push_back({i, v, weight});
            }
        }
    }

    tree_id.resize(n);
    for (int i = 0; i < n; i++) tree_id[i] = i;

    kruskal(edges, n);

    cout << "Cost: " << cost << "\n";
    for (Edge e : result) {
        cout << e.u << " " << e.v << " " << e.weight << "\n";
    }
    return 0;
}
