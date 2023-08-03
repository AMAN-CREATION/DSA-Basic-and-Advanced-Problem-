// C++ program for implementation of
// selection sort
#include <bits/stdc++.h>
using namespace std;

void selectionSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int minIndex = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[minIndex])
                minIndex = j;
        }
        swap(arr[minIndex], arr[i]);
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
    int arr[] = {65, 22, 12, 22, 11};
    int n = sizeof(arr) / sizeof(n);
    cout << "Unsorted Array" << endl;
    printArray(arr, n);
    selectionSort(arr, n);
    cout << "Sorted Array" << endl;
    printArray(arr, n);
}
/*output==
Unsorted Array 65 22 12 22 11
Sorted Array 11 12 22 22 65*/