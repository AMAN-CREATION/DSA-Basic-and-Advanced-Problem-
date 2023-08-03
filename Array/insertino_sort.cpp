#include <bits/stdc++.h>
using namespace std;

//! time-complexity:-o(n^2);

void insertionSort(vector<int> &arr, int n)
{
    for (int i = 1; i < n; i++)
    {
        int temp = arr[i];
        int j = i - 1;
        for (; j >= 0; j--)
        {
            if (arr[j] > temp)
                arr[j + 1] = arr[j];
            else
                break;
        }
        arr[j + 1] = temp;
    }
}

int main()
{
    vector<int> arr = {12, 11, 13, 5, 6};

    insertionSort(arr, arr.size());
    for (auto i : arr)
        cout << i << " ";

    return 0;
}
