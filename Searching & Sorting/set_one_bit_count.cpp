#include <bits/stdc++.h>
using namespace std;

int countBits(int x)
{
    int count = 0;
    while (x)
    {
        if (x & 1)
            count += 1;
        x = x >> 1;
    }
    return count;
}

void sortBySetBitCount(int *arr, int n)
{
    vector<vector<int>> count(32);
    int setBits = 0;
    for (int i = 0; i < n; i++)
    {
        setBits = countBits(arr[i]);
        count[setBits].push_back(arr[i]);
    }
    int j = 0;
    for (int i = 31; i >= 0; i--)
    {
        vector<int> v = count[i];
        for (int i = 0; i < v.size(); i++)
            arr[j++] = v[i];
    }
}
int main()
{
    int arr[] = {5, 2, 3, 9, 4, 6, 7, 15, 32};
    int n = sizeof(arr) / sizeof(n);
    sortBySetBitCount(arr, n);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}