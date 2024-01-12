#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int largeConsecutive(vector<int> &nums)
    {
        int n=nums.size();
        if(n==0)
            return 0;

        int longest=1;
        unordered_set<int> st;
        for(int i=0; i<n; i++){
            st.insert(nums[i]);
        }
        for(auto it:st){
            if(st.find(it-1)==st.end()){
                int cnt=1;
                int x=it;
                while(st.find(x+1)!=st.end()){
                    x++;
                    cnt++;
                }
                longest=max(longest,cnt);
            }
        }
        return longest;
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
