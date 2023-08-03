#include <bits/stdc++.h>
using namespace std;

int solveMemo(vector<int> &nums1, vector<int> &nums2, int index, bool swapped, vector<vector<int>> &dp)
{
    if (index == nums1.size())
        return 0;

    if (dp[index][swapped] != -1)
        return dp[index][swapped];

    int ans = INT_MAX;

    int prev1 = nums1[index - 1];
    int prev2 = nums2[index - 1];

    if (swapped)
        swap(prev1, prev2);

    // noswap
    if (nums1[index] > prev1 && nums2[index] > prev2)
        ans = solveMemo(nums1, nums2, index + 1, 0, dp);

    // swap
    if (nums1[index] > prev2 && nums2[index] > prev1)
        ans = min(ans, 1 + solveMemo(nums1, nums2, index + 1, 1, dp));

    return dp[index][swapped] = ans;
}

int solveTabu(vector<int> &nums1, vector<int> &nums2)
{
    int n = nums1.size();
    vector<vector<int>> dp(n + 1, vector<int>(2, 0));

    for (int index = n - 1; index >= 1; index--)
    {
        for (int swapped = 1; swapped >= 0; swapped--)
        {
            int ans = INT_MAX;

            int prev1 = nums1[index - 1];
            int prev2 = nums2[index - 1];

            if (swapped)
                swap(prev1, prev2);

            // noswap
            if (nums1[index] > prev1 && nums2[index] > prev2)
                ans = dp[index + 1][0];

            // swap
            if (nums1[index] > prev2 && nums2[index] > prev1)
                ans = min(ans, 1 + dp[index + 1][1]);

            dp[index][swapped] = ans;
        }
    }
    return dp[1][0];
}

int solveSpace(vector<int> &nums1, vector<int> &nums2)
{
    int n = nums1.size();

    int swap = 0;
    int noswap = 0;
    int currSwap = 0;
    int currNoSwap = 0;

    for (int index = n - 1; index >= 1; index--)
    {
        for (int swapped = 1; swapped >= 0; swapped--)
        {
            int ans = INT_MAX;

            int prev1 = nums1[index - 1];
            int prev2 = nums2[index - 1];

            if (swapped)
            {
                int temp = prev1;
                prev1 = prev2;
                prev2 = temp;
            }

            // noswap
            if (nums1[index] > prev1 && nums2[index] > prev2)
                ans = noswap;

            // swap
            if (nums1[index] > prev2 && nums2[index] > prev1)
                ans = min(ans, 1 + swap);

            if (swapped)
                currSwap = ans;
            else
                currNoSwap = ans;
        }
        swap = currSwap;
        noswap = currNoSwap;
    }
    return min(swap, noswap);
}

int minSwap(vector<int> &nums1, vector<int> &nums2)
{

    nums1.insert(nums1.begin(), -1);
    nums2.insert(nums2.begin(), -1);

    bool swapped = 0;

    int n = nums1.size();
    //     vector<vector<int>> dp(n, vector<int>(2, -1));
    //     return solveMemo(nums1, nums2, 1, swapped, dp);

    // return solveTabu(nums1, nums2);
    return solveSpace(nums1, nums2);
}

int main()
{
    vector<int> nums1 = {1, 3, 5, 4};
    vector<int> nums2 = {1, 2, 3, 7};

    cout << "the minimum number of strictly increasing is : " << minSwap(nums1, nums2);
}
