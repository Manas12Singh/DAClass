//
// Created by Manas Singh on 08-05-2024.
//
#include <vector>

using namespace std;

int fibIterative(int n) {
    int a = 0, b = 1;
    for (int i = 0; i < n; i++) {
        b = b + a;
        a = b - a;
    }
    return a;
}


int fibRecursive(int n) {
    if (n < 2)
        return n;
    return fibRecursive(n - 1) + fibRecursive(n - 2);
}

int fibRecursiveWithMemo(vector<int> &arr, int n) {
    if (arr[n] == -1)
        arr[n] = fibRecursiveWithMemo(arr, n - 1) + fibRecursiveWithMemo(arr, n - 2);
    return arr[n];
}

int fibRecursiveLogN(vector<int>& arr,int n){
    if(n<2)
        return n;
    if(n&1)
    {
        n>>=1;
    }
}