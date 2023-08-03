#include <bits/stdc++.h>
using namespace std;

vector<int> candyStore(int candies[], int n, int k)
{
    sort(candies, candies + n);

    int mini = 0;
    int buy = 0;
    int free = n - 1;

    while (buy <= free)
    {
        mini += candies[buy];
        buy++;
        free -= k;
    }

    int maxi = 0;
    buy = n - 1;
    free = 0;

    while (buy >= free)
    {
        maxi += candies[buy];
        buy--;
        free += k;
    }
    vector<int> ans;
    ans.push_back(mini);
    ans.push_back(maxi);

    return ans;
}

int main()
{
    int candies[] = {3, 2, 1, 4, 5};
    int n = 5, k = 4;

    vector<int> ans = candyStore(candies, n, k);

    for (auto i : ans)
        cout << i << " ";
}
