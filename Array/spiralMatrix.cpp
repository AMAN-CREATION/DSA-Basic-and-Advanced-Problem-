#include <bits/stdc++.h>
#include <vector>
using namespace std;

// !solution first

class Solution
{
public:
    vector<int> spirallyTraverse(vector<vector<int>> matrix, int r, int c)
    {
        // code here
        int left = 0;
        // column
        int right = c - 1;
        // rows
        int top = 0;
        int bottom = r - 1;

        vector<int> ans;
        while (top <= bottom && left <= right)
        {
            // top
            for (int i = left; i <= right; i++)
            {
                ans.push_back(matrix[top][i]);
            }
            top++;

            // right
            for (int i = top; i <= bottom; i++)
            {
                ans.push_back(matrix[i][right]);
            }
            right--;
            // bottom
            if (top <= bottom)
            {
                for (int i = right; i >= left; i--)
                {
                    ans.push_back(matrix[bottom][i]);
                }
                bottom--;
            }
            if (left <= right)
            {
                for (int i = bottom; i >= top; i--)
                {
                    ans.push_back(matrix[i][left]);
                }
                left++;
            }
        }
        return ans;
    }
};

int main()
{

    int r, c;
    cin >> r >> c;
    vector<vector<int>> matrix(r);

    for (int i = 0; i < r; i++)
    {
        matrix[i].assign(c, 0);
        for (int j = 0; j < c; j++)
        {
            cin >> matrix[i][j];
        }
    }

    Solution ob;
    vector<int> result = ob.spirallyTraverse(matrix, r, c);
    for (int i = 0; i < result.size(); ++i)
        cout << result[i] << " ";
    cout << endl;

    return 0;
}
/*
 !solution second;


class Solution
{
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {
        int n = matrix.size();
        int m = matrix[0].size();
        int left = 0, right = m - 1, bottom = n - 1, top = 0;
        int direction = 1;
        vector<int> v;
        while (left <= right && top <= bottom)
        {
            if (direction == 1)
            {
                for (int i = left; i <= right; i++)
                    v.push_back(matrix[top][i]);
                direction = 2;
                top++;
            }

            else if (direction == 2)
            {
                for (int i = top; i <= bottom; i++)
                    v.push_back(matrix[i][right]);
                direction = 3;
                right--;
            }

            else if (direction == 3)
            {
                for (int i = right; i >= left; i--)
                    v.push_back(matrix[bottom][i]);
                direction = 4;
                bottom--;
            }

            else if (direction == 4)
            {
                for (int i = bottom; i >= top; i--)
                    v.push_back(matrix[i][left]);
                direction = 1;
                left++;
            }
        }
        return v;
    }
};

int main()
{
    vector<vector<int>> v = {{1, 2, 3, 4},
                             {5, 6, 7, 8},
                             {9, 10, 11, 12},
                             {13, 14, 15, 16}};

    Solution obj;
    vector<int> ans = obj.spiralOrder(v);

    for (int i : ans)
    {
        cout << i << " ";
    }
}
*/