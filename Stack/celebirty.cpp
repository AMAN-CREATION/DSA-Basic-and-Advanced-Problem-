#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    bool knows(vector<vector<int>> &M, int a, int b, int n)
    {
        if (M[a][b] == 1)
            return true;
        else
            return false;
    }

public:
    // Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int>> &M, int n)
    {
        stack<int> s;
        // step1: push all element in stack
        for (int i = 0; i < n; i++)
        {
            s.push(i);
        }

        // step2: get 2 elements and copare them

        while (s.size() > 1)
        {

            int a = s.top();
            s.pop();

            int b = s.top();
            s.pop();

            if (knows(M, a, b, n))
            {
                s.push(b);
            }
            else
            {
                s.push(a);
            }
        }
        int ans = s.top();
        // step3: single element in stack is potential celeb
        // so verify it

        int zeroCount = 0;

        for (int i = 0; i < n; i++)
        {
            if (M[ans][i] == 0)
                zeroCount++;
        }

        // all zeroes
        if (zeroCount != n)
            return -1;

        // column check
        int oneCount = 0;

        for (int i = 0; i < n; i++)
        {
            if (M[i][ans] == 1)
                oneCount++;
        }

        if (oneCount != n - 1)
            return -1;

        return ans;
    }
};

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> m(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> m[i][j];
        }
    }
    Solution obj;
    cout << obj.celebrity(m, n) << endl;
}

// output
// 3
// 0 1 0
// 0 0 0
// 0 1 0
// 1

// int findCelebrity(int n)
// {

//     // Create a stack and push all ids in it.
//     stack<int> ids;
//     for (int i = 0; i < n; i++)
//     {
//         ids.push(i);
//     }

//     // Finding celebrity.
//     while (ids.size() > 1)
//     {
//         int id1 = ids.top();
//         ids.pop();
//         int id2 = ids.top();
//         ids.pop();

//         if (knows(id1, id2))
//         {
//             // Because person with id1 can not be celebrity.
//             ids.push(id2);
//         }
//         else
//         {
//             // Because person with id2 can not be celebrity.
//             ids.push(id1);
//         }
//     }

//     int celebrity = ids.top();
//     bool knowAny = false, knownToAll = true;

//     // Verify whether the celebrity knows any other person.
//     for (int i = 0; i < n; i++)
//     {
//         if (knows(celebrity, i))
//         {
//             knowAny = true;
//             break;
//         }
//     }

//     // Verify whether the celebrity is known to all the other person.
//     for (int i = 0; i < n; i++)
//     {
//         if (i != celebrity and !knows(i, celebrity))
//         {
//             knownToAll = false;
//             break;
//         }
//     }

//     if (knowAny or !knownToAll)
//     {
//         // If verificatin failed, then it means there is no celebrity at the party.
//         celebrity = -1;
//     }

//     return celebrity;
// }