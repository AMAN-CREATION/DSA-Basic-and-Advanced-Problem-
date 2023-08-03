#include <bits/stdc++.h>
using namespace std;

bool solveMemo(int index, vector<int> &nums, int n, int target, vector<vector<int>> &dp)
{
    if (index >= n)
        return 0;
    if (target < 0)
        return 0;
    if (target == 0)
        return 1;

    if (dp[index][target] != -1)
        return dp[index][target];

    bool incl = solveMemo(index + 1, nums, n, target - nums[index], dp);
    bool excl = solveMemo(index + 1, nums, n, target - 0, dp);

    return dp[index][target] = incl || excl;
}

int solveTabu(int n, vector<int> &nums, int total)
{
    vector<vector<int>> dp(n + 1, vector<int>(total + 1, 0));
    for (int i = 0; i <= n; i++)
    {
        dp[i][0] = 1;
    }

    for (int index = n - 1; index >= 0; index--)
    {
        for (int target = 0; target <= total / 2; target++)
        {
            bool incl = 0;
            if (target - nums[index] >= 0)
                incl = dp[index + 1][target - nums[index]];

            bool excl = dp[index + 1][target - 0];

            dp[index][target] = incl || excl;
        }
    }
    return dp[0][total / 2];
}

int solveSpace(int n, vector<int> &nums, int total)
{
    vector<int> curr(total / 2 + 1, 0);
    vector<int> next(total / 2 + 1, 0);

    curr[0] = 1;
    next[0] = 1;

    for (int index = n - 1; index >= 0; index--)
    {
        for (int target = 0; target <= total / 2; target++)
        {
            bool incl = 0;
            if (target - nums[index] >= 0)
                incl = next[target - nums[index]];

            bool excl = next[target - 0];
            curr[target] = incl or excl;
        }
        next = curr;
    }
    return next[total / 2];
}
bool canPartition(vector<int> &nums)
{
    int n = nums.size();

    int total = 0;
    for (int i = 0; i < n; i++)
    {
        total += nums[i];
    }

    if (total & 1)
        return 0;

    int target = total / 2;

    // vector<vector<int>> dp(n, vector<int>(target + 1, -1));
    // return solveMemo(0, nums, n, target, dp);

    // return solveTabu(n, nums, total);
    return solveSpace(n, nums, total);
}

int main()
{
    // vector<int> nums = {1, 5, 11, 5}; // true
    vector<int> nums = {1, 2, 3, 5}; // false

    if (canPartition(nums))
        cout << "true";
    else
        cout << "false";
}