#include <bits/stdc++.h>
using namespace std;

// !Kth smallest element

// arr : given array
// l : starting index of the array i.e 0
// r : ending index of the array i.e size-1
// k : find kth smallest element and return using this function

int kSmallest(int arr[], int l, int r, int k)
{
    priority_queue<int> pq;

    for (int i = 0; i < k; i++)
    {
        pq.push(arr[i]);
    }

    for (int i = k; i <= r; i++)
    {
        if (arr[i] < pq.top())
        {
            pq.pop();
            pq.push(arr[i]);
        }
    }
    int ans = pq.top();
    return ans;
}

int main()
{
    int arr[] = {7, 10, 4, 3, 20, 15};
    int n = sizeof(arr) / sizeof(n);
    int k = 3;
    cout << kSmallest(arr, 0, n - 1, k);
}