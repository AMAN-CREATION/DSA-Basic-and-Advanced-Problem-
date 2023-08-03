#include <iostream>
#include <vector>
using namespace std;
int findPeak(int arr[], int n)
{
    // first or last element is peak element
    if (n == 1)
        return 0;
    if (arr[0] >= arr[1])
        return 0;
    if (arr[n - 1] >= arr[n - 2])
        return n - 1;

    // check for every other element
    for (int i = 1; i < n - 1; i++)
    {

        // check if the neighbors are smaller
        if (arr[i] >= arr[i - 1] && arr[i] >= arr[i + 1])
            return i;
    }
}
int main()
{
    int arr[] = {5, 7, 20, 10, 15};

    int n = sizeof(arr) / sizeof(n);

    cout << "peak is " << findPeak(arr, n);
}

class Solution
{
public:
    int findPeakElement(vector<int> &nums)
    {
        int i = 0, j = nums.size() - 1;
        while (i < j)
        {
            int mid = i + (j - i) / 2;
            if (nums[mid] >= nums[mid + 1])
            {
                j = mid;
            }
            else
            {
                i = mid + 1;
            }
        }
        return i;
    }
};