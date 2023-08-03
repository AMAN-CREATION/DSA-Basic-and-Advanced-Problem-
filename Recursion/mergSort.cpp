#include <bits/stdc++.h>
using namespace std;
void print(int *arr, int s, int e)
{
    for (int i = s; i <= e; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
void merge(int *arr, int s, int e)
{
    int mid = s + (e - s) / 2;

    // save length both side
    int l1 = mid - s + 1;
    int l2 = e - mid;

    int *first = new int[l1];
    int *second = new int[l2];

    // copy value

    // left part
    int mainArrayIndex = s;
    for (int i = 0; i < l1; i++)
    {
        first[i] = arr[mainArrayIndex++];
    }

    // right part
    mainArrayIndex = mid + 1;
    for (int i = 0; i < l2; i++)
    {
        second[i] = arr[mainArrayIndex++];
    }

    // merge 2 sorted array
    int index1 = 0;
    int index2 = 0;
    mainArrayIndex = s;

    while (index1 < l1 && index2 < l2)
    {
        if (first[index1] < second[index2])
        {
            arr[mainArrayIndex++] = first[index1++];
        }
        else

            arr[mainArrayIndex++] = second[index2++];
    }
    while (index1 < l1)
    {
        arr[mainArrayIndex++] = first[index1++];
    }
    while (index2 < l2)
    {
        arr[mainArrayIndex++] = second[index2++];
    }
    delete[] first;
    delete[] second;
}

void mergesort(int *arr, int s, int e)
{
    print(arr, s, e);

    if (s >= e)
        return;

    int mid = s + (e - s) / 2;
    cout << "value of mid is " << mid;

    // for left part
    mergesort(arr, s, mid);

    // for right part
    mergesort(arr, mid + 1, e);

    merge(arr, s, e);
}

int main()
{
    int arr[15] = {3, 7, 0, 1, 5, 8, 3, 2, 34, 66, 87, 23, 12, 12, 12};
    int n = 15;

    mergesort(arr, 0, n - 1);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}