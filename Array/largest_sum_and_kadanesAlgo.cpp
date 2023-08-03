//* Largest Sum Contiguous Subarray
//!(Kadane’s Algorithm)

#include <bits/stdc++.h>
#include <vector>
using namespace std;

class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int sum = 0;
        int maxi = nums[0];
        for (int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];
            maxi = max(maxi, sum);
            if (sum < 0)
                sum = 0;
        }
        return maxi;
    }
};

//* this is without using vector
// long long maxSubarraySum(int arr[], int n)
// {

//     int sum = 0;
//     int maxi = arr[0];
//     for (int i = 0; i < n; i++)
//     {
//         sum += arr[i];
//         maxi = max(maxi, sum);
//         if (sum < 0)
//             sum = 0;
//     }
//     return maxi;
// }

int main()
{
    vector<int> v = {-2, -3, 4, -1, -2, 2, 5, 3};
    Solution obj;
    cout << " largest sum is " << obj.maxSubArray(v);
}