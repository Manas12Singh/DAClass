#include <iostream>
#include <bits/stdc++.h>
using namespace std;

//bfs
void util(vector<vector<int>> g, vector<bool> &v) {
    queue<int> q;
    q.push(0);
    v[0]=true;
    while (!q.empty()) {
        int curr=q.front();
        cout << curr << " ";
        q.pop();
        for (auto it: g[curr]) {
            if (!v[it]) {
                q.push(it);
                v[it]=true;
            }
        }
    }
}
void bfs(vector<vector<int>> g) {
    vector<bool> v(g.size(), false);
    for (int i=0; i<g.size(); i++) {
        if (!v[i]) util(g, v);
    }
}