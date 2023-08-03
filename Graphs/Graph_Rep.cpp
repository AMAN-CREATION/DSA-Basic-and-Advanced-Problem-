#include <bits/stdc++.h>
using namespace std;

template <typename T>

class Graph
{
public:
    unordered_map<T, list<T>> adj;

    void addEdge(T u, T v, bool direction)
    {
        //*direction = 0 -> undirected graph;
        //*direction = 1 -> directed graph;

        adj[u].push_back(v);
        if (direction == 0)
        {
            adj[v].push_back(u);
        }
    }

    void printAdj()
    {
        for (auto i : adj)
        {
            cout << i.first << " -> ";
            for (auto j : i.second)
            {
                cout << j << ", ";
            }
            cout << endl;
        }
    }
};

// int main()
// {
//     int n;
//     cout << "Enter the number of Nodes " << endl;
//     cin >> n;

//     int m;
//     cout << "Enter the number of Edges " << endl;
//     cin >> m;

//     Graph<int> g;

//     for (int i = 0; i < m; i++)
//     {
//         int u, v;
//         cin >> u >> v;
//         // creating an undirected graph
//         g.addEdge(u, v, 0);
//     }
//     g.printAdj();
// }

/*
*input
Enter the number of Nodes
5
Enter the number of Edges
6
0 1
1 2
2 3
3 1
3 4
0 4

*output
4 -> 3, 0,
0 -> 1, 4,
1 -> 0, 2, 3,
2 -> 1, 3,
3 -> 2, 1, 4,
*/

vector<vector<int>> printAdjacency(int n, int m, vector<vector<int>> &edges)
{
    vector<int> ans[n];
    for (int i = 0; i < m; i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];

        ans[u].push_back(v);
        ans[v].push_back(u);
    }
    vector<vector<int>> adj(n);
    for (int i = 0; i < n; i++)
    {
        adj[i].push_back(i);

        for (int j = 0; j < ans[i].size(); j++)
        {
            adj[i].push_back(ans[i][j]);
        }
    }
    return adj;
}

int main()
{
    int n = 4, m = 3;
    vector<vector<int>> edges = {
        {1, 2},
        {0, 3},
        {2, 3},
    };

    vector<vector<int>> adjacency = printAdjacency(n, m, edges);

    // Print the adjacency list
    for (int i = 0; i < adjacency.size(); i++)
    {
        cout << i << ": ";
        for (int j = 0; j < adjacency[i].size(); j++)
        {
            cout << adjacency[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}