#include <bits/stdc++.h>
using namespace std;

int solveMemo(vector<int> &obstacles, int currLane, int currPos, vector<vector<int>> &dp)
{
    int n = obstacles.size() - 1;
    if (currPos == n)
        return 0;

    if (dp[currLane][currPos] != -1)
        return dp[currLane][currPos];

    // front direction
    if (obstacles[currPos + 1] != currLane)
    {
        return solveMemo(obstacles, currLane, currPos + 1, dp);
    }
    // left or right
    else
    {
        int ans = INT_MAX;
        for (int i = 1; i <= 3; i++)
        {
            if (currLane != i && obstacles[currPos] != i)
                ans = min(ans, 1 + solveMemo(obstacles, i, currPos, dp));
        }
        dp[currLane][currPos] = ans;
        return dp[currLane][currPos];
    }
}

int solveTabu(vector<int> &obstacles)
{
    int n = obstacles.size() - 1;
    vector<vector<int>> dp(4, vector<int>(obstacles.size(), INT_MAX));

    dp[0][n] = 0;
    dp[1][n] = 0;
    dp[2][n] = 0;
    dp[3][n] = 0;

    for (int currPos = n - 1; currPos >= 0; currPos--)
    {
        for (int currLane = 1; currLane <= 3; currLane++)
        {
            if (obstacles[currPos + 1] != currLane)
                dp[currLane][currPos] = dp[currLane][currPos + 1];
            else
            {
                int ans = 1e9;
                for (int i = 1; i <= 3; i++)
                {
                    if (currLane != i && obstacles[currPos] != i)
                    {
                        ans = min(ans, 1 + dp[i][currPos + 1]);
                    }
                    dp[currLane][currPos] = ans;
                }
            }
        }
    }
    return min(dp[2][0], min(1 + dp[1][0], 1 + dp[3][0]));
}

int solveSpace(vector<int> &obstacles)
{
    int n = obstacles.size() - 1;

    vector<int> curr(4, INT_MAX);
    vector<int> next(4, INT_MAX);

    next[0] = 0;
    next[1] = 0;
    next[2] = 0;
    next[3] = 0;

    for (int currPos = n - 1; currPos >= 0; currPos--)
    {
        for (int currLane = 1; currLane <= 3; currLane++)
        {
            if (obstacles[currPos + 1] != currLane)
                curr[currLane] = next[currLane];
            else
            {
                int ans = 1e9;
                for (int i = 1; i <= 3; i++)
                {
                    if (currLane != i && obstacles[currPos] != i)
                        ans = min(ans, 1 + next[i]);
                }
                curr[currLane] = ans;
            }
        }
        next = curr;
    }
    return min(next[2], min(1 + next[1], 1 + next[3]));
}

int minSideJumps(vector<int> &obstacles)
{
    // vector<vector<int>> dp(4, vector<int>(obstacles.size(), -1));
    // return solveMemo(obstacles, 2, 0, dp);

    // return solveTabu(obstacles);

    return solveSpace(obstacles);
}

int main()
{
    vector<int> obstacles = {0, 1, 2, 3, 0};

    int minJump = minSideJumps(obstacles);
    cout << "the minimum number of side jumps is : " << minJump << endl;
}