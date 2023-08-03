#include <bits/stdc++.h>
using namespace std;

int rainWater(int *arr, int n)
{
    int left = 0;
    int right = n - 1;

    int leftMax = 0;
    int rightMax = 0;

    int result = 0;

    while (left <= right)
    {
        if (rightMax <= leftMax)
        {
            result += max(0, rightMax - arr[right]);
            rightMax = max(rightMax, arr[right]);
            right -= 1;
        }
        else
        {
            result += max(0, leftMax - arr[left]);
            leftMax = max(leftMax, arr[left]);
            left += 1;
        }
    }
    return result;
}

// int main()
// {
//     int arr[] = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
//     int n = sizeof(arr) / sizeof(n);
//     cout << rainWater(arr, n) << endl;
//     return 0;
// }

int maxWater(vector<int> &height)
{
    stack<int> st;
    int n = height.size() - 1;
    int ans = 0;

    for (int i = 0; i <= n; i++)
    {
        while (!st.empty() && height[st.top()] < height[i])
        {
            int curr = st.top();
            st.pop();

            if (st.empty())
                break;

            int diff = i - st.top() - 1;
            ans += (min(height[st.top()], height[i]) - height[curr]) * diff;
        }
        st.push(i);
    }
    return ans;
}

int main()
{
    vector<int> v = {4, 2, 0, 3, 2, 5};
    cout << maxWater(v);
}