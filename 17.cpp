//
// Created by Manas Singh on 08-05-2024.
//
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

vector<vector<pair<int, int>>> prims(int n, vector<vector<pair<int, int>>> &graph, int start) {
    vector<int> parent(n), weight(n, INT_MAX);
    vector<bool> inMST(n);
    vector<vector<pair<int, int>>> res(n);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    pq.emplace(0, start);
    parent[start] = -1;
    weight[start] = 0;
    while (!pq.empty()) {
        auto u = pq.top().second;
        pq.pop();
        if (inMST[u])
            continue;
        inMST[u] = true;
        for (auto &adj: graph[u]) {
            if (!inMST[adj.first] && adj.second < weight[adj.first]) {
                weight[adj.first] = adj.second;
                pq.emplace(adj.second, adj.first);
                parent[adj.first] = u;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        if (i == start)
            continue;
        res[i].emplace_back(parent[i], weight[i]);
        res[parent[i]].emplace_back(i, weight[i]);
    }
    return res;
}

/*
 * Adjacency List
 * pair <destination,weight>
 */

int main() {
    vector<vector<pair<int, int>>> graph = {{{1, 1}, {2, 1}},
                                            {{0, 1}, {2, 1}},
                                            {{0, 1}, {1, 1}}};
    vector<vector<pair<int, int>>> res = prims(graph.size(), graph, 0);
    for (int i = 0; i < res.size(); i++)
        for (auto &j: res[i])
            cout << i << " to " << j.first << " length " << j.second << endl;
}
