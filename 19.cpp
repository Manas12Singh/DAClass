//
// Created by Manas Singh on 09-05-2024.
//
#include <iostream>
#include <vector>

using namespace std;

vector<pair<int, int>> bellmanFord(int n, vector<vector<pair<int, int>>> &graph, int source) {
    vector<pair<int, int>> res(n, {-1, INT_MAX});
    res[source].second = 0;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n; j++) {
            if (res[j].second != INT_MAX) {
                for (auto &k: graph[j])
                    if (res[k.first].second > k.second + res[j].second) {
                        res[k.first].first = j;
                        res[k.first].second = k.second + res[j].second;
                    }
            }
        }
    }
    return res;
}

int main() {
    vector<vector<pair<int, int>>> graph = {{{1, 8}, {2, 9}},
                                            {{0, 8}, {2, 7}, {3, 3}, {5, 5}},
                                            {{0, 9}, {1, 7}, {5, 4}},
                                            {{1, 3}, {4, 1}, {5, 6}},
                                            {{3, 1}, {5, 2}},
                                            {{1, 5}, {2, 4}, {3, 6}, {4, 2}}};
    vector<pair<int, int>> res = bellmanFord(graph.size(), graph, 0);
    for (int i = 0; i < graph.size(); i++)
        cout << i << " " << res[i].second << endl;
    return 0;
}