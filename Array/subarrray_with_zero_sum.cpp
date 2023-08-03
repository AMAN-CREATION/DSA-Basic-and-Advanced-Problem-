#include <bits/stdc++.h>
using namespace std;

bool subArrayExits(int *arr, int n)
{
    unordered_set<int> sumSet;

    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
        if (sum == 0 || sumSet.find(sum) != sumSet.end())
        {
            cout << sum << endl;
            return true;
        }
        sumSet.insert(sum);
    }
    return false;
}

int main()
{
    int arr[] = {4, 2, -3, 1, 6};
    int n = sizeof(arr) / sizeof(n);

    if (subArrayExits(arr, n))
    {
        cout << "found 0 sum";
    }
    else
    {
        cout << "no found";
    }
}