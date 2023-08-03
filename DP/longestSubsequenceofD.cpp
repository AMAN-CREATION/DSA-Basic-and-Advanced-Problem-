#include <bits/stdc++.h>
using namespace std;

int longestSubsequence(vector<int> &arr, int difference)
{
    unordered_map<int, int> dp;
    int ans = 0;

    for (int i = 0; i < arr.size(); i++)
    {
        int temp = arr[i] - difference;
        int tempAns = 0;

        // check answer already exisit in dp;
        if (dp.count(temp))
            tempAns = dp[temp];

        dp[arr[i]] = 1 + tempAns;

        ans = max(ans, dp[arr[i]]);
    }
    return ans;
}

int main()
{
    // vector<int> arr = {1, 2, 3, 4};
    vector<int> arr = {1, 3, 5, 7};
    int d = 1;
    cout << longestSubsequence(arr, d);
}
