#include <vector>
using namespace std;
//iterative binary search
int binSearchIter(vector<int>& arr, int target) {
    int left = 0;
    int right = arr.size() - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target) return mid;
        else if (arr[mid] < target) left = mid + 1;
        else right = mid - 1;
    }
    return -1;  
}

//recursive binary search
int binSearchRec(vector<int>& arr, int target, int left, int right) {
    if (right >= left) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target) return mid;
        if (arr[mid] > target) return binSearchRec(arr, target, left, mid - 1);
        return binSearchRec(arr, target, mid + 1, right);
    }
    return -1;  
}