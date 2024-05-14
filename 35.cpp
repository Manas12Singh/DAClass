//topological sort using dfs
void util(vector<vector<int>> g, vector<bool> &v, int curr, stack<int> &s) {
    v[curr]=true;
    for (int i=0; i<g[curr].size(); i++ ) {
        if (!v[i]) util(g, v, g[curr][i], s);
    }
    s.push(curr);
}

void tsort(vector<vector<int>> g) {
    vector<bool> v(g.size(), false);
    stack<int> s;
    for (int i=0; i<g.size(); i++) {
        if (!v[i]) util(g, v, i, s);
    }
    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
}
