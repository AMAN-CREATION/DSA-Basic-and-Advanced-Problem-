#include <bits/stdc++.h>
using namespace std;

int maxProfit(vector<int> &prices)
{
    int mini = prices[0];
    int profit = 0;
    for (int i = 1; i < prices.size(); i++)
    {
        int diff = prices[i] - mini;
        profit = max(profit, diff);
        mini = min(mini, prices[i]);
    }
    return profit;
}

int main()
{
    vector<int> prices = {7, 1, 5, 3, 6, 4};
    cout << "the maximum profit is : " << maxProfit(prices);
}

/*
Input: prices = [7,1,5,3,6,4]
Output: 5
Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
Note that buying on day 2 and selling on day 1 is not allowed because you must buy before you sell.

*/