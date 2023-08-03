#include <bits/stdc++.h>
using namespace std;

void printSolution(vector<vector<int>> &board)
{
    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board[i].size(); j++)
            if (board[i][j])
                cout << "Q ";
            else
                cout << ". ";
        printf("\n");
    }
}

void addSolution(vector<vector<int>> &ans, vector<vector<int>> &board, int n)
{
    vector<int> temp;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            temp.push_back(board[i][j]);
        }
    }
    ans.push_back(temp);
}

bool isSafe(int row, int col, vector<vector<int>> &board, int n)
{
    int x = row;
    int y = col;

    // check for same row
    while (y >= 0)
    {
        if (board[x][y] == 1)
            return false;
        y--;
    }

    x = row;
    y = col;
    // check for diagnol
    while (x >= 0 && y >= 0)
    {
        if (board[x][y] == 1)
            return false;
        y--;
        x--;
    }

    x = row;
    y = col;
    while (x < n && y >= 0)
    {
        if (board[x][y] == 1)
            return false;
        y--;
        x++;
    }
    return true;
}

void solve(int col, vector<vector<int>> &ans, vector<vector<int>> &board, int n)
{
    if (col == n)
    {
        addSolution(ans, board, n);
        return;
    }
    for (int row = 0; row < n; row++)
    {
        if (isSafe(row, col, board, n))
        {
            board[row][col] = 1;
            solve(col + 1, ans, board, n);
            board[row][col] = 0;
        }
    }
}

vector<vector<int>> nQueens(int n)
{
    vector<vector<int>> board(n, vector<int>(n, 0));
    vector<vector<int>> ans;

    solve(0, ans, board, n);
    return ans;
}

int main()
{
}
class Solution
{

private:
    bool isSafe(int row, int col, vector<vector<int>> &board, int n)
    {
        int x = row;
        int y = col;
        // row checking
        while (y >= 0)
        {
            if (board[x][y--] == 1)
            {
                return false;
            }
        }
        // diagonal 1 checking
        y = col;
        while (x >= 0 && y >= 0)
        {
            if (board[x--][y--] == 1)
            {
                return false;
            }
        }
        // diagonal 2 checking
        x = row;
        y = col;
        while (x < n && y >= 0)
        {
            if (board[x++][y--] == 1)
            {
                return false;
            }
        }
        return true;
    }

    void addSolution(vector<vector<string>> &ans, vector<vector<int>> &board, int n)
    {
        vector<string> temp;
        for (int i = 0; i < n; i++)
        {
            string s;
            for (int j = 0; j < n; j++)
            {
                if (board[i][j] == 1)
                {
                    s.push_back('Q');
                }
                else
                {
                    s.push_back('.');
                }
            }
            temp.push_back(s);
        }
        ans.push_back(temp);
    }

    void solve(int col, vector<vector<string>> &ans, vector<vector<int>> &board, int n)
    {
        if (col == n)
        {
            addSolution(ans, board, n);
            return;
        }

        for (int row = 0; row < n; row++)
        {
            if (isSafe(row, col, board, n))
            {
                // safe hai toh uss position ko mark karke next column par jao
                board[row][col] = 1;
                solve(col + 1, ans, board, n);
                // backtrack
                board[row][col] = 0;
            }
        }
    }

public:
    vector<vector<string>> solveNQueens(int n)
    {
        vector<vector<int>> board(n, vector<int>(n, 0));
        vector<vector<string>> ans;
        solve(0, ans, board, n);
        return ans;
    }
};