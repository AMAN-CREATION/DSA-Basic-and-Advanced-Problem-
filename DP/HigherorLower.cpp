// Guess Number Higher or Lower II - leetcode.com

#include <bits/stdc++.h>
using namespace std;

int solveMemo(int start, int end, vector<vector<int>> &dp)
{
    if (start >= end)
        return 0;

    if (dp[start][end] != -1)
        return dp[start][end];

    int maxi = INT_MAX;
    for (int i = start; i <= end; i++)
    {
        maxi = min(maxi, i + max(solveMemo(start, i - 1, dp), solveMemo(i + 1, end, dp)));
    }
    return dp[start][end] = maxi;
}

int solveTabu(int n)
{
    vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));

    for (int start = n; start >= 1; start--)
    {
        for (int end = start; end <= n; end++)
        {
            if (start == end)
                continue;
            else
            {
                int maxi = INT_MAX;
                for (int i = start; i <= end; i++)
                {
                    maxi = min(maxi, i + max(dp[start][i - 1], dp[i + 1][end]));
                }
                dp[start][end] = maxi;
            }
        }
    }
    return dp[1][n];
}

int getMoneyAmount(int n)
{
    // vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
    // return solveMemo(1, n, dp);

    return solveTabu(n);
}

int main()
{
    cout << getMoneyAmount(10) << endl;
}
