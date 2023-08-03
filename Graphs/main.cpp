#include <bits/stdc++.h>
using namespace std;

int solve(int n, int m, int s, int dest, vector<vector<int>> &edges)
{
    vector<int> dist(n + 1, 1e9);
    dist[s] = 0;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int u = edges[j][0];
            int v = edges[j][1];
            int wt = edges[j][2];

            if (dist[u] != 1e9 && ((dist[u] + wt) < dist[v]))
                dist[v] = dist[u] + wt;
        }
    }
    return dist[dest];
}

int main()
{
    int n = 4;    // Number of nodes
    int m = 4;    // Number of edges
    int src = 1;  // Source node
    int dest = 4; // Destination node

    vector<vector<int>> edges = {
        {1, 2, 4},
        {1, 3, 3},
        {2, 4, 7},
        {3, 4, -2}};

    int result = solve(n, m, src, dest, edges);
    cout << "The optimal path from source vertex " << src << " to destination vertex " << dest << " is: " << result << endl;

    return 0;
}