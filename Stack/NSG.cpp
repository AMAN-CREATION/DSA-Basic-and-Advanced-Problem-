#include <bits/stdc++.h>
using namespace std;

vector<int> nextGreaterElement(vector<int> nums)
{
    int n = nums.size();
    vector<int> ans(n, -1);
    stack<int> s;
    for (int i = 0; i < 2 * n; i++)
    {
        while (!s.empty() && nums[i % n] > nums[s.top() % n])
        {
            ans[s.top() % n] = nums[i % n];
            s.pop();
        }
        s.push(i % n);
    }
    return ans;
}
int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    vector<int> ans = nextGreaterElement(arr);
    for (auto i : ans)
    {
        cout << i << " ";
    }
}

// output:
// 5
// 1 2 3 4 3
// 2 3 4 -1 4