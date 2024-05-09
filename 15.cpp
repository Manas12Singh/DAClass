//
// Created by Manas Singh on 08-05-2024.
//
#include <vector>
#include <iostream>

using namespace std;

void dfs(vector<vector<int>> &adjacencyList, vector<bool> &visited, int i) {
    if (visited[i])
        return;
    visited[i] = true;
    cout << i << " ";
    for (int &j: adjacencyList[i])
        dfs(adjacencyList, visited, j);
}

int main() {
    vector<vector<int>> adjacencyList = {{1, 2},
                                         {2, 3},
                                         {0, 3},
                                         {1, 2}};
    vector<bool> visited(4);
    dfs(adjacencyList, visited, 1);
}