#include <bits/stdc++.h>
using namespace std;

int getPairsCount(int *arr, int n, int sum)
{
    int count = 0;
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            if (arr[i] + arr[j] == sum)
            {
                // cout << i << " " << j << endl;
                count++;
            }
    return count;
}

//*approach -2 using map
int countPairs(int *arr, int n, int sum)
{
    unordered_map<int, int> m;

    // Store counts of all elements in map m
    for (int i = 0; i < n; i++)
        m[arr[i]]++;

    int twice_count = 0;
    // iterate through each element and increment the
    // count (Notice that every pair is counted twice)
    for (int i = 0; i < n; i++)
    {
        twice_count += m[sum - arr[i]];

        // if (arr[i], arr[i]) pair satisfies the condition,
        // then we need to ensure that the count is
        // decreased by one such that the (arr[i], arr[i])
        // pair is not considered
        if (sum - arr[i] == arr[i])
            twice_count--;
    }

    // return the half of twice_count
    return twice_count / 2;
}

int main()
{
    int arr[] = {2, 4, 3, 2, 1};
    int n = sizeof(arr) / sizeof(n);
    int sum = 6;
    cout << "count of pairs is " << getPairsCount(arr, n, sum);
    return 0;
}