#include <bits/stdc++.h>
using namespace std;

/* Memoization
time-complexity - constant
*/
int solveMemo(vector<int> &days, vector<int> &costs, int n, int index, vector<int> &dp)
{
    if (index >= n)
        return 0;

    if (dp[index] != -1)
        return dp[index];

    //*1-days
    int op1 = costs[0] + solveMemo(days, costs, n, index + 1, dp);

    int i;

    //* 7 days
    for (i = index; i < n && days[i] < days[index] + 7; i++)
        ;

    int op2 = costs[1] + solveMemo(days, costs, n, i, dp);

    //* 30 days
    for (i = index; i < n && days[i] < days[index] + 30; i++)
        ;

    int op3 = costs[2] + solveMemo(days, costs, n, i, dp);

    dp[index] = min(op1, min(op2, op3));
    return dp[index];
}

/* tabulation
time ans space complexity -
*/

int solveTabu(vector<int> &days, vector<int> &costs, int n)
{
    vector<int> dp(n + 1, INT_MAX);
    dp[n] = 0;

    for (int k = n - 1; k >= 0; k--)
    {
        //*1-days
        int op1 = costs[0] + dp[k + 1];

        int i;

        //* 7 days
        for (i = k; i < n && days[i] < days[k] + 7; i++)
            ;

        int op2 = costs[1] + dp[i];

        //* 30 days
        for (int i = k; i < n && days[i] < days[k] + 30; i++)
            ;

        int op3 = costs[2] + dp[i];

        dp[k] = min(op1, min(op2, op3));
    }
    return dp[0];
}

int mincostTickets(vector<int> &days, vector<int> &cost)
{
    int n = days.size();
    // vector<int> dp(n + 1, -1);
    // return solveMemo(days, cost, n, 0, dp);

    // return solveTabu(days, cost, n);

    /*space optimization*/
    int ans = 0;

    queue<pair<int, int>> month;
    queue<pair<int, int>> week;

    for (int day : days)
    {
        // step 1: remove expired days
        while (!month.empty() && month.front().first + 30 <= day)
            month.pop();

        while (!week.empty() && week.front().first + 7 <= day)
            week.pop();

        // step 2:add cost for current days
        week.push({day, ans + cost[1]});
        month.push({day, ans + cost[2]});

        // step 3 :ans update
        ans = min(ans + cost[0], min(week.front().second, month.front().second));
    }
    return ans;
}

int main()
{
    vector<int> days = {1, 4, 6, 7, 8, 20};
    vector<int> costs = {2, 7, 15};

    int ans = mincostTickets(days, costs);

    cout << "Minimum cost of ticket is " << ans << endl; // 11
}