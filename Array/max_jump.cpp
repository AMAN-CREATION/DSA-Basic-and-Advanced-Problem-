#include <bits/stdc++.h>
#include <vector>
using namespace std;

int maxJump(vector<int> nums)
{

    int position = 0;
    int jump = 0;
    int des = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        des = max(des, nums[i] + i);

        if (position == i)
        {
            position = des;
            jump++;
        }
    }
    return jump;
}

int main()
{
    vector<int> v = {2, 3, 1, 1, 4};
    cout << maxJump(v);
}