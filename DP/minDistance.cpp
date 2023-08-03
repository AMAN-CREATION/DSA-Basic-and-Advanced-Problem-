#include <bits/stdc++.h>
using namespace std;

int solveMemo(string a, string b, int i, int j, vector<vector<int>> &dp)
{
    if (i == a.length())
        return b.length() - j;
    if (j == b.length())
        return a.length() - i;

    if (dp[i][j] != -1)
        return dp[i][j];

    int ans = 0;
    if (a[i] == b[j])
        return solveMemo(a, b, i + 1, j + 1, dp);
    else
    {
        int insertAns = 1 + solveMemo(a, b, i, j + 1, dp);

        int deleteAns = 1 + solveMemo(a, b, i + 1, j, dp);

        int replaceAns = 1 + solveMemo(a, b, i + 1, j + 1, dp);

        ans = min(insertAns, min(deleteAns, replaceAns));
    }
    return dp[i][j] = ans;
}

int solveTabu(string a, string b)
{
    vector<vector<int>> dp(a.length() + 1, vector<int>(b.length() + 1, 0));

    for (int j = 0; j < b.length(); j++)
    {
        dp[a.length()][j] = b.length() - j;
    }

    for (int i = 0; i < a.length(); i++)
    {
        dp[i][b.length()] = a.length() - i;
    }

    for (int i = a.length() - 1; i >= 0; i--)
    {
        for (int j = b.length() - 1; j >= 0; j--)
        {
            int ans = 0;
            if (a[i] == b[j])
                ans = dp[i + 1][j + 1];
            else
            {
                int insertAns = 1 + dp[i][j + 1];

                int deleteAns = 1 + dp[i + 1][j];

                int reverseAns = 1 + dp[i + 1][j + 1];

                ans = min(insertAns, min(deleteAns, reverseAns));
            }
            dp[i][j] = ans;
        }
    }
    return dp[0][0];
}
int solveOptimal(string a, string b)
{
    vector<int> curr(b.length() + 1, 0);
    vector<int> next(b.length() + 1, 0);

    for (int j = 0; j < b.length(); j++)
    {
        next[j] = b.length() - j;
    }

    for (int i = a.length() - 1; i >= 0; i--)
    {
        for (int j = b.length(); j >= 0; j--)
        {
            curr[b.length()]=a.length()-i;

            int ans = 0;
            if (a[i] == b[j])
                ans = next[j + 1];
            else
            {
                int insertAns = 1 + curr[j + 1];
                int deleteAns = 1 + next[j];
                int replaceAns = 1 + next[j + 1];

                ans = min(insertAns, min(deleteAns, replaceAns));
            }
            curr[j] = ans;
        }
        next = curr;
    }
    return next[0];
}

int minDistance(string word1, string word2)
{
    // vector<vector<int>> dp(word1.length(), vector<int>(word2.length(), -1));
    // return solveMemo(word1, word2, 0, 0, dp);

    // return solveTabu(word1, word2);

    if(word1.length()==0)
            return word2.length();
        if(word2.length()==0)
            return word1.length();
    return solveOptimal(word1, word2);
}

int main()
{
    string word1 = "horse", word2 = "ros";

    cout << minDistance(word1, word2);
}
/*
Input: word1 = "horse", word2 = "ros"
Output: 3
Explanation:
horse -> rorse (replace 'h' with 'r')
rorse -> rose (remove 'r')
rose -> ros (remove 'e')
*/