#include <bits/stdc++.h>
using namespace std;

long long invCount = 0;

void merge(long long *arr, long long l, long long mid, long long r)
{
    long long l1 = mid - l + 1;
    long long a1[l1];
    long long l2 = r - mid;
    long long a2[l2];

    //*sorting left part;
    for (long long i = 0; i < l1; i++)
    {
        a1[i] = arr[i + l];
    }
    //*sorting right part
    for (long long j = 0; j < l2; j++)
    {
        a2[j] = arr[mid + j + 1];
    }

    long long left = 0, right = 0, k = l;

    while (left < l1 && right < l2)
    {
        if (a1[left] <= a2[right])
        {
            arr[k] = a1[left];
            left++;
        }
        else
        {
            arr[k] = a2[right];
            right++;
            invCount += (l1 - left);
        }
        k++;
    }
    while (left < l1)
    {
        arr[k++] = a1[left++];
    }
    while (right < l2)
    {
        arr[k++] = a2[right++];
    }
}

void mergeSort(long long *arr, long long l, long long r)
{
    if (l < r)
    {
        int mid = l + (r - l) / 2;

        //*recursive call to sorting left part;
        mergeSort(arr, l, mid);

        //*recursive call to sorting right part;
        mergeSort(arr, mid + 1, r);

        //*merging both halves
        merge(arr, l, mid, r);
    }
}

long long inversionCount(long long *arr, int n)
{
    mergeSort(arr, 0, n - 1);
    long long res = invCount;
    invCount = 0;
    return res;
}

int main()
{
    long long n;
    cin >> n;
    long long arr[n];
    for (long long i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << inversionCount(arr, n);
}