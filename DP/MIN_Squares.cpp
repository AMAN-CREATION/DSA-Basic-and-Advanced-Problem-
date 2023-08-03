#include <bits/stdc++.h>
using namespace std;

int solveMemo(int n, vector<int> &dp)
{
    if (n == 0)
        return 0;

    if (dp[n] != -1)
        return dp[n];

    int ans = n;
    for (int i = 1; i * i <= n; i++)
    {
        int temp = i * i;
        ans = min(ans, 1 + solveMemo(n - temp, dp));
    }
    return dp[n] = ans;
}

int solveTabu(int n)
{
    vector<int> dp(n + 1, INT_MAX);
    dp[0] = 0;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j * j <= n; j++)
        {
            int temp = j * j;
            if (i - temp >= 0)
                dp[i] = min(dp[i], 1 + dp[i - temp]);
        }
    }
    return dp[n];
}

int numSquares(int n)
{
    vector<int> dp(n + 1, -1);
    return solveMemo(n, dp);
}

int main()
{
    int n = 12;
    cout << numSquares(n);
}

/*
Input: n = 12
Output: 3
Explanation: 12 = 4 + 4 + 4.
*/