#include <bits/stdc++.h>
using namespace std;

int detectCycleInDirectedGraph(int n, vector<pair<int, int>> &edges)
{

    unordered_map<int, list<int>> adj;

    // crate ajdicency list
    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i].first - 1;
        int v = edges[i].second - 1;

        adj[u].push_back(v);
    }

    // find all indegrees
    vector<int> indegree(n);
    for (auto i : adj)
    {
        for (auto j : i.second)
            indegree[j]++;
    }

    queue<int> q;
    for (int i = 0; i < n; i++)
    {
        if (indegree[i] == 0)
            q.push(i);
    }

    int cnt = 0;
    while (!q.empty())
    {
        int front = q.front();
        q.pop();

        cnt++;

        for (auto i : adj[front])
        {
            indegree[i]--;
            if (indegree[i] == 0)
                q.push(i);
        }
    }

    if (cnt == n)
        return false;
    else
        return true;
}

int main()
{
    int n = 5;
    vector<pair<int, int>> edges = {{1, 2}, {4, 1}, {2, 4}, {3, 4}, {5, 2}, {1, 3}};
    // true
    // vector<pair<int, int>> edges = {
    //     {1, 2},
    //     {2, 3},
    //     {3, 4},
    //     {4, 5},
    // }; // false

    bool hasCycle = detectCycleInDirectedGraph(n, edges);

    if (hasCycle)
        cout << "true" << endl;
    else
        cout << "false" << endl;

    return 0;
}