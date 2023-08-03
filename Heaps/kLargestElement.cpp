#include <bits/stdc++.h>
using namespace std;

int findKthLargest(vector<int> &nums, int k)
{
    int n = nums.size();
    priority_queue<int> pq;

    for (int i = 0; i < k; i++)
        pq.push(nums[i]);

    for (int i = k; i <= n; i++)
    {
        if (nums[i] < pq.top())
        {
            pq.pop();
            pq.push(nums[i]);
        }
    }
    int ans = pq.top();
    return ans;
}

int main()
{
    vector<int> arr = {3, 2, 1, 5, 6, 4};

    int k = arr.size() - 1;
    cout << findKthLargest(arr, k);
}