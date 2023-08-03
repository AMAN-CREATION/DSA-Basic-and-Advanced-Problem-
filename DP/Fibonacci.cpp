#include <bits/stdc++.h>
using namespace std;

//! time amd space complexity = o(n);

//* top-down
int fib(int n, vector<int> &dp)
{
    if (n <= 1)
        return n;

    // step 2
    if (dp[n] != -1)
        return dp[n];

    dp[n] = fib(n - 1, dp) + fib(n - 2, dp);
    return dp[n];
}

// int main()
// {
//     int n;
//     cin >> n;

//     // step 1
//     vector<int> dp(n + 1);
//     for (int i = 0; i <= n; i++)
//     {
//         dp[i] = -1;
//     }

//     cout << fib(n, dp) << endl;
//     return 0;
// }

//* bottom-up

// int main()
// {
//     int n;
//     cin >> n;

//     vector<int> dp(n + 1);

//     dp[1] = 1;
//     dp[0] = 0;

//     for (int i = 2; i <= n; i++)
//     {
//         dp[i] = dp[i - 1] + dp[i - 2];
//     }

//     cout << dp[n] << endl;
// }

//* space optimization

int main()
{
    int n;
    cin >> n;

    int prev1 = 1;
    int prev2 = 0;

    if (n == 0)
        return prev2;

    for (int i = 2; i <= n; i++)
    {
        int curr = prev1 + prev2;
        // shift logic
        prev2 = prev1;
        prev1 = curr;
    }

    cout << prev1 << endl;
    return 0;
}

class Solution
{
public:
    int fib(int n)
    {
        if (n < 2)
        {
            return n;
        }
        int first = 0;
        int second = 1;
        for (int i = 2; i <= n; ++i)
        {
            int temp = first + second;
            first = second;
            second = temp;
        }
        return second;
    }
};