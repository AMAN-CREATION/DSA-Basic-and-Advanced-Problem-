#include <bits/stdc++.h>
using namespace std;

//! time complexity - o(n*amount);
//     Recursion or Memoization
int solveMemo(vector<int> &coins, int amount, vector<int> &dp)
{
    if (amount == 0)
        return 0;
    if (amount < 0)
        return INT_MAX;

    if (dp[amount] != -1)
        return dp[amount];

    int mini = INT_MAX;

    for (int i = 0; i < coins.size(); i++)
    {
        int ans = solveMemo(coins, amount - coins[i], dp);
        if (ans != INT_MAX)
            mini = min(mini, 1 + ans);
    }
    dp[amount] = mini;
    return dp[amount];
}

// tabulation
int solveTabu(vector<int> &coins, int amount)
{
    vector<int> dp(amount + 1, INT_MAX);
    dp[0] = 0;

    for (int i = 1; i <= amount; i++)
    {
        for (int j = 0; j < coins.size(); j++)
        {
            if (i - coins[j] >= 0 && dp[i - coins[j]] != INT_MAX)
                dp[i] = min(dp[i], 1 + dp[i - coins[j]]);
        }
    }
    if (dp[amount] == INT_MAX)
        return -1;
    return dp[amount];
}

int coinChange(vector<int> &coins, int amount)
{
    // vector<int> dp(amount + 1, -1);
    // int ans = solveMemo(coins, amount, dp);

    // if (ans == INT_MAX)
    //     return -1;
    // return ans;

    // return solveTabu(coins, amount);
}

int main()
{
    vector<int> coins = {1, 2, 5};
    int amount = 11;

    cout << coinChange(coins, amount);
}

/*
Input: coins = [1,2,5], amount = 11
Output: 3
Explanation: 11 = 5 + 5 + 1
*/