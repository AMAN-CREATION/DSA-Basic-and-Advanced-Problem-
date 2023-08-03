#include <bits/stdc++.h>
using namespace std;

/*
!time complexity = O(n*m);
!space complexity = O(n);
*/

int bellmonFord(int n, int m, int src, int dest, vector<vector<int>> &edges)
{
    vector<int> dist(n + 1, 1e9);
    dist[src] = 0;

    // n-1 times

    for (int i = 1; i <= n; i++)
    {
        // travers on edges list
        for (int j = 0; j < m; j++)
        {
            int u = edges[j][0];
            int v = edges[j][1];
            int wt = edges[j][2];

            if (dist[u] != 1e9 && ((dist[u] + wt) < dist[v]))
            {
                dist[v] = dist[u] + wt;
            }
        }
    }
    return dist[dest];

    // check for negative cycle
    // bool flag=0;
    // for(int j=0; j<m; j++){
    //     int u=edges[j][0];
    //     int v=edges[j][1];
    //     int wt=edges[j][2];

    //     if(dist[u]!=1e9 && ((dist[u]+wt)<dist[v])){
    //         flag=1;
    //     }
    // }

    // if(flag==0)
    //     return dist[dest];
    // return -1;
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

    int result = bellmonFord(n, m, src, dest, edges);
    cout << "The optimal path from source vertex " << src << " to destination vertex " << dest << " is: " << result << endl;

    return 0;
}