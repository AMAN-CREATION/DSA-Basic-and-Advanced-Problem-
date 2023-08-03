#include <bits/stdc++.h>
using namespace std;

// time complexity = O(n);
void heapifyMax(int *arr, int n, int i)
{
    int largest = i;
    int left = 2 * i;
    int right = 2 * i + 1;

    if (left <= n && arr[largest] < arr[left])
        largest = left;
    if (right <= n && arr[largest] < arr[right])
        largest = right;

    if (largest != i)
    {
        swap(arr[largest], arr[i]);
        heapifyMax(arr, n, largest);
    }
}

// time complexity = O(nlogn);
void heapSort(int *arr, int n)
{
    int size = n;
    while (size > 1)
    {
        swap(arr[size], arr[1]);
        size--;

        heapifyMax(arr, size, 1);
    }
}

int main()
{
    int arr[6] = {-1, 54, 53, 55, 52, 50};
    int n = 5;

    //*heap creation
    for (int i = n / 2; i > 0; i--)
    {
        heapifyMax(arr, n, i);
    }
    cout << "Printing Heap arr " << endl;
    for (int i = 1; i <= n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    heapSort(arr, n);
    cout << "Printing Heap arr " << endl;
    for (int i = 1; i <= n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}