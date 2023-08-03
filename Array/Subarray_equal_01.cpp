#include <bits/stdc++.h>
using namespace std;

int countSubArray(int *arr, int n)
{
    unordered_map<int, int> m;
    int sum = 0;
    long long ans = 0;
    m[0] = 1;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 0)
        {
            sum -= 1;
        }
        else
        {
            sum += 1;
        }
        if (m.find(sum) != m.end())
        {
            ans += m[sum];
            m[sum]++;
        }
        else
        {
            m[sum] = 1;
        }
    }
    return ans;
}

int main()
{
    int arr[] = {1, 0, 0, 1, 0, 1, 1};
    int n = sizeof(arr) / sizeof(n);
    cout << "count = " << countSubArray(arr, n);
}