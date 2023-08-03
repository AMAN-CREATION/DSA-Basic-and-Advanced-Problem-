#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int majorityElement(int *arr, int n)
    {
        int element = 0;
        int count = 0;
        for (int i = 0; i < n; i++)
        {
            if (count == 0)
                element = arr[i];

            if (element == arr[i])
                count++;

            else
                count--;
        }
        count = 0;
        for (int i = 0; i < n; i++)
        {
            if (element == arr[i])
                count++;
        }

        if (count > n / 2)
            return element;
        return -1;
    }
};
int main()
{
    int arr[] = {3, 3, 4, 2, 4, 4, 2, 4, 4};
    int n = sizeof(arr) / sizeof(n);

    Solution obj;
    cout << obj.majorityElement(arr, n);
}