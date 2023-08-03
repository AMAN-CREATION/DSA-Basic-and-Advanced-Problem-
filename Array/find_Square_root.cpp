#include <bits/stdc++.h>
using namespace std;

long long int isSquare(int n)
{
    int s = 0;
    int e = n;
    long long int mid = s + (e - s) / 2;
    long long int ans = -1;

    while (s <= e)
    {
        long long int square = mid * mid;

        if (square == n)
            return mid;

        if (square < n)
        {
            ans = mid;
            s = mid + 1;
        }
        else
            e = mid - 1;
        mid = s + (e - s) / 2;
    }
    return ans;
}

double morePrecision(int n, int precision, int temSol)
{
    double factor = 1;
    double ans = temSol;

    for (int i = 0; i < precision; i++)
    {
        factor /= 10;
        for (double j = ans; j * j < n; j += factor)
            ans = j;
    }
    return ans;
}

int main()
{
    int n;
    cin >> n;
    int temSol = isSquare(n);
    cout << temSol << endl;

    cout << morePrecision(n, 3, temSol);
}