#include <bits/stdc++.h>
using namespace std;

vector<long long> printFirstNegativeInteger(long long int a[], long long int n, long long int k)
{
    deque<long long int> dq;
    vector<long long> ans;

    // process first window
    for (int i = 0; i < k; i++)
    {
        if (a[i] < 0)
            dq.push_back(i);
    }

    // push answer front first window
    if (dq.size() > 0)
        ans.push_back(a[dq.front()]);
    else
        ans.push_back(0);

    // now process for remaining window
    for (int i = k; i < n; i++)
    {
        // first pop out window element
        if (!dq.empty() && (i - dq.front()) >= k)
            dq.pop_front();

        // then push current element
        if (a[i] < 0)
            dq.push_back(i);

        // put in answer
        if (dq.size() > 0)
            ans.push_back(a[dq.front()]);
        else
            ans.push_back(0);
    }
    return ans;
}

int main()
{
    long long int n;
    cin >> n;
    long long arr[n];
    for (long long i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    long long int k = 2;
    vector<long long> ans = printFirstNegativeInteger(arr, n, k);
    for (auto i : ans)
        cout << i << " ";
    cout << endl;
    return 0;
}

// output
// 5
// -8 2 3 -6 10
// -8 0 -6 -6