#include <bits/stdc++.h>
using namespace std;

/*
! Time and space complexity is linear ;
*/

void dfs(int node, unordered_map<int, bool> &visited,
         unordered_map<int, list<int>> &adj, vector<int> &component)
{

    component.push_back(node);
    visited[node] = true;

    // recursive call for all node;
    for (auto i : adj[node])
    {
        if (!visited[i])
            dfs(i, visited, adj, component);
    }
}

vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges)
{
    unordered_map<int, list<int>> adj;
    // prepare adjecency list;
    for (int i = 0; i < edges.size(); i++)

    {
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<vector<int>> ans;
    unordered_map<int, bool> visited;

    for (int i = 0; i < V; i++)
    {
        if (!visited[i])
        {
            vector<int> component;
            dfs(i, visited, adj, component);
            ans.push_back(component);
        }
    }
    return ans;
}
int main()
{
    int V = 9; // Number of vertices
    int E = 7; // Number of edges
    vector<vector<int>> edges = {
        {0, 1},
        {0, 2},
        {0, 5},
        {3, 6},
        {4, 7},
        {4, 8},
        {7, 8},
    };

    vector<vector<int>> components = depthFirstSearch(V, E, edges);

    cout << "Connected Components:\n";
    for (const auto &component : components)
    {
        for (const auto &node : component)
        {
            cout << node << " ";
        }
        cout << endl;
    }

    return 0;
}
