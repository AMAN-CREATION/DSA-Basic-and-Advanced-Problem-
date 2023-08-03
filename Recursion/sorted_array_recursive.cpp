#include <iostream>
using namespace std;

bool isSorted(int *arr, int size)
{
    // base case
    if (size == 0 || size == 1)
        return true;

    if (arr[0] > arr[1])
        return false;

    else
    {
        bool remaningPart = isSorted(arr + 1, size - 1);
        return remaningPart;
    }
}

int main()
{
    int arr[5] = {2, 4, 6, 8, 10};

    int size = 5;

    bool ans = isSorted(arr, size);

    if (ans)
        cout << "Array is shorted ";
    else
        cout << "Array is not sroted";
    return 0;
}