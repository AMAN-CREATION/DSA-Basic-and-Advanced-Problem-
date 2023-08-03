#include <bits/stdc++.h>
using namespace std;

void findMissing(int *arr, int n)
{
    int temp[n + 1];
    for (int i = 0; i <= n; i++)
    {
        temp[i] = 0;
    }
    for (int i = 0; i <= n; i++)
    {
        temp[arr[i] - 1] = 1;
    }
    int ans;
    for (int i = 0; i <= n; i++)
    {
        if (temp[i] == 0)
            ans = i + 1;
    }
    cout << ans;
}

// int main()
// {
//     int arr[] = {1, 6, 3, 7, 5, 4};
//     int n = sizeof(arr) / sizeof(n);
//     findMissing(arr, n);
// }

int missingNumber(vector<int> &v, int n)
{
    int total = (n + 1) * n / 2;
    for (int i = 0; i < n - 1; i++)
    {
        total -= v[i];
    }
    return total;
}

int main()
{
    int n;
    cin >> n;

    vector<int> v(n - 1);

    for (int i = 0; i <= n - 1; ++i)
    {
        cin >> v[i];
    }
    cout << "missing number is " << missingNumber(v, n);
}