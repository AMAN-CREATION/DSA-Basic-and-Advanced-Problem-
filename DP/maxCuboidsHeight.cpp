#include <bits/stdc++.h>
using namespace std;

bool check(vector<int> &base, vector<int> &newBox)
{
    if (newBox[0] <= base[0] && newBox[1] <= base[1] && newBox[2] <= base[2])
        return true;
    else
        false;
}

int solveTabu(int n, vector<vector<int>> &cuboids)
{
    vector<int> currRow(n + 1, 0);
    vector<int> nextRow(n + 1, 0);

    for (int curr = n - 1; curr >= 0; curr--)
    {
        for (int prev = curr - 1; prev >= -1; prev--)
        {
            int include = 0;
            if (prev == -1 || check(cuboids[curr], cuboids[prev]))
                include = cuboids[curr][2] + nextRow[curr + 1];

            int exclude = 0 + nextRow[prev + 1];
            currRow[prev + 1] = max(include, exclude);
        }
        nextRow = currRow;
    }
    return nextRow[0];
}

int maxHeight(vector<vector<int>> &cuboids)
{
    for (auto &a : cuboids)
    {
        sort(a.begin(), a.end());
    }

    sort(cuboids.begin(), cuboids.end());

    return solveTabu(cuboids.size(), cuboids);
}

int main()
{
    vector<vector<int>> cuboids = {
        {50, 45, 20},
        {95, 37, 53},
        {45, 23, 12},
    };

    int height = maxHeight(cuboids);

    cout << "the maximum height of the stacked cuboids is :" << height << endl;
}