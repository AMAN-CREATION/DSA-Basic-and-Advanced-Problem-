#include <bits/stdc++.h>
#include <vector>
using namespace std;

void move(vector<int> &arr)
{
    sort(begin(arr), end(arr));
}

int main()
{
    vector<int> arr = {-1, -2, -3, -4, -5, 6, -7, 8, 9};
    move(arr);
    for (int i : arr)
    {
        cout << i << " ";
    }
    return 0;
}