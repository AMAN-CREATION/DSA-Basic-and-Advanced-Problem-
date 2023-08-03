#include <bits/stdc++.h>
using namespace std;

vector<int> runningSum(vector<int> nums)
{
    vector<int> ans(nums.size());
    ans[0] = nums[0];
    for (int i = 1; i < nums.size(); i++)
    {
        ans[i] = ans[i - 1] + nums[i];
    }
    return ans;
}

int main()
{
    vector<int> v = {1, 1, 1, 1, 1};
    vector<int> ans = runningSum(v);
    for (int i : ans)
    {
        cout << i << " ";
    }
}