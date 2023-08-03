#include <bits/stdc++.h>
using namespace std;

int isSum(int *arr, int size)
{
    // base case
    if (size == 0)
        return 0;
    if (size == 1)
        return arr[0];

    int remaningPart = isSum(arr + 1, size - 1);
    int sum = arr[0] + remaningPart;

    return sum;
}
int main()
{
    int arr[5] = {3, 2, 5, 1, 6};

    cout << isSum(arr, 5);
    return 0;
}