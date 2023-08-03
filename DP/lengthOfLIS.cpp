#include <bits/stdc++.h>
using namespace std;

// tc and sc = o(n^2)
int solveMemo(vector<int> &nums, int curr, int prev, vector<vector<int>> &dp)
{
    int n = nums.size();
    if (curr == n)
        return 0;

    if (dp[curr][prev + 1] != -1)
        return dp[curr][prev + 1];

    int include = 0;
    if (prev == -1 || nums[curr] > nums[prev])
        include = 1 + solveMemo(nums, curr + 1, curr, dp);

    int exclude = 0 + solveMemo(nums, curr + 1, curr, dp);

    return dp[curr][prev + 1] = max(include, exclude);
}

// tc and sc = o(n^2)
int solveTabu(vector<int> &nums)
{
    int n = nums.size();
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

    for (int curr = n - 1; curr >= 0; curr--)
    {
        for (int prev = curr - 1; prev >= -1; prev--)
        {
            int include = 0;
            if (prev == -1 || nums[curr] > nums[prev])
                include = 1 + dp[curr + 1][curr + 1];

            int exclude = 0 + dp[curr + 1][prev + 1];

            dp[curr][prev + 1] = max(include, exclude);
        }
    }
    return dp[0][0];
}

int solveSpace(vector<int> &nums)
{
    int n = nums.size();

    vector<int> currRow(n + 1, 0);
    vector<int> nextRow(n + 1, 0);

    for (int curr = n - 1; curr >= 0; curr--)
    {
        for (int prev = curr - 1; prev >= -1; prev--)
        {
            int include = 0;
            if (prev == -1 || nums[curr] > nums[prev])
                include = 1 + nextRow[curr + 1];

            int exclude = 0 + nextRow[prev + 1];

            currRow[prev + 1] = max(include, exclude);
        }
        nextRow = currRow;
    }
    return nextRow[0];
}

int solveOptimal(vector<int> &nums)
{
    int n = nums.size();

    if (n == 0)
        return 0;

    vector<int> ans;
    ans.push_back(nums[0]);

    for (int i = 1; i < n; i++)
    {
        if (nums[i] > ans.back())
            ans.push_back(nums[i]);
        else
        {
            int index = lower_bound(ans.begin(), ans.end(), nums[i]) - ans.begin();
            ans[index] = nums[i];
        }
    }
    return ans.size();
}

int lengthOfLIS(vector<int> &nums)
{
    // int n = nums.size();
    // vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
    // return solveMemo(nums, 0, -1, dp);

    // return solveTabu(nums);

    // return solveSpace(nums);

    return solveOptimal(nums);
}

int main()
{
    vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18}; //4
    // vector<int> nums = {5, 8, 3, 7, 9, 1}; // 3
    cout << " length of the longest strictly increasing subsequence " << lengthOfLIS(nums);
}