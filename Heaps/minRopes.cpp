//! Minimum cost of ropes
//*time complexity:-o(nlogn)

#include <bits/stdc++.h>
using namespace std;

long long minCost(long long arr[], long long n)
{
    priority_queue<long long, vector<long long>, greater<long long>> pq;

    for (long long i = 0; i < n; i++)
        pq.push(arr[i]);

    long long cost = 0;

    while (pq.size() > 1)
    {
        long long a = pq.top();
        pq.pop();
        long long b = pq.top();
        pq.pop();

        long long sum = a + b;

        cost += sum;
        pq.push(sum);
    }
    return cost;
}

int main()
{
    long long arr[] = {4, 3, 2, 6};
    long long n = sizeof(arr) / sizeof(n);

    cout << minCost(arr, n);
}

// 29