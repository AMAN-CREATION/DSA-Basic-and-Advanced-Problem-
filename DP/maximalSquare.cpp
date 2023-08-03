#include <bits/stdc++.h>
using namespace std;

int solveMemo(vector<vector<char>> &matrix, int i, int j, int &maxi, vector<vector<int>> &dp)
{
    if (i >= matrix.size() || j >= matrix[0].size())
        return 0;

    if (dp[i][j] != -1)
        return dp[i][j];

    int right = solveMemo(matrix, i, j + 1, maxi, dp);
    int diagonal = solveMemo(matrix, i + 1, j + 1, maxi, dp);
    int down = solveMemo(matrix, i + 1, j, maxi, dp);

    if (matrix[i][j] == '1')
    {
        dp[i][j] = 1 + min(right, min(diagonal, down));
        maxi = max(maxi, dp[i][j]);
        return dp[i][j];
    }
    else
    {
        return dp[i][j] = 0;
    }
}

int solveTabu(vector<vector<char>> &matrix, int &maxi)
{
    int row = matrix.size(), col = matrix[0].size();

    vector<vector<int>> dp(row + 1, vector<int>(col + 1, 0));

    for (int i = row - 1; i >= 0; i--)
    {
        for (int j = col - 1; j >= 0; j--)
        {
            int right = dp[i][j + 1];
            int diagonal = dp[i + 1][j + 1];
            int down = dp[i + 1][j];

            if (matrix[i][j] == '1')
            {
                dp[i][j] = 1 + min(right, min(diagonal, down));
                maxi = max(maxi, dp[i][j]);
            }
            else
            {
                dp[i][j] = 0;
            }
        }
    }
    return dp[0][0];
}

int solveSpace(vector<vector<char>> &matrix, int &maxi)
{
    int row = matrix.size(), col = matrix[0].size();

    // vector<vector<int>> dp(row + 1, vector<int>(col + 1, 0));
    vector<int> curr(col + 1, 0);
    vector<int> next(col + 1, 0);

    for (int i = row - 1; i >= 0; i--)
    {
        for (int j = col - 1; j >= 0; j--)
        {
            int right = curr[j + 1];
            int diagonal = curr[j + 1];
            int down = curr[j];

            if (matrix[i][j] == '1')
            {
                curr[j] = 1 + min(right, min(diagonal, down));
                maxi = max(maxi, curr[j]);
            }
            else
            {
                curr[j] = 0;
            }
        }
        next = curr;
    }
    return next[0];
}

int maximalSquare(vector<vector<char>> &matrix)
{
    int n = matrix.size(), m = matrix[0].size();
    int maxi = 0;

    // vector<vector<int>> dp(n, vector<int>(m, -1));
    // solveMemo(matrix, 0, 0, maxi, dp);
    // return maxi * maxi;

    // solveTabu(matrix, maxi);
    // return maxi * maxi;

    solveSpace(matrix, maxi);
    return maxi * maxi;
}

int main()
{
    vector<vector<char>> matrix = {
        {'1', '0', '1', '0', '0'},
        {'1', '0', '1', '1', '1'},
        {'1', '1', '1', '1', '1'},
        {'1', '0', '0', '1', '0'},
    }; // 4

    cout << maximalSquare(matrix);
}