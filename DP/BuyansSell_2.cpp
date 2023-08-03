#include <bits/stdc++.h>
using namespace std;

int solveMemo(int index, int buy, vector<int> &prices, vector<vector<int>> &dp)
{
    if (index == prices.size())
        return 0;

    if (dp[index][buy] != -1)
        return dp[index][buy];

    int profit = 0;
    if (buy)
    {
        int buying = -prices[index] + solveMemo(index + 1, 0, prices, dp);
        int skip = 0 + solveMemo(index + 1, 1, prices, dp);
        profit = max(buying, skip);
    }
    else
    {
        int sell = prices[index] + solveMemo(index + 1, 1, prices, dp);
        int skip = 0 + solveMemo(index + 1, 0, prices, dp);
        profit = max(sell, skip);
    }
    return dp[index][buy] = profit;
}

int solveTabu(vector<int> &prices)
{
    int n = prices.size();
    vector<vector<int>> dp(n + 1, vector<int>(2, 0));

    for (int index = n - 1; index >= 0; index--)
    {
        for (int buy = 0; buy <= 1; buy++)
        {
            int profit = 0;
            if (buy)
            {
                int buying = -prices[index] + dp[index + 1][0];
                int skip = 0 + dp[index + 1][1];
                profit = max(buying, skip);
            }
            else
            {
                int sell = prices[index] + dp[index + 1][1];
                int skip = 0 + dp[index + 1][0];
                profit = max(sell, skip);
            }
            dp[index][buy] = profit;
        }
    }
    return dp[0][1];
}

int solveSpace(vector<int> &prices)
{
    int n = prices.size();

    vector<int> curr(2, 0);
    vector<int> next(2, 0);

    for (int index = n - 1; index >= 0; index--)
    {
        for (int buy = 0; buy <= 1; buy++)
        {
            int profit = 0;
            if (buy)
            {
                int buying = -prices[index] + next[0];
                int skip = 0 + next[1];
                profit = max(buying, skip);
            }
            else
            {
                int sell = prices[index] + next[1];
                int skip = 0 + next[0];
                profit = max(sell, skip);
            }
            curr[buy] = profit;
        }
        next = curr;
    }
    return next[1];
}

int maxProfit(vector<int> &prices)
{
    int n = prices.size();
    // vector<vector<int>> dp(n, vector<int>(2, -1));
    // return solveMemo(0, 1, prices, dp);

    // return solveTabu(prices);
    return solveSpace(prices);
}

int main()
{
    vector<int> prices = {7, 1, 5, 3, 6, 4};
    cout << "the maximum profit is : " << maxProfit(prices);
}
