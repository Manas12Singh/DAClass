//
// Created by Manas Singh on 13-05-2024.
//
//
// Created by Manas Singh on 08-05-2024.
//
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int prims(int n, vector<vector<pair<int, int>>> &graph, int start) {
    vector<int> weight(n, INT_MAX);
    vector<bool> inMST(n);
    int res = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    pq.emplace(0, start);
    weight[start] = 0;
    while (!pq.empty()) {
        auto u = pq.top().second;
        pq.pop();
        if (inMST[u])
            continue;
        res += weight[u];
        inMST[u] = true;
        for (auto &adj: graph[u]) {
            if (!inMST[adj.first] && adj.second < weight[adj.first]) {
                weight[adj.first] = adj.second;
                pq.emplace(adj.second, adj.first);
            }
        }
    }
    return res;
}

/*
 * Adjacency List
 * pair <destination,weight>
 */

int main() {
    int matrix[7][7] = {
            {0, 0, 7, 5,  0,  0,  0},
            {0, 0, 8, 5,  0,  0,  0},
            {7, 8, 0, 9,  7,  0,  0},
            {5, 5, 9, 0,  15, 6,  0},
            {0, 0, 7, 15, 0,  8,  9},
            {0, 0, 0, 6,  8,  0,  11},
            {0, 0, 0, 0,  9,  11, 0}
    };
    vector<vector<pair<int, int>>> adjList(7);
    for (int i = 0; i < 7; ++i) {
        for (int j = 0; j < 7; ++j) {
            if (matrix[i][j] != 0) {
                adjList[i].emplace_back(j, matrix[i][j]);
                if (i != j) {
                    adjList[j].emplace_back(i, matrix[i][j]);
                }
            }
        }
    }
    cout << prims(adjList.size(), adjList, 0);
}
