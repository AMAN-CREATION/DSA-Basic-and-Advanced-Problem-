#include <bits/stdc++.h>
using namespace std;
/* Memoization
time- complexity o(n*maxWeight);
*/

int solveMemo(vector<int> &weight, vector<int> &value, int index, int capacity, vector<vector<int>> &dp)
{
    // if only 1 item to steal, then just compare its weight with the knapsack capacity
    if (index == 0)
    {
        if (weight[index] <= capacity)
            return value[0];
        else
            return 0;
    }

    if (dp[index][capacity] != -1)
        return dp[index][capacity];

    int include = 0;
    if (weight[index] <= capacity)
        include = value[index] + solveMemo(weight, value, index - 1, capacity - weight[index], dp);

    int exclude = 0 + solveMemo(weight, value, index - 1, capacity, dp);

    dp[index][capacity] = max(exclude, include);

    return dp[index][capacity];
}

/* Tabulation
time- complexity o(n*maxWeight);
*/
int solveTabu(vector<int> &weight, vector<int> &value, int n, int capacity)
{
    // step 1
    vector<vector<int>> dp(n, vector<int>(capacity + 1, 0));

    // step 2
    for (int w = weight[0]; w <= capacity; w++)
    {
        if (weight[0] <= capacity)
            dp[0][w] = value[0];
        else
            dp[0][w] = 0;
    }

    for (int index = 1; index < n; index++)
    {
        for (int w = 0; w <= capacity; w++)
        {
            int include = 0;

            if (weight[index] <= w)
                include = value[index] + dp[index - 1][w - weight[index]];

            int exclude = 0 + dp[index - 1][w];

            dp[index][w] = max(exclude, include);
        }
    }
    return dp[n - 1][capacity];
}

/* space optimization
space - o(2*w);
*/

int solveSpace(vector<int> &weight, vector<int> &value, int n, int capacity)
{
    vector<int> prev(capacity + 1, 0);
    vector<int> curr(capacity + 1, 0);

    for (int w = weight[0]; w <= capacity; w++)
    {
        if (weight[0] <= capacity)
            prev[w] = value[0];
        else
            prev[w] = 0;
    }

    for (int index = 1; index < n; index++)
    {
        for (int w = 0; w <= capacity; w++)
        {
            int include = 0;

            if (weight[index] <= w)
                include = value[index] + prev[w - weight[index]];

            int exclude = 0 + prev[w];

            curr[w] = max(include, exclude);
        }
        prev = curr;
    }
    return prev[capacity];
}

/* space and code- optimization
space - o(w);
*/

int solveOptimum(vector<int> &weight, vector<int> &value, int n, int capacity)
{
    vector<int> prev(capacity + 1, 0);
    vector<int> curr(capacity + 1, 0);

    for (int w = weight[0]; w <= capacity; w++)
    {
        if (weight[0] <= capacity)
            curr[w] = value[0];
        else
            curr[w] = 0;
    }

    for (int index = 1; index < n; index++)
    {
        for (int w = capacity; w >= 0; w--)
        {
            int include = 0;

            if (weight[index] <= w)
                include = value[index] + curr[w - weight[index]];

            int exclude = 0 + curr[w];

            curr[w] = max(include, exclude);
        }
    }
    return curr[capacity];
}

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight)
{
    // vector<vector<int>> dp(n, vector<int>(maxWeight + 1, -1));
    // return solveMemo(weight, value, n - 1, maxWeight, dp);

    // return solveTabu(weight, value, n, maxWeight);

    // return solveSpace(weight, value, n, maxWeight);

    return solveOptimum(weight, value, n, maxWeight);
}

int main()
{
    int n = 4;
    vector<int> w = {1, 2, 4, 5};
    vector<int> v = {5, 4, 8, 6};
    int wt = 5;

    int maxWeight = knapsack(w, v, n, wt);

    cout << "MaxWeight is : " << maxWeight;
}
