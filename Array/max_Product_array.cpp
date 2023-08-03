#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxProduct(vector<int> &nums)
    {
        int ans = nums[0];
        int maxi = ans;
        int mini = ans;

        for (int i = 1; i < nums.size(); i++)
        {
            maxi = max(nums[i], maxi * nums[i]);
            mini = min(nums[i], mini * nums[i]);
            ans = max(ans, maxi);

            if (nums[i] < 0)
            {
                swap(maxi, mini);
            }
        }
        return ans;
    }

    long long maxProduct(vector<int> arr, int n)
    {
        // code here
        long long ans = arr[0];
        long long maxi = ans;
        long long mini = ans;

        // n=arr.size();
        for (int i = 1; i < n; i++)
        {
            if (arr[i] < 0)
            {
                swap(maxi, mini);
            }
            maxi = max((long long)arr[i], maxi * arr[i]);
            mini = min((long long)arr[i], mini * arr[i]);
            ans = max(ans, maxi);
        }
        return ans;
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> v(n);

        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        Solution obj;
        auto ans = obj.maxProduct(v, n);
        cout << ans;
    }
}

// output:-
// 5
// 6 -3 -10 0 2
// 180