#include <bits/stdc++.h>
using namespace std;

class Heap
{
public:
    int arr[100];
    int size;

    Heap()
    {
        arr[0] = -1;
        size = 0;
    }

    //*Insertion
    void insert(int val)
    {
        size = size + 1;
        int index = size;
        arr[index] = val;

        while (index > 1)
        {
            int parent = index / 2;

            if (arr[parent] < arr[index])
            {
                swap(arr[parent], arr[index]);
                index = parent;
            }
            else
                return;
        }
    }
    void print()
    {
        for (int i = 1; i <= size; i++)
            cout << arr[i] << " ";
        cout << endl;
    }

    //*Deletion
    void deleteNode()
    {
        if (size == 0)
        {
            cout << "Heap is empty " << endl;
            return;
        }
        // step 1: put last element into first index
        arr[1] = arr[size];
        // step 2: remove last element
        size--;

        // step 3: take root node to its correct position
        int i = 1;
        while (i < size)
        {
            int leftIndex = 2 * i;
            int rightIndex = 2 * i + 1;

            if (leftIndex < size && arr[i] < arr[leftIndex])
            {
                swap(arr[i], arr[leftIndex]);
                i = leftIndex;
            }
            else if (rightIndex < size && arr[i] < arr[rightIndex])
            {
                swap(arr[i], arr[rightIndex]);
                i = rightIndex;
            }
            else
                return;
        }
    }
};

//! Max Heap
// time-complexity - O(n);
void heapifyMax(int arr[], int n, int i)
{
    int largest = i;
    int left = 2 * i;
    int right = 2 * i + 1;

    // check left in under the bound
    if (left <= n && arr[largest] < arr[left])
        largest = left;
    // check right in under the bound
    if (right <= n & arr[largest] < arr[right])
        largest = right;

    // if largest index update in can't be equal to i index (largest=i) x;
    if (largest != i)
    {
        swap(arr[largest], arr[i]);
        heapifyMax(arr, n, largest);
    }
}

//! Min Heap
// time-complexity - O(n);
void heapifyMin(int arr[], int n, int i)
{
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[smallest] > arr[left])
        smallest = left;
    if (right < n && arr[smallest] > arr[right])
        smallest = right;

    if (smallest != i)
    {
        swap(arr[smallest], arr[i]);
        heapifyMin(arr, n, smallest);
    }
}

int main()
{
    Heap h;
    h.insert(50);
    h.insert(55);
    h.insert(53);
    h.insert(52);
    h.insert(54);
    h.print();

    h.deleteNode();
    h.print();

    int arr[6] = {-1, 54, 53, 55, 52, 50};
    int n = 5;

    //*heap creation
    for (int i = n / 2; i > 0; i--)
    {
        heapifyMax(arr, n, i);
    }
    cout << "Printing array now " << endl;
    for (int i = 1; i <= n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    /*
    Min heap
        int arr[5] = {54, 53, 55, 52, 50};
    int n = 5;

    for (int i = n / 2 - 1; i >= 0; i--)
    {
        heapifyMin(arr, n, i);
    }
    cout << "Printing array now " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
*/

    return 0;
}
/*
        55
       /  \
     54    53
    /  \
   50   52

output:- 55 54 53 50 52
time-complexity:-O(log n)||insertion & deletion ;
*/

// int main()
// {
//     int arr[5] = {54, 53, 55, 52, 50};
//     int n = 5;

//     for (int i = n / 2 - 1; i >= 0; i--)
//     {
//         heapifyMin(arr, n, i);
//     }
//     cout << "Printing array now " << endl;
//     for (int i = 0; i < n; i++)
//     {
//         cout << arr[i] << " ";
//     }
//     cout << endl;
// }