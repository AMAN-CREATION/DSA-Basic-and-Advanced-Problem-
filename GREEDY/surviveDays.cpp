/*
N – The maximum unit of food you can buy each day.
S – Number of days you are required to survive.
M – Unit of food required each day to survive.
*/

#include <bits/stdc++.h>
using namespace std;

int minimumDays(int s, int n, int m)
{
    int sunday = s / 7;

    int buyingDays = s - sunday;
    int totalFood = s * m;

    int ans = 0;
    if (totalFood % n == 0)
        ans = totalFood / n;
    else
        ans = totalFood / n + 1;

    if (ans <= buyingDays)
        return ans;
    else
        return -1;
}

int main()
{
    int s = 10, n = 16, m = 2;

    cout << minimumDays(s, n, m);
}