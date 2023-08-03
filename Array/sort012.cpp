//! this problem is also name has "Dutch National Flag Problem "
#include <bits/stdc++.h>
using namespace std;

void sort012(int *arr, int n)
{
    int low = 0;
    int high = n - 1;
    int mid = 0;

    while (mid <= high)
    {
        switch (arr[mid])
        {
            //*if the element is 0;
        case 0:
            swap(arr[low++], arr[mid++]);
            break;

        //*if the element is 1.
        case 1:
            mid++;
            break;
        case 2:
            swap(arr[mid], arr[high--]);
            break;
        }
    }
}

void printArray(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    int arr[] = {0, 1, 2, 0, 1, 2};
    int n = sizeof(arr) / sizeof(n);
    cout << "befor sort ";
    printArray(arr, n);

    sort012(arr, n);
    cout << "after sort ";
    printArray(arr, n);
}