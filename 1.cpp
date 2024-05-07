#include <iostream>
#include <vector>

using namespace std;

int linearSearch(vector<int> &nums, int k)
{
    int n = nums.size();
    for (int i = 0; i < n; i++)
        if (nums[i] == k)
            return i;
    return -1;
}

int main()
{
    int n;
    vector<int> nums;
    return 0;
}
