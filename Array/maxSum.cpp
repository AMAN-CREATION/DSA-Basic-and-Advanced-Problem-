#include <bits/stdc++.h>
using namespace std;

// int maxSum(int *arr, int n)
// {
//     int res = INT_MIN;
//     for (int i = 0; i < n; i++)
//     {
//         int currSum = 0;
//         for (int j = 0; j < n; j++)
//         {
//             int index = (i + j) % n;
//             currSum += j * arr[index];
//         }
//         res = max(res, currSum);
//     }
//     return res;
// }

int findPivot(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > arr[(i + 1) % n])
            return i;
    }
}

int maxSum(int *arr, int n)
{
    int sum = 0;
    int pivot = findPivot(arr, n);

    int diff = n - 1 - pivot;
    for (int i = 0; i < n; i++)
    {
        sum += ((i + diff) % n) * arr[i];
    }
    return sum;
}

int main()
{
    int arr[] = {8, 3, 1, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << maxSum(arr, n) << endl;
    return 0;
}