//
// Created by Manas Singh on 08-05-2024.
//
#include <vector>
#include <iostream>

using namespace std;

void heapify(vector<int> &arr, int index, int n) {
    int maxIndex = index;
    if (index * 2 + 1 < n && arr[maxIndex] < arr[index * 2 + 1])
        maxIndex = index * 2 + 1;
    if (index * 2 + 2 < n && arr[maxIndex] < arr[index * 2 + 2])
        maxIndex = index * 2 + 2;
    if (index != maxIndex) {
        swap(arr[index], arr[maxIndex]);
        heapify(arr, maxIndex, n);
    }
}

void buildHeap(vector<int> &arr) {
    int n = arr.size();
    for (int i = n / 2; i > -1; i--)
        heapify(arr, i, n);
}

void heapSort(vector<int> &arr) {
    buildHeap(arr);
    for (int i = arr.size() - 1; i > 0; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, 0, i);
    }
}

int main() {
    vector<int> arr = {4, 2, 1, 3, 5};
    heapSort(arr);
    for (int i = 0; i < 5; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}