//
// Created by Manas Singh on 30-05-2024.
//
#include <vector>
#include <iostream>
#include <queue>

using namespace std;

vector<vector<int>> prims(int n, vector<vector<int>> &matrix, int source) {
    vector<vector<int>> MST(n, vector<int>(n, 0));
    vector<bool> inMST(n, false);
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> pq;
    pq.push({0, {source, source}});
    while (!pq.empty()) {
        int prevNode = pq.top().second.first;
        int curNode = pq.top().second.second;
        int curWeight = pq.top().first;
        pq.pop();
        if (inMST[curNode])
            continue;
        MST[prevNode][curNode] = curWeight;
        MST[curNode][prevNode] = curWeight;
        inMST[curNode] = true;
        for (int nextNode = 0; nextNode < n; nextNode++)
            if (!inMST[nextNode] && matrix[curNode][nextNode])
                pq.push({matrix[curNode][nextNode], {curNode, nextNode}});
    }
    return MST;
}

int main() {
    int n;
    cout << "Enter number of nodes: ";
    cin >> n;
    vector<vector<int>> matrix(n, vector<int>(n));
    cout << "Enter adjacency matrix: " << endl;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> matrix[i][j];
    vector<vector<int>> MST = prims(n, matrix, 0);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cout << MST[i][j] << " ";
        cout << endl;
    }
    cout << endl;
    return 0;
}