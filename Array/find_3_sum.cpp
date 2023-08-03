#include <bits/stdc++.h>
using namespace std;

bool find3(int *arr, int n, int sum)
{
    sort(arr, arr + n);

    for (int i = 0; i < n - 2; i++)
    {
        int l = i + 1;
        int r = n - 1;
        while (l < r)
        {
            if (arr[i] + arr[l] + arr[r] == sum)
            {
                cout << "Triplet is " << arr[i] << " " << arr[l] << " " << arr[r] << " = " << sum;
                return true;
            }
            else if (arr[i] + arr[l] + arr[r] < sum)
                l++;
            else if (sum > 0)
                r--;
        }
    }
    return false;
}

int main()
{
    int arr[] = {1, 4, 45, 6, 10, 8};
    int n = sizeof(arr) / sizeof(n);

    int sum = 22;
    find3(arr, n, sum);
}