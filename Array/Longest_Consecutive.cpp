#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int largeConsecutive(vector<int> &nums)
    {
        set<int> s;
        for (int n : nums)
        {
            s.insert(n);
        }
        int ans = 0;
        for (int n : nums)
        {
            if (!s.count(n - 1))
            {
                int i = n;
                int currAns = 1;
                while (s.count(i + 1))
                {
                    i += 1;
                    currAns += 1;
                }
                ans = max(ans, currAns);
            }
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
        cout << "largest consecutive is " << obj.largeConsecutive(v);
    }
    return 0;
}

// 1
// 7
// 2 6 1 9 4 5 3
// largest consecutive is 6