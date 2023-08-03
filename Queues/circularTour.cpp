#include <bits/stdc++.h>
using namespace std;

class petrolPump
{
public:
    int petrol;
    int distance;
};

class Solution
{
public:
    int tour(petrolPump p[], int n)
    {
        int start = 0;
        int balance = 0;
        int deficit = 0;

        for (int i = 0; i < n; i++)
        {
            balance += p[i].petrol - p[i].distance;

            if (balance < 0)
            {
                start = i + 1;
                deficit += balance;
                balance = 0;
            }
        }
        if (deficit + balance >= 0)
            return start;
        else
            return -1;
    }
};

int main()
{
    int n;
    cin >> n;

    petrolPump p[n];

    for (int i = 0; i < n; i++)
    {
        cin >> p[i].petrol >> p[i].distance;
    }
    Solution obj;
    cout << obj.tour(p, n);
}

// output
// 4
// 4 6 7 4
// 6 5 3 5
// 1