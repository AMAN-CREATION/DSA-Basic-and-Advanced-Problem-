#include <bits/stdc++.h>
using namespace std;

int countOccurrence(int arr[], int n, int x)
{
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (x == arr[i])
            count++;
    }
    return count;
}

int main()
{
    int arr[] = {1, 2, 2, 2, 2, 2, 2, 3, 4, 5, 5, 5, 5, 5, 5, 6};
    int n = sizeof(arr) / sizeof(n);

    int x = 5;
    cout << countOccurrence(arr, n, x);
}