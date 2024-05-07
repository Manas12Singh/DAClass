//
// Created by Manas Singh on 07-05-2024.
//
#include <iostream>
#include <vector>

using namespace std;

void insertionSort(vector<int> &nums) {
    int n = nums.size();
    for (int i = 0; i < n; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++)
            if (nums[i] < nums[minIndex])
                minIndex = i;
        if (i != minIndex) {
            int temp = nums[i];
            nums[i] = nums[minIndex];
            nums[minIndex] = temp;
        }
    }
}