#include <bits/stdc++.h>
using namespace std;

// int main()
// {
//     int arr[] = {1, 2, 2, 2, 3, 3, 4, 5, 5, 5, 6, 6};
//     int n = sizeof(arr) / sizeof(n);

//     for (int i = 0; i < n; i++)
//     {
//         arr[arr[i] % n] = arr[arr[i] % n] + n;
//     }
//     cout << "element is " << endl;
//     for (int i = 0; i < n; i++)
//     {
//         if (arr[i] >= n * 2)
//         {
//             cout << i << " " << endl;
//         }
//     }
//     return 0;
// }

// !Remove Duplicates from Sorted Array

int removeDuplicates(vector<int> &nums)
{
    int i = 0;
    for (int j = 1; j < nums.size(); j++)
    {
        if (nums[i] != nums[j])
        {
            nums[i + 1] = nums[j];
            i++;
        }
    }
    return (i + 1);
}

int main()
{
    vector<int> arr = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
    int n = arr.size();
    removeDuplicates(arr);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}