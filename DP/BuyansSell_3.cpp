#include <bits/stdc++.h>
using namespace std;

int solveMemo(int index, int buy, vector<int> &prices, int limit, vector<vector<vector<int>>> &dp)
{
    int n = prices.size();
    if (index == n)
        return 0;

    if (limit == 0)
        return 0;

    if (dp[index][buy][limit] != -1)
        return dp[index][buy][limit];

    int profit = 0;
    if (buy)
    {
        int buying = -prices[index] + solveMemo(index + 1, 0, prices, limit, dp);
        int skip = 0 + solveMemo(index + 1, 1, prices, limit, dp);
        profit = max(buying, skip);
    }
    else
    {
        int sell = prices[index] + solveMemo(index + 1, 1, prices, limit - 1, dp);
        int skip = 0 + solveMemo(index + 1, 0, prices, limit, dp);
        profit = max(sell, skip);
    }
    return dp[index][buy][limit] = profit;
}

int solveTabu(vector<int> &prices)
{
    int n = prices.size();
    vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(3, 0)));

    for (int index = n - 1; index >= 0; index--)
    {
        for (int buy = 0; buy <= 1; buy++)
        {
            for (int limit = 1; limit <= 2; limit++)
            {
                int profit = 0;
                if (buy)
                {
                    int buying = -prices[index] + dp[index + 1][0][limit];
                    int skip = 0 + dp[index + 1][1][limit];
                    profit = max(buying, skip);
                }
                else
                {
                    int sell = prices[index] + dp[index + 1][1][limit - 1];
                    int skip = 0 + dp[index + 1][0][limit];
                    profit = max(sell, skip);
                }
                dp[index][buy][limit] = profit;
            }
        }
    }
    return dp[0][1][2];
}
int solveOptimal(vector<int> &prices)
{
    int n = prices.size();

    vector<vector<int>> curr(2, vector<int>(3, 0));
    vector<vector<int>> next(2, vector<int>(3, 0));

    for (int index = n - 1; index >= 0; index--)
    {
        for (int buy = 0; buy <= 1; buy++)
        {
            for (int limit = 1; limit <= 2; limit++)
            {
                int profit = 0;
                if (buy)
                {
                    int buying = -prices[index] + next[0][limit];
                    int skip = 0 + next[1][limit];
                    profit = max(buying, skip);
                }
                else
                {
                    int sell = prices[index] + next[1][limit - 1];
                    int skip = 0 + next[0][limit];
                    profit = max(sell, skip);
                }
                curr[buy][limit] = profit;
            }
        }
        next = curr;
    }
    return next[1][2];
}

int maxProfit(vector<int> &prices)
{
    // int n = prices.size();
    // vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(3, -1)));
    // return solveMemo(0, 1, prices, 2, dp);

    return solveTabu(prices);
    // return solveOptimal(prices);
}

int main()
{
    // vector<int> prices = {3, 3, 5, 0, 0, 3, 1, 4};
    vector<int> prices = {1, 2, 3, 4, 5};
    // vector<int> prices = {7, 6, 4, 3, 1};
    cout << "the maximum profit is : " << maxProfit(prices);
}
