#include <bits/stdc++.h>
using namespace std;

int findKthPositive(vector<int> &arr, int k)
{
    int s = 0;
    int e = arr.size() - 1;

    while (s < e)
    {
        int mid = s + (e - s) / 2;
        if (arr[mid] - mid > k)
            e = mid;
        else
            s = mid + 1;
    }
    return e + k;
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << findKthPositive(arr, n);
    return 0;
}