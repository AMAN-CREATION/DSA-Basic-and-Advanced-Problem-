#include <bits/stdc++.h>
using namespace std;

/*
!time complexity = O(n+e);
!space complexity = O(n+e);
*/

vector<int> shortestPath(vector<pair<int, int>> edges, int n, int m, int s, int t)
{

    unordered_map<int, list<int>> adj;
    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i].first;
        int v = edges[i].second;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    unordered_map<int, bool> visited;
    unordered_map<int, int> parent;
    queue<int> q;
    q.push(s);
    parent[s] = -1;
    visited[s] = true;

    while (!q.empty())
    {
        int front = q.front();
        q.pop();

        for (auto i : adj[front])
        {
            if (!visited[i])
            {
                visited[i] = true;
                parent[i] = front;
                q.push(i);
            }
        }
    }

    // prepare shortet path
    vector<int> ans;
    int currNode = t;
    ans.push_back(t);

    while (currNode != s)
    {
        currNode = parent[currNode];
        ans.push_back(currNode);
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

int main()
{
    int n = 4; // number of vertices
    int m = 4; // number of edges

    vector<pair<int, int>> edges = {
        {1, 2},
        {1, 3},
        {2, 3},
        {2, 1},
        {3, 4},
        {3, 1},
        {4, 3}};

    int s = 1; // source vertex
    int t = 4; // target vertex

    vector<int> path = shortestPath(edges, n, m, s, t);

    cout << "Shortest Path: ";
    for (int i = 0; i < path.size(); i++)
    {
        cout << path[i];
        if (i != path.size() - 1)
            cout << " -> ";
    }
    cout << endl;

    return 0;
}