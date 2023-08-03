#include <bits/stdc++.h>
using namespace std;

/*
! Minimum Spanning Tree || Prim's Algorithm
*/
vector<pair<pair<int, int>, int>> calculatePrimsMST(int n, int m, vector<pair<pair<int, int>, int>> &g)
{
    // create adj list
    unordered_map<int, list<pair<int, int>>> adj;
    for (int i = 0; i < g.size(); i++)
    {
        int u = g[i].first.first;
        int v = g[i].first.second;
        int w = g[i].second;
        adj[u].push_back(make_pair(v, w));
        adj[v].push_back(make_pair(u, w));
    }

    vector<int> key(n + 1);
    vector<bool> mst(n + 1);
    vector<int> parent(n + 1);

    for (int i = 0; i <= n; i++)
    {
        key[i] = INT_MAX;
        mst[i] = false;
        parent[i] = -1;
    }

    key[1] = 0;
    parent[1] = -1;

    for (int i = 1; i < n; i++)
    {
        int mini = INT_MAX;
        int u;
        // find the min value node
        for (int v = 1; v <= n; v++)
        {
            if (mst[v] == false && key[v] < mini)
            {
                u = v;
                mini = key[v];
            }
        }

        // mark min node at true;
        mst[u] = true;

        // check its adjacent node
        for (auto it : adj[u])
        {
            int v = it.first;
            int w = it.second;
            if (mst[v] == false && w < key[v])
            {
                parent[v] = u;
                key[v] = w;
            }
        }
    }

    vector<pair<pair<int, int>, int>> result;
    for (int i = 2; i <= n; i++)
    {
        result.push_back({{parent[i], i}, key[i]});
    }
    return result;
}

vector<pair<pair<int, int>, int>> calculatePrimsMST(int n, int m, vector<pair<pair<int, int>, int>> &g);

int main()
{
    int n = 5;  // Number of vertices
    int m = 14; // Number of edges

    // Edge list representation: {{source, destination}, weight}
    vector<pair<pair<int, int>, int>> g = {
        {{1, 2}, 2},
        {{1, 4}, 6},
        {{2, 1}, 2},
        {{2, 3}, 3},
        {{2, 4}, 8},
        {{2, 5}, 5},
        {{3, 2}, 3},
        {{3, 5}, 7},
        {{4, 1}, 6},
        {{4, 2}, 8},
        {{4, 5}, 9},
        {{5, 2}, 5},
        {{5, 3}, 7},
        {{5, 4}, 9}};

    vector<pair<pair<int, int>, int>> mst = calculatePrimsMST(n, m, g);

    cout << "Minimum Spanning Tree Edges:\n";
    for (auto edge : mst)
    {
        cout << edge.first.first << " - " << edge.first.second << " : " << edge.second << "\n";
    }

    return 0;
}

/*
output:
Minimum Spanning Tree Edges:
1 - 2 : 2
2 - 3 : 3
1 - 4 : 6
2 - 5 : 5
*/

// vector<pair<pair<int, int>, int>> calculatePrimsMST(int n, int m, vector<pair<pair<int, int>, int>> &g)
// {
// Implementation of Prim's algorithm
// ...

// The code for calculating MST is already implemented in the provided function calculatePrimsMST()
// You can directly use the function as it is

// Just make sure to include the function declaration before the main() function
// and provide the implementation for the function definition after the main() function
// ...

// return the result as per the implementation in calculatePrimsMST()
// }