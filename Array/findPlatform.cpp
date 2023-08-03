#include <bits/stdc++.h>
using namespace std;

int findPlatform(int arr[], int dep[], int n)
{
    sort(arr, arr + n);
    sort(dep, dep + n);

    int ans = 0;
    int count = 0;
    int i = 0, j = 0;

    while (i < n)
    {
        if (arr[i] <= dep[j])
        {
            count++;
            ans = max(ans, count);
            i++;
        }
        else if (arr[i] > dep[j])
        {
            count--;
            j++;
        }
    }
    return ans;
}

int main()
{
    int a[] = {100, 300, 500};
    int d[] = {900, 400, 600};

    int n = sizeof(a) / sizeof(n);
    cout << findPlatform(a, d, n);
}