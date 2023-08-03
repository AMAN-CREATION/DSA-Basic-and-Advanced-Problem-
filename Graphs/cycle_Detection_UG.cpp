#include <bits/stdc++.h>
using namespace std;

/*
using BFS to detect the loop
! time-complexity - o(n) will be space
*/

bool isCyclicBFS(int src, unordered_map<int, bool> &visited,
                 unordered_map<int, list<int>> &adj)
{
    unordered_map<int, int> parent;

    parent[src] = -1;
    visited[src] = 1;
    queue<int> q;
    q.push(src);

    while (!q.empty())
    {
        int frontNode = q.front();
        q.pop();
        // i is the neighbour of adjacency list;
        for (auto i : adj[frontNode])
        {
            if (visited[i] == true && i != parent[frontNode])
                return true;
            else if (!visited[i])
            {
                q.push(i);
                visited[i] = 1;
                parent[i] = frontNode;
            }
        }
    }
    return false;
}

bool isCyclicDFS(int node, int parent, unordered_map<int, bool> &visited,
                 unordered_map<int, list<int>> &adj)
{
    visited[node] = true;

    for (auto i : adj[node])
    {
        if (!visited[i])
        {
            bool found = isCyclicDFS(i, node, visited, adj);
            if (found)
                return true;
        }
        else if (i != parent)
            return true;
    }
    return false;
}

string cycleDetection(vector<vector<int>> &edges, int n, int m)
{
    // create adjacency list
    unordered_map<int, list<int>> adj;
    for (int i = 0; i < m; i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // to handle disconnected component
    unordered_map<int, bool> visited;
    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
        {
            bool ans = isCyclicDFS(i, -1, visited, adj);
            // bool ans = isCyclicBFS(i, visited, adj);
            if (ans == 1)
                return "Yes";
        }
    }
    return "No";
}

int main()
{
    // vector<vector<int>> edges = {{1, 2}, {2, 3}, {3, 4}, {4, 5}};
    vector<vector<int>> edges = {{1, 2}, {2, 3}, {3, 4}, {4, 5}, {5, 2}};
    int n = 5;
    int m = edges.size();

    string result = cycleDetection(edges, n, m);

    cout << "Cycle detection result: " << result << endl;

    return 0;
}
