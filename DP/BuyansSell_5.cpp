#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> &prices, int fee)
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
                int sell = prices[index] + next[1] - fee;
                int skip = 0 + next[0];
                profit = max(sell, skip);
            }
            curr[buy] = profit;
        }
        next = curr;
    }
    return next[1];
}

int maxProfit(vector<int> &prices, int fee)
{
    return solve(prices, fee);
}

int main()
{
    vector<int> prices = {1, 3, 2, 8, 4, 9};
    cout << "the maximum profit is : " << maxProfit(prices, 2);
}
