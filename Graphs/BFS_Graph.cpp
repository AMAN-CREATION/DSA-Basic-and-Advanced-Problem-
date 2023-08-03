#include <bits/stdc++.h>
using namespace std;

/*
* Time and space complexity is O(N+E)
->vertex number fo node
->number of edges
*/

void prepareAdjList(unordered_map<int, set<int>> &adjList, vector<pair<int, int>> &edges)
{
    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i].first;
        int v = edges[i].second;

        adjList[u].insert(v);
        adjList[v].insert(u);
    }
}

void bfs(unordered_map<int, set<int>> &adjList, unordered_map<int, bool> &visited,
         vector<int> &ans, int node)
{
    queue<int> q;
    q.push(node);
    visited[node] = 1;

    while (!q.empty())
    {
        int frontNode = q.front();
        q.pop();

        // store frontNode to ans
        ans.push_back(frontNode);

        // traverse all neighbouer of frontNode
        for (auto i : adjList[frontNode])
        {
            if (!visited[i])
            {
                q.push(i);
                visited[i] = 1;
            }
        }
    }
}

vector<int> BFS(int vertex, vector<pair<int, int>> edges)
{
    unordered_map<int, set<int>> adjList;
    vector<int> ans;
    unordered_map<int, bool> visited;

    prepareAdjList(adjList, edges);

    // traverse all component of graph
    for (int i = 0; i < vertex; i++)
    {
        if (!visited[i])
            bfs(adjList, visited, ans, i);
    }
    return ans;
}

int main()
{
    int vertex = 4;
    vector<pair<int, int>> edges = {{4, 4}, {0, 1}, {0, 3}, {1, 2}, {2, 3}};
    vector<int> bfs_traversal = BFS(vertex, edges);

    cout << "BFS traversal of the graph: ";
    for (int i = 0; i < bfs_traversal.size(); i++)
    {
        cout << bfs_traversal[i] << " ";
    }
    cout << endl;

    return 0;
}