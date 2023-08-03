#include <bits/stdc++.h>
using namespace std;

int firstOcc(int *arr, int n, int key)
{
    int s = 0;
    int e = n - 1;
    int mid = s + (e - s) / 2;
    int ans = -1;
    while (s <= e)
    {
        if (arr[mid] == key)
        {
            ans = mid;
            e = mid - 1;
        }
        else if (arr[mid] < key)
            s = mid + 1;

        else
            e = mid - 1;
        mid = s + (e - s) / 2;
    }
    return ans;
}
int lastOcc(int *arr, int n, int key)
{
    int s = 0;
    int e = n - 1;
    int mid = s + (e - s) / 2;
    int ans = -1;
    while (s <= e)
    {
        if (arr[mid] == key)
        {
            ans = mid;
            s = mid + 1;
        }
        else if (arr[mid] < key)
            s = mid + 1;

        else
            e = mid - 1;
        mid = s + (e - s) / 2;
    }
    return ans;
}

vector<int> find(int arr[], int n, int x)

{
    int m = firstOcc(arr, n, x);
    int p = lastOcc(arr, n, x);

    return {m, p};
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, x;
        cin >> n >> x;
        int arr[n], i;
        for (i = 0; i < n; i++)
            cin >> arr[i];
        vector<int> ans;
        ans = find(arr, n, x);
        cout << ans[0] << " " << ans[1] << endl;
    }
    return 0;
}
