//! Maximum sum of non-adjacent elements or House Robber

#include <bits/stdc++.h>
using namespace std;

// ! time and space complexity of memo and tabu is o(n);

// Memoization
int solveMemo(vector<int> &nums, int n, vector<int> &dp)
{
    if (n < 0)
        return 0;
    if (n == 0)
        return nums[0];

    if (dp[n] != -1)
        return dp[n];

    int incl = solveMemo(nums, n - 2, dp) + nums[n];
    int excl = solveMemo(nums, n - 1, dp) + 0;

    dp[n] = max(incl, excl);
    return dp[n];
}

// Tabulation
int solveTabu(vector<int> &nums)
{
    int n = nums.size();
    vector<int> dp(n, 0);
    dp[0] = nums[0];
    for (int i = 1; i < n; i++)
    {
        int pick = nums[i];
        if (i > 1)
            pick += dp[i - 2];
        int notPick = 0 + dp[i - 1];
        dp[i] = max(pick, notPick);
    }
    return dp[n - 1];
}

// space optimization

int solveSpace(vector<int> &nums)
{
    int n = nums.size();
    int prev2 = 0;
    int prev1 = nums[0];

    for (int i = 1; i < n; i++)
    {
        int incl = prev2 + nums[i];
        int excl = prev1 + 0;

        int ans = max(incl, excl);
        prev2 = prev1;
        prev1 = ans;
    }
    return prev1;
}

int rob(vector<int> &nums)
{
    // int n=nums.size();
    // vector<int>dp(n,-1);
    // return solveMemo(nums,n-1,dp);

    // return solveTabu(nums);

    // return solveSpace(nums);

    int n = nums.size();

    if (n == 1)
        return nums[0];

    vector<int> first, second;
    for (int i = 0; i < n; i++)
    {
        if (i != n)
            first.push_back(nums[i]);
        if (i != 0)
            second.push_back(nums[i]);
    }
    return max(solveSpace(first), solveSpace(second));
}

int main()
{
    vector<int> nums = {2, 7, 9, 3, 1};
    cout << "Max sum is : " << rob(nums);
}