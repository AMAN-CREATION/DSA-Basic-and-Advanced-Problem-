#include <bits/stdc++.h>
using namespace std;

int solveMemo(int index, int opNo, int k, vector<int> &prices, vector<vector<int>> &dp)
{
    if (index == prices.size())
        return 0;

    if (opNo == 2 * k)
        return 0;

    if (dp[index][opNo] != -1)
        return dp[index][opNo];

    int profit;
    if (opNo % 2 == 0)
    {
        int buying = -prices[index] + solveMemo(index + 1, opNo + 1, k, prices, dp);
        int skip = 0 + solveMemo(index + 1, opNo, k, prices, dp);
        profit = max(buying, skip);
    }
    else
    {
        int sell = prices[index] + solveMemo(index + 1, opNo + 1, k, prices, dp);
        int skip = 0 + solveMemo(index + 1, opNo, k, prices, dp);
        profit = max(sell, skip);
    }
    return dp[index][opNo] = profit;
}

int solveTabu(int k, vector<int> &prices)
{
    int n = prices.size();

    vector<vector<int>> dp(n + 1, vector<int>(2 * k + 1, 0));

    for (int index = n - 1; index >= 0; index--)
    {
        for (int opNo = 0; opNo < 2 * k; opNo++)
        {
            int profit = 0;
            if (opNo % 2 == 0)
            {
                int buying = -prices[index] + dp[index + 1][opNo + 1];
                int skip = 0 + dp[index + 1][opNo];
                profit = max(buying, skip);
            }
            else
            {
                int sell = prices[index] + dp[index + 1][opNo + 1];
                int skip = 0 + dp[index + 1][opNo];
                profit = max(sell, skip);
            }
            dp[index][opNo] = profit;
        }
    }
    return dp[0][0];
}

int solveOptimal(int k, vector<int> &prices)
{
    int n = prices.size();

    vector<int> curr(2 * k + 1, 0);
    vector<int> next(2 * k + 1, 0);

    for (int index = n - 1; index >= 0; index--)
    {
        for (int opNo = 0; opNo < 2 * k; opNo++)
        {
            int profit = 0;
            if (opNo % 2 == 0)
            {
                int buying = -prices[index] + next[opNo + 1];
                int skip = 0 + next[opNo];
                profit = max(buying, skip);
            }
            else
            {
                int sell = prices[index] + next[opNo + 1];
                int skip = 0 + next[opNo];
                profit = max(sell, skip);
            }
            curr[opNo] = profit;
        }
        next = curr;
    }
    return next[0];
}

int maxProfit(int k, vector<int> &prices)
{
    // int n = prices.size();
    // vector<vector<int>> dp(n, vector<int>(2 * k, -1));
    // return solveMemo(0, 0, k, prices, dp);

    // return solveTabu(k, prices);
    return solveOptimal(k, prices);
}

int main()
{
    // vector<int> prices = {3, 2, 6, 5, 0, 3};
    vector<int> prices = {2, 4, 1};
    int k = 2;
    cout << "the maximum profit is : " << maxProfit(k, prices);
}
