#include <vector>

using namespace std;

void modifiedBubbleSort(vector<int> &arr) {
    int n = arr.size(), swaps;
    for (int i = 0; i < n - 1; i++) {
        swaps = 0;
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swaps++;
            }
        }
        if (swaps == 0)
            break;
    }
}