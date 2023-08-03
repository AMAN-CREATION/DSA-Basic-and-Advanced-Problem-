#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

int add(int a, int b)
{
    return (a % MOD + b % MOD) % MOD;
}

int mul(int a, int b)
{
    return ((a % MOD) * 1LL * (b % MOD)) % MOD;
}

int solveMemo(int n, int k, vector<int> &dp)
{
    if (n == 1)
        return k;
    if (n == 2)
        return add(k, mul(k, k - 1));

    if (dp[n] != -1)
        return dp[n];

    dp[n] = add(mul(solveMemo(n - 2, k, dp), k - 1), mul(solveMemo(n - 1, k, dp), k - 1));
    return dp[n];
}

int solveTabu(int n, int k)
{
    vector<int> dp(n + 1, 0);
    dp[1] = k;
    dp[2] = add(k, mul(k, k - 1));

    for (int i = 3; i <= n; i++)
    {
        dp[i] = add(mul(dp[i - 2], k - 1), mul(dp[i - 1], k - 1));
    }
    return dp[n];
}

int solveSpace(int n, int k)
{
    int prev2 = k;
    int prev1 = add(k, mul(k, k - 1));

    for (int i = 3; i <= n; i++)
    {
        int ans = add(mul(prev2, k - 1), mul(prev1, k - 1));
        prev2 = prev1;
        prev1 = ans;
    }
    return prev1;
}

int numberOfWays(int n, int k)
{
    // vector<int> dp(n + 1, -1);
    // return solveMemo(n, k, dp);

    // return solveTabu(n, k);

    return solveSpace(n, k);
}

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n = 3, k = 2;
    cout << numberOfWays(n, k) << endl;
}
