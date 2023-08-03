#include <bits/stdc++.h>
using namespace std;

void printUnion(int arr1[], int arr2[], int m, int n)
{
    int i = 0, j = 0;
    while (i < m && j < n)
    {
        if (arr1[i] < arr2[j])
            cout << arr1[i++] << " ";

        else if (arr2[j] < arr1[i])
            cout << arr2[j++] << " ";

        else
        {
            cout << arr2[j++] << " ";
            i++;
        }
    }

    while (i < m)
    {
        cout << arr1[i++] << " ";
    }
    while (j < n)
    {
        cout << arr2[j++] << " ";
    }
}

int main()
{
    int arr1[] = {1, 2, 4, 5, 6};

    int arr2[] = {3,
                  7,
                  1,
                  10};

    int n = sizeof(arr1) / sizeof(n);
    int m = sizeof(arr2) / sizeof(m);

    printUnion(arr1, arr2, m, n);
}