#include <bits/stdc++.h>
using namespace std;

void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
{
    int i = m - 1, j = n - 1;
    while (i >= 0 && j >= 0)
    {
        if (nums1[i] >= nums2[j])
        {
            nums1[i + j + 1] = nums1[i];
            i--;
        }
        else
        {
            nums1[i + j + 1] = nums2[j];
            j--;
        }
    }
    while (j >= 0)
    {
        nums1[j] = nums2[j];
        j--;
    }
}

// int main()
// {
//     vector<int> arr1 = {1, 3, 5, 7, 9};
//     vector<int> arr2 = {2, 4, 6};
//  = merge(arr1, 5, arr2, 3);

//     return 0;
// }
void mergeSorted(int *arr1, int n, int *arr2, int m, int *arr3)
{
    int i = 0, j = 0;
    int k = 0;
    while (i < n && j < m)
    {
        if (arr1[i] < arr2[j])
            arr3[k++] = arr1[i++];
        else
            arr3[k++] = arr2[j++];
    }
    while (i < n)
    {
        arr3[k++] = arr1[i++];
    }
    while (j < m)
    {
        arr3[k++] = arr2[j++];
    }
}

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    int arr1[5] = {1, 3, 5, 7, 9};
    int arr2[3] = {2, 4, 6};

    int arr3[8] = {0};

    mergeSorted(arr1, 5, arr2, 3, arr3);

    printArray(arr3, 8);

    return 0;
}