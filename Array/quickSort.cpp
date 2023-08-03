#include <bits/stdc++.h>
using namespace std;

// int partition(int *arr, int s, int e)
// {
//     int pivot = arr[s];

//     int cnt = 0;
//     for (int i = s + 1; i <= e; i++)
//     {
//         if (arr[i] <= pivot)
//             cnt++;
//     }
//     //*place pivot at right position
//     int pivotIndex = s + cnt;
//     swap(arr[pivotIndex], arr[s]);

//     //*left and right part
//     int i = s, j = e;

//     while (i < pivotIndex && j > pivotIndex)
//     {
//         while (arr[i] <= pivot)
//         {
//             i++;
//         }
//         while (arr[j] > pivot)
//         {
//             j--;
//         }
//         if (i < pivotIndex && j > pivotIndex)
//         {
//             swap(arr[i++], arr[j--]);
//         }
//     }
//     return pivotIndex;
// }

// void quickSort(int *arr, int s, int e)
// {
//     if (s >= e)
//         return;

//     int p = partition(arr, s, e);

//     quickSort(arr, s, p - 1);

//     quickSort(arr, p + 1, e);
// }

class Solution
{

public:
    //! time-complexity:-o(nlogn);
    // Function to swap two elements.
    void swap(int *s, int *e)
    {
        int temp = *s;
        *s = *e;
        *e = temp;
    }

    void quickSort(int arr[], int s, int e)
    {
        if (s < e)
        {
            // pi is partitioning index, arr[pi] is now at right place.
            int p = partition(arr, s, e);

            // Separately sorting elements before and after partitioning index.
            quickSort(arr, s, p - 1);
            quickSort(arr, p + 1, e);
        }
    }

    int partition(int arr[], int s, int e)
    {
        // Picking the pivot.
        int pivot = arr[e];

        int i = (s - 1);
        for (int j = s; j <= e - 1; j++)
        {

            if (arr[j] <= pivot)
            {
                i++;
                swap(&arr[i], &arr[j]);
            }
        }

        swap(&arr[i + 1], &arr[e]);
        return (i + 1);
    }
};

void quickSort(int arr[], int low, int high)
{
    // code here
    int i = low, j = high;
    int pivot = arr[(low + high) / 2];

    while (i <= j)
    {
        while (arr[i] < pivot)
            i++;
        while (arr[j] > pivot)
            j--;
        if (i <= j)
        {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            i++;
            j--;
        }
    }
    if (low < j)
        quickSort(arr, low, j);
    if (i < high)
        quickSort(arr, i, high);
}

//! using vector
/*
    Time Complexity: O(N ^ 2)
    Space Complexity: O(N)

    Where 'N' is the size of the array.
*/

void quickSortHelper(vector<int> &arr, int l, int r)
{
    // Base case.
    if (l >= r)
    {
        return;
    }

    int pivot = arr[r];

    int i = l, j = l;

    // Split the array.
    while (i < r)
    {
        if (arr[i] <= pivot)
        {
            swap(arr[i], arr[j]);
            j++;
        }
        i++;
    }

    swap(arr[r], arr[j]);

    // Call quickSortHelper on both halves.
    quickSortHelper(arr, l, j - 1);

    quickSortHelper(arr, j + 1, r);
}

vector<int> quickSort(vector<int> arr)
{
    quickSortHelper(arr, 0, arr.size() - 1);

    return arr;
}

int main()
{
    int arr[] = {1, 3, 5, 7, 9, 2, 4, 6, 8, 10};
    int n = sizeof(arr) / sizeof(n);

    cout << "original array ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    Solution obj;
    obj.quickSort(arr, 0, n - 1);
    cout << "sorted array ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}