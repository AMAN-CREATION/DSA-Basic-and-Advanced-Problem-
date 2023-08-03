#include <bits/stdc++.h>
using namespace std;

int mod = 1e9 + 7;

int solveMemo(int dice, int face, int target, vector<vector<int>> &dp)
{
    if (target < 0)
        return 0;
    if (dice == 0 && target != 0)
        return 0;
    if (dice != 0 && target == 0)
        return 0;
    if (dice == 0 && target == 0)
        return 1;

    if (dp[dice][target] != -1)
        return dp[dice][target];

    long long int ans = 0;
    for (int i = 1; i <= face; i++)
    {
        if (i > target)
            break;
        ans += solveMemo(dice - 1, face, target - i, dp);
    }
    return dp[dice][target] = ans % mod;
}

int solveTabu(int d, int f, int t)
{
    vector<vector<int>> dp(d + 1, vector<int>(t + 1, 0));
    dp[0][0] = 1;

    for (int dice = 1; dice <= d; dice++)
    {
        for (int target = 1; target <= t; target++)
        {
            long long int ans = 0;

            for (int faces = 1; faces <= f; faces++)
            {
                if (faces > target)
                    break;
                ans += dp[dice - 1][target - faces];
            }
            dp[dice][target] = ans % mod;
        }
    }
    return dp[d][t];
}

int solveSpace(int d, int f, int t)
{
    vector<int> curr(t + 1, 0);
    vector<int> prev(t + 1, 0);
    prev[0] = 1;

    for (int dice = 1; dice <= d; dice++)
    {
        for (int target = 1; target <= t; target++)
        {
            long long ans = 0;
            for (int faces = 1; faces <= f; faces++)
            {
                if (target - faces >= 0)
                    ans = (ans + prev[target - faces]) % mod;
            }
            curr[target] = ans;
        }
        prev = curr;
    }
    return prev[t];
}

// n dice, and each die has k faces numbered from 1 to k.
int numRollsToTarget(int n, int k, int target)
{
    // vector<vector<int>> dp(n + 1, vector<int>(target + 1, -1));
    // return solveMemo(n, k, target, dp);

    // return solveTabu(n, k, target);
    return solveSpace(n, k, target);
}

int main()
{
    cout << numRollsToTarget(2, 6, 7);
}