#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];

    int q;
    cin >> q;

    sort(a, a + n);

    int prev[n + 1];
    prev[0] = 0;

    for (int i = 1; i <= n; i++)
        prev[i] = prev[i - 1] + a[i - 1];

    while (q--)
    {
        int x;
        cin >> x;
        int idx = upper_bound(a, a + n, x) - a;
        cout << idx << " " << prev[idx] << endl;
    }
    return 0;
}

// output:
// 7
// 1 2 3 4 5 6 7
// 3
// 3
// 3 6
// 10
// 7 28
// 2
// 2 3