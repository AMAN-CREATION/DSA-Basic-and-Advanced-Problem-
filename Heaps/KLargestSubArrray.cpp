#include <bits/stdc++.h>
using namespace std;
/*
*solution-1
*time complexity-o(n^2logn);
int kthLargest(vector<int> &Arr, int N, int K)
{
    vector<int> sumStore;

    for (int i = 0; i < N; i++)
    {
        int sum = 0;
        for (int j = i; j < N; j++)
        {
            sum += Arr[j];
            sumStore.push_back(sum);
        }
    }
    sort(sumStore.begin(), sumStore.end());
    return sumStore[sumStore.size() - K];
}
*/

int kthLargest(vector<int> &arr, int k)
{
    priority_queue<int, vector<int>, greater<int>> pq;

    int n = arr.size();
    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        for (int j = i; j < n; j++)
        {
            sum += arr[j];
            if (pq.size() < k)
                pq.push(sum);
            else
            {
                if (sum > pq.top())
                {
                    pq.pop();
                    pq.push(sum);
                }
            }
        }
    }
    return pq.top();
}
int main()
{
    vector<int> arr = {3, 2, 1};
    int k = 2;
    cout << kthLargest(arr, k);
}
// 5