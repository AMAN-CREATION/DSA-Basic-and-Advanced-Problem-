#include <bits/stdc++.h>
using namespace std;

void movesZeros(vector<int> &nums)
{
    int i = 0;
    int j = 0;

    while (j < nums.size())
    {
        if (nums[j] != 0)
        {
            swap(nums[j], nums[i]);
            i++;
        }
        j++;
    }
}

int main()
{
    vector<int> v = {0, 1, 0, 3, 1, 2};

    movesZeros(v);
    for (int i : v)
    {
        cout << i << " ";
    }
}