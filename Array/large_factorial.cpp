#include <bits/stdc++.h>
#include <vector>
using namespace std;

vector<int> factorial(int n)
{
    vector<int> ans;
    ans.push_back(n);
    int carry = 0;
    for (int i = n - 1; i >= 2; i--)
    {
        carry = 0;
        for (int j = ans.size() - 1; j >= 0; j--)
        {
            ans[j] = ans[j] * i + carry;
            carry = ans[j] / 10;
            ans[j] = ans[j] % 10;
        }
        while (carry > 0)
        {
            ans.insert(ans.begin(), carry % 10);
            carry /= 10;
        }
    }
    return ans;
}

int main()
{
    vector<int> ans = factorial(100);
    for (auto i : ans)
    {
        cout << i;
    }
}