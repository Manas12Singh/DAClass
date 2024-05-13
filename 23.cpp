//
// Created by Manas Singh on 09-05-2024.
//
#include <map>
#include <vector>
#include <queue>
#include <string>
#include <iostream>

using namespace std;

struct TreeNode {
    char c;
    int count;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : c(0), count(0), left(nullptr), right(nullptr) {}

    TreeNode(char c, int count) : c(c), count(count), left(nullptr), right(nullptr) {}

    TreeNode(int count, TreeNode *left, TreeNode *right) : count(count), c(0), left(left), right(right) {}
};

class Compare {
public:
    bool operator()(TreeNode *a, TreeNode *b) {
        return a->count > b->count;
    }
};

void dfs(map<char, string> &res, TreeNode *root, string s, char c) {
    s.push_back(c);
    if (root->left && root->right) {
        dfs(res, root->left, s, '0');
        dfs(res, root->right, s, '1');
    } else {
        res[root->c] = s;
    }
}

map<char, string> huffmanCoding(const map<char, int> &m) {
    priority_queue<TreeNode *, vector<TreeNode *>, Compare> pq;
    for (pair<char, int> i: m)
        pq.emplace(new TreeNode(i.first, i.second));
    while (pq.size() != 1) {
        TreeNode *a = pq.top();
        pq.pop();
        TreeNode *b = pq.top();
        pq.pop();
        pq.emplace(new TreeNode(a->count + b->count, a, b));
    }
    map<char, string> res;
    dfs(res, pq.top(), "", 0);
    return res;
}


int main() {
    map<char, int> m;
    m['a'] = 25;
    m['b'] = 37;
    m['c'] = 38;
    m['d'] = 12;
    map<char, string> res = huffmanCoding(m);
    for (pair<char, string> i: res)
        cout << i.first << " " << i.second << endl;
}