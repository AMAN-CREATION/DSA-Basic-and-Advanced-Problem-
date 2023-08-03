#include <bits/stdc++.h>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> StockSpan(int *arr, int n)
    {
        stack<int> s;
        vector<int> ans;
        for (int i = 0; i < n; i++)
        {
            while (!s.empty() && arr[s.top()] <= arr[i])
            {
                s.pop();
            }
            if (s.empty())
                ans.push_back(i + 1);
            else
            {
                int top = s.top();
                ans.push_back(i - top);
            }
            s.push(i);
        }
        return ans;
    }

    // stack<pair<int, int>> stack;

    // int next(int price)
    // {
    //     int days = 1;
    //     while (!stack.empty() && stack.top().first <= price)
    //     {
    //         days += stack.top().second;
    //         stack.pop();
    //     }

    //     stack.push({price, days});
    //     return days;
    // }
};

int main()
{
    int arr[] = {100, 80, 60, 70, 60, 75, 85};
    int n = sizeof(arr) / sizeof(n);

    Solution obj;
    vector<int> ans = obj.StockSpan(arr, n);

    for (auto i : ans)
    {
        cout << i << " ";
    }
}
