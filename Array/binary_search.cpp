#include <bits/stdc++.h>
using namespace std;

int binarySearch(int *arr, int n, int key)
{
    int s = 0;
    int e = n - 1;
    int mid = s + (e - s) / 2;

    while (s <= e)
    {
        if (arr[mid] == key)
            return mid;

        if (arr[mid] < key)
            s = mid + 1;
        else
            e = mid - 1;

        mid = s + (e - s) / 2;
    }
    return -1;
}

int main()
{
    int arr[] = {2, 4, 6, 8, 10, 12};
    int n = sizeof(arr) / sizeof(n);

    cout << "present or not " << binarySearch(arr, n, 6);
}