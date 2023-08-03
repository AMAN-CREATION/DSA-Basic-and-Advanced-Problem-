#include <bits/stdc++.h>
using namespace std;
//! time-complexity:-o(	n^{2});

void bubbleSort(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        bool swapped = false;
        for (int j = 0; j < n - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        if (swapped == false)
            break;
    }
}
int main()
{
    int arr[] = {3, 1, 5, 2, 4, 10};
    int n = sizeof(arr) / sizeof(n);

    bubbleSort(arr, n);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}
