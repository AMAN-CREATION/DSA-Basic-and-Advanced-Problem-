#include <bits/stdc++.h>
using namespace std;

void subArraySum(int *arr, int n, int sum)
{
    //*pick a starting point
    for (int i = 0; i < n; i++)
    {
        int currentSum = arr[i];

        if (currentSum == sum)
        {
            cout << "Sum found at indexes " << i << endl;
            return;
        }
        else
        {
            //*try all subarrays start with i;
            for (int j = i + 1; j < n; j++)
            {
                currentSum += arr[j];
                if (currentSum == sum)
                {
                    cout << "sum found between index " << i << " and " << j << endl;
                    return;
                }
            }
        }
    }
    cout << "No subarray found";
    return;
}

int main()
{
    int arr[] = {15, 2, 4, 8, 9, 5, 10, 23};
    int n = sizeof(arr) / sizeof(n);

    int sum = 100;
    subArraySum(arr, n, sum);
    return 0;
}

class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        vector<int> v;
        unordered_map<int, int> m;
        for (int i = 0; i < nums.size(); i++)
        {
            if (m.count(target - nums[i]) > 0)
            {
                v.push_back(m[target - nums[i]]);
                v.push_back(i);

                return v;
            }
            m[nums[i]] = i;
        }
        return v;
    }
};