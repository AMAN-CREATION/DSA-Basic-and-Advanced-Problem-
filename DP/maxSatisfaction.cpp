#include <bits/stdc++.h>
using namespace std;

// tc and sc =o(n^2)
int solveMemo(vector<int> &satisfaction, int index, int time, vector<vector<int>> &dp)
{
    int n = satisfaction.size();
    if (index == n)
        return 0;

    if (dp[index][time] != -1)
        return dp[index][time];

    int include = satisfaction[index] * (time + 1) + solveMemo(satisfaction, index + 1, time + 1, dp);
    int exclude = 0 + solveMemo(satisfaction, index + 1, time, dp);

    return dp[index][time] = max(include, exclude);
}

// tc and sc =o(n^2)
int solveTabu(vector<int> &satisfaction)
{
    int n = satisfaction.size();
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

    for (int index = n - 1; index >= 0; index--)
    {
        for (int time = index; time >= 0; time--)
        {
            int include = satisfaction[index] * (time + 1) + dp[index + 1][time + 1];
            int exclude = 0 + dp[index + 1][time];

            dp[index][time] = max(include, exclude);
        }
    }
    return dp[0][0];
}

// tc = o(n^2) and sc = o(n)
int solveSpace(vector<int> &satisfaction)
{
    int n = satisfaction.size();

    vector<int> curr(n + 1, 0);
    vector<int> next(n + 1, 0);

    for (int index = n - 1; index >= 0; index--)
    {
        for (int time = index; time >= 0; time--)
        {
            int include = satisfaction[index] * (time + 1) + next[time + 1];
            int exclude = 0 + next[time];

            curr[time] = max(include, exclude);
        }
        next = curr;
    }
    return next[0];
}

int maxSatisfaction(vector<int> &satisfaction)
{
    sort(satisfaction.begin(), satisfaction.end());
    // int n = satisfaction.size();
    // vector<vector<int>> dp(n+1, vector<int>(n + 1, -1));
    // return solveMemo(satisfaction, 0, 0, dp);

    // return solveTabu(satisfaction);

    return solveSpace(satisfaction);
}

int main()
{
    vector<int> satisfaction = {-1, -8, 0, 5, -9};
    cout << "The maximum sum of like-time coefficient is :" << maxSatisfaction(satisfaction);
}
