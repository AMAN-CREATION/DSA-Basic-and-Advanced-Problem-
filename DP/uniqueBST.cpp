#include <bits/stdc++.h>
using namespace std;

int solveMemo(int n, vector<int> &dp)
{
    if (n <= 1)
        return 1;

    if (dp[n] != -1)
        return dp[n];

    int ans = 0;

    // i as root node
    for (int i = 1; i <= n; i++)
    {
        ans += solveMemo(i - 1, dp) * solveMemo(n - i, dp);
    }
    return dp[n] = ans;
}

int solveTabu(int n)
{
    vector<int> dp(n + 1, 0);
    dp[0] = dp[1] = 1;

    // i -> number of node
    for (int i = 2; i <= n; i++)
    {
        // j-> root node
        for (int j = 1; j <= i; j++)
        {
            dp[i] += dp[j - 1] * dp[i - j];
        }
    }
    return dp[n];
}

int numsTree(int n)
{
    // vector<int> dp(n + 1, -1);
    // return solveMemo(n, dp);

    return solveTabu(n);
}

int main()
{
    cout << "the number of structurally unique BST is " << numsTree(3);
}