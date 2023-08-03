#include <bits/stdc++.h>
using namespace std;

int missingPositive(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        while (arr[i] >= 1 && arr[i] <= n && arr[i] != arr[arr[i] - 1])
        {
            swap(arr[i], arr[arr[i] - 1]);
        }
    }

    //*checking any element which is not equal to n+1;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] != i + 1)
            return i + 1;
    }

    return n + 1;
}

int main()
{
    int arr[] = {0, 10, 2, -10, -20};
    int n = sizeof(arr) / sizeof(n);

    int ans = missingPositive(arr, n);
    cout << ans;
    

    return 0;
}