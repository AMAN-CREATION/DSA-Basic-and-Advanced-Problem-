#include <bits/stdc++.h>
using namespace std;

int findPlatform(int *a, int *d, int n)
{
    sort(a, a + n);
    sort(d, d + n);

    int count = 0;
    int ans = 0;
    int i = 0, j = 0;
    while (i < n)
    {
        if (a[i] <= d[j])
        {
            count++;
            ans = max(ans, count);
            i++;
        }
        else if (a[i] > d[j])
        {
            count--;
            j++;
        }
    }
    return ans;
     // while (i < n && j < n)
    // {
    //     if (a[i] <= d[j])
    //     {
    //         count++;
    //         i++;
    //     }
    //     else if (a[i] > d[j])
    //     {
    //         count--;
    //         j++;
    //     }
    //     if (count > ans)
    //     {
    //         ans = count;
    //     }
    // }
    // return ans;
}

int main()
{
    int a[] = {900, 940, 950, 1100, 1500, 1800};
    int d[] = {910, 1200, 1120, 1130, 1900, 2000};
    int n = sizeof(a) / sizeof(n);

    cout << findPlatform(a, d, n);
    return 0;
}