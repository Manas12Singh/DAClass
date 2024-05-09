//
// Created by Manas Singh on 09-05-2024.
//
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int activitSelection(vector<pair<int, int>> jobs) {
    int n = jobs.size();
    if (n == 0)
        return 0;
    sort(jobs.begin(), jobs.end());
    int lastStart = jobs[n - 1].first, res = 1;
    for (int i = n - 2; i > -1; i--) {
        if (jobs[i].second <= lastStart)
            res++, lastStart = jobs[i].first;
    }
    return res;
}

int main() {
    vector<pair<int, int>> jobs = {{1, 4},
                                   {2, 5},
                                   {3, 6}};
    cout << activitSelection(jobs) << endl;
}