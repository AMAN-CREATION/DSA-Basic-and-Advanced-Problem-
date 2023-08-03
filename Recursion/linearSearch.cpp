#include <iostream>
using namespace std;

int linearSearch(int *arr, int size, int k)
{
    if (size == 0)
        return false;

    if (arr[0] == k)
    {
        return true;
    }
    else
    {
        int remainingPart = linearSearch(arr + 1, size - 1, k);
        return remainingPart;
    }
}

int main()
{
    int arr[5] = {1, 2, 3, 4, 5};
    int key = 2;

    int found = linearSearch(arr, 5, key);
    if (found)
    {
        cout << "presented in array";
    }
    else
    {
        cout << "not presented in array";
    }

    return 0;
}