#include <bits/stdc++.h>
using namespace std;

int longestArithSeqLength(vector<int> &nums)
{
    int n = nums.size();

    if (n <= 2)
        return n;

    int ans = 0;

    unordered_map<int, int> dp[n + 1];

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            int diff = nums[i] - nums[j];

            int cnt = 1;

            if (dp[j].count(diff))
                cnt = dp[j][diff];

            dp[i][diff] = 1 + cnt;
            ans = max(ans, dp[i][diff]);
        }
    }
    return ans;
}

int main()
{
    // vector<int> nums = {3, 6, 9, 12};
    vector<int> nums = {9, 4, 7, 2, 10};

    cout << "the length of the longest arithmetic subsequence is " << longestArithSeqLength(nums);
}