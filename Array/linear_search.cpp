#include <bits/stdc++.h>
#include <vector>
using namespace std;

bool linearSearch(int *arr, int n, int key)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == key)
            return true;
    }
    return false;
}

int main()
{
    int arr[] = {1, 3, 5, 6, 7};
    int n = sizeof(arr) / sizeof(n);

    bool found = linearSearch(arr, n, 2);
    if (found)
        cout << "found";
    else
        cout << "not found";
}