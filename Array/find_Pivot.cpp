#include <bits/stdc++.h>
using namespace std;

int pivotIndex(vector<int> nums)
{
    int sum = 0;
    int leftSum = 0;
    for (int x : nums)
        sum += x;

    for (int i = 0; i < nums.size(); i++)
    {
        if (leftSum == sum - leftSum - nums[i])
            return i;

        leftSum += nums[i];
    }
    return -1;
}
int main()
{
    vector<int> v = {1, 7, 3, 6, 5, 6};

    cout << pivotIndex(v);
}