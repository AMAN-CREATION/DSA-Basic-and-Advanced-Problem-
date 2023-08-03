#include <bits/stdc++.h>
using namespace std;

void heapifyMax(vector<int> &ans, int n, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && ans[largest] < ans[left])
        largest = left;
    if (right < n && ans[largest] < ans[right])
        largest = right;

    if (largest != i)
    {
        swap(ans[largest], ans[i]);
        heapifyMax(ans, n, largest);
    }
}

vector<int> mergeHeap(vector<int> &a, vector<int> &b, int n, int m)
{
    vector<int> ans;
    for (auto i : a)
        ans.push_back(i);
    for (auto i : b)
        ans.push_back(i);

    int size = ans.size();
    for (int i = size / 2 - 1; i >= 0; i--)
        heapifyMax(ans, size, i);
    return ans;
}

int main()
{
    vector<int> a = {10, 5, 6, 2};
    vector<int> b = {12, 7, 9};

    int n = a.size();
    int m = b.size();
    vector<int> ans = mergeHeap(a, b, n, m);
    for (auto i : ans)
        cout << i << " ";
}