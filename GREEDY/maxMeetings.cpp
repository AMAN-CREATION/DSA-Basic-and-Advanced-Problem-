//! N meetings in one room

#include <bits/stdc++.h>
using namespace std;

static bool cmp(pair<int, int> a, pair<int, int> b)
{
    return a.second < b.second;
}

int maxMeetings(int start[], int end[], int n)
{
    vector<pair<int, int>> time;

    for (int i = 0; i < n; i++)
    {
        pair<int, int> p = make_pair(start[i], end[i]);
        time.push_back(p);
    }

    sort(time.begin(), time.end(), cmp);

    int count = 1;
    int ansEnd = time[0].second;

    for (int i = 1; i < n; i++)
    {
        if (time[i].first > ansEnd)
        {
            count++;
            ansEnd = time[i].second;
        }
    }
    return count;
}

int main()
{
    int start[] = {1, 3, 0, 5, 8, 5};
    int end[] = {2, 4, 6, 7, 9, 9};

    int n = 6;

    cout << "the maximum number of meetings is : " << maxMeetings(start, end, n);
    return 0;
}