#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> merge(vector<vector<int>> intervals)
{
    sort(intervals.begin(), intervals.end());
    vector<vector<int>> ans;
    vector<int> curr = intervals[0];

    for (auto i : intervals)
    {
        if (curr[1] >= i[0])
            curr[1] = max(curr[1], i[1]);
        else
            ans.push_back(curr);
        curr = i;
    }
    ans.push_back(curr);
    return ans;
}