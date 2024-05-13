//
// Created by Manas Singh on 13-05-2024.
//
#include <vector>
#include <climits>
#include <iostream>

using namespace std;

int matrixChainMultiplication(vector<int> &arr) {
    int n = arr.size();
    vector<vector<int>> dp(n, vector<int>(n, 0));
    for (int l = 2; l < n; l++) {
        for (int i = 1; i < n - l + 1; i++) {
            int j = i + l - 1;
            dp[i][j] = INT_MAX;
            for (int k = i; k < j; k++) {
                int q = dp[i][k] + dp[k + 1][j] + arr[i - 1] * arr[k] * arr[j];
                if (q < dp[i][j]) {
                    dp[i][j] = q;
                }
            }
        }
    }
    return dp[1][n - 1];
}

int main() {
    vector<int> matrixDimension = {1, 2, 3, 4};
    cout << matrixChainMultiplication(matrixDimension);
}