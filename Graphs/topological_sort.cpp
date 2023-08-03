#include <bits/stdc++.h>

using namespace std;
/*
!time complexity = O(n+e);
!space complexity = O(n+e);
*/

//  ! using DFS
// *normal way to sorting
// void topoSort(int node, unordered_map<int, bool> &visited, stack<int> &s, unordered_map<int, list<int>> &adj)
// {
//     visited[node] = true;
//     for (auto i : adj[node])
//     {
//         if (!visited[i])
//             topoSort(i, visited, s, adj);
//     }
//     s.push(node);
// }

// vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)
// {
//     unordered_map<int, list<int>> adj;
//     for (int i = 0; i < e; i++)
//     {
//         int u = edges[i][0];
//         int v = edges[i][1];

//         adj[u].push_back(v);
//     }

//     // call dfs topological sort util function for all components
//     unordered_map<int, bool> visited;
//     stack<int> s;
//     for (int i = 0; i < v; i++)
//     {
//         if (!visited[i])
//             topoSort(i, visited, s, adj);
//     }

//     vector<int> ans;
//     while (!s.empty())
//     {
//         ans.push_back(s.top());
//         s.pop();
//     }
//     return ans;
// }

// int main()
// {
//     int v = 2; // Number of vertices
//     int e = 3; // Number of edges

//     vector<vector<int>> edges = {
//         {2, 1},
//         {1, 0},
//         {0, 2}};

//     vector<int> sortedOrder = topologicalSort(edges, v, e);

//     cout << "Topological order: ";
//     for (int i = 0; i < sortedOrder.size(); i++)
//     {
//         cout << sortedOrder[i] << " ";
//     }
//     cout << endl;

//     return 0;
// }

// //! using BFS and kahn's algorithm
vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)
{
    unordered_map<int, list<int>> adj;

    for (int i = 0; i < e; i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
    }

    // find all indegrees
    vector<int> indegree(v);
    for (auto i : adj)
    {
        for (auto j : i.second)
        {
            indegree[j]++;
        }
    }

    // insert all 0 indegree in queue
    queue<int> q;
    for (int i = 0; i < v; i++)
    {
        if (indegree[i] == 0)
            q.push(i);
    }

    // do bfs
    vector<int> ans;
    while (!q.empty())
    {
        int frontNode = q.front();
        q.pop();

        ans.push_back(frontNode);

        for (auto i : adj[frontNode])
        {
            indegree[i]--;
            if (indegree[i] == 0)
                q.push(i);
        }
    }
    return ans;
}

int main()
{
    vector<vector<int>> edges = {{1, 0}, {2, 0}, {3, 1}, {3, 2}};
    int v = 4;
    int e = 4;

    vector<int> sortedOrder = topologicalSort(edges, v, e);

    cout << "Topological Sort Order: ";
    for (int vertex : sortedOrder)
    {
        cout << vertex << " ";
    }
    cout << endl;

    return 0;
}