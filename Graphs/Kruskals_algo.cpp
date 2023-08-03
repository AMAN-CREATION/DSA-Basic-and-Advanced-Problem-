#include <bits/stdc++.h>
using namespace std;

/*
*e-edges,v=vertices
!time complexity = O(mlog n);
!space complexity = O(n);
*/

bool cmp(vector<int> &a, vector<int> &b)
{
    return a[2] < b[2];
}

void makeSet(vector<int> &parnet, vector<int> &rank, int n)
{
    for (int i = 0; i < n; i++)
    {
        parnet[i] = i;
        rank[i] = 0;
    }
}

int findParent(vector<int> &parent, int node)
{
    if (parent[node] == node)
        return node;

    return parent[node] = findParent(parent, parent[node]);
}

void unionSet(int u, int v, vector<int> &parent, vector<int> &rank)
{
    u = findParent(parent, u);
    v = findParent(parent, v);

    if (rank[u] < rank[v])
        parent[u] = v;
    else if (rank[v] < rank[u])
        parent[v] = u;
    else
    {
        parent[v] = u;
        rank[u]++;
    }
}

int minimumSpanningTree(vector<vector<int>> &edges, int n)
{
    sort(edges.begin(), edges.end(), cmp);
    vector<int> parent(n);
    vector<int> rank(n);
    makeSet(parent, rank, n);

    int minWeight = 0;

    for (int i = 0; i < edges.size(); i++)
    {
        int u = findParent(parent, edges[i][0]);
        int v = findParent(parent, edges[i][1]);
        int wt = edges[i][2];

        if (u != v)
        {
            minWeight += wt;
            unionSet(u, v, parent, rank);
        }
    }
    return minWeight;
}

int main()
{
    int n = 4; // Number of nodes
    int m = 4; // Number of edges

    vector<vector<int>> edges(m, vector<int>(3));
    edges[0] = {0, 1, 3};
    edges[1] = {0, 3, 5};
    edges[2] = {1, 2, 1};
    edges[3] = {2, 3, 8};

    int minWeight = minimumSpanningTree(edges, n);
    cout << "Minimum spanning tree weight: " << minWeight << endl;

    return 0;
}