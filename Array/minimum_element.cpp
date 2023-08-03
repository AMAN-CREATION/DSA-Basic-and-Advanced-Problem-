#include <bits/stdc++.h>
using namespace std;

int findMin(int *arr, int n)
{
    int mini = arr[0];

    for (int i = 0; i < n; i++)
    {
        if (arr[i] < mini)
            mini = arr[i];
    }

    return mini;
}

//*using vector
// int findMin(vector<int> &nums)
// {
//     int mini = nums[0];
//     for (int i = 0; i < nums.size(); i++)
//     {
//         if (nums[i] < mini)
//             mini = nums[i];
//     }
//     return mini;
// }

int main()
{
    int arr[] = {2, 5, 7, 9, 10};
    int n = sizeof(arr) / sizeof(n);
    cout << findMin(arr, n);
}