#include <bits/stdc++.h>
#include <vector>
using namespace std;

bool isSafe(int row, int col, vector<vector<int>> &board, int val)
{
    for (int i = 0; i < 9; i++)
    {
        if (board[row][i] == val)
            return false;
        if (board[i][col] == val)
            return false;
        if (board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == val)
            return false;
    }
    return true;
}

bool solve(vector<vector<int>> &board)
{
    int ch = board[0].size();

    for (int row = 0; row < ch; row++)
    {
        for (int col = 0; col < ch; col++)
        {
            // cell empty
            if (board[row][col] == 0)
            {
                for (int val = 1; val <= 9; val++)
                {
                    if (isSafe(row, col, board, val))
                    {
                        board[row][col] = val;

                        bool nextPossible = solve(board);
                        if (nextPossible)
                            return true;
                        else
                        {
                            // backTrack
                            board[row][col] = 0;
                        }
                    }
                }
                return false;
            }
        }
    }
    return true;
}

void solveSudoku(vector<vector<int>> &board)
{
    solve(board);
}

int main()
{
    vector<vector<int>> arr = {{3, 0, 6, 5, 0, 8, 4, 0, 0},
                               {5, 2, 0, 0, 0, 0, 0, 0, 0},
                               {0, 8, 7, 0, 0, 0, 0, 3, 1},
                               {0, 0, 3, 0, 1, 0, 0, 8, 0},
                               {9, 0, 0, 8, 6, 3, 0, 0, 5},
                               {0, 5, 0, 0, 9, 0, 6, 0, 0},
                               {1, 3, 0, 0, 0, 0, 2, 5, 0},
                               {0, 0, 0, 0, 0, 0, 0, 7, 4},
                               {0, 0, 5, 2, 0, 6, 3, 0, 0}};

    solveSudoku(arr);
    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = 0; j < arr[i].size(); j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

/*
class Solution {
public:
    bool isSafe(int row ,int col,vector<vector<char>>& board,int val){
        for(int i=0; i<9; i++){
            if(board[row][i] - '0'==val)
                return false;
            if(board[i][col] - '0'==val)
                return false;
            if(board[3*(row/3 )+ i/3][3*(col/3)+ i%3] - '0'==val)
                return false;
        }
        return true;
    }

    bool solve(vector<vector<char>>& board){
        int ch=board[0].size();

        for(int row=0; row<ch; row++){
            for(int col=0; col<ch; col++){
                //cell empty
                if(board[row][col]=='.'){
                    for(int val=1; val<=9; val++){
                        if(isSafe(row,col,board,val)){
                            board[row][col]= '0'+val;

                            bool nextPossible=solve(board);
                            if(nextPossible)
                                return true;
                            else
                            {
                                board[row][col]='.';
                            }
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }

    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};

*/