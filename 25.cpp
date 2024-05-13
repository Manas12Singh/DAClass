//
// Created by Manas Singh on 13-05-2024.
//

#include <vector>
#include <iostream>

using namespace std;

int zeroOneKnapSack(vector<pair<int, int>> items, int bagSize) {
    int n = items.size();
    vector<int> dp(bagSize + 1, 0);
    for (int i = 1; i <= n; i++)
        for (int j = bagSize; j >= 0; j--) {
            if (items[i - 1].second <= j) {
                dp[j] = max(dp[j], items[i - 1].first + dp[j - items[i - 1].second]);
            }
        }
    return dp[bagSize];
}

int main() {
    vector<pair<int, int>> profit = {{60,  10},
                                     {100, 20},
                                     {120, 30}};
    cout << zeroOneKnapSack(profit, 50);
    return 0;
}