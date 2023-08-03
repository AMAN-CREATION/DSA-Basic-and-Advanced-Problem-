#include <iostream>
#include <vector>
using namespace std;

// void reverse(int *arr, int s, int e)
// {
//     while (s <= e)
//     {
// int temp=arr[s];
// arr[s]=arr[e];
// arr[e]=temp;
// s++;
// e--;
/*
//         swap(arr[s++], arr[e--]);
*/
//     }
// }
void print(vector<int> v)
{
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
}

// reverse with array with vector
// approach-1
vector<int> reverseArray(vector<int> v)
{
    int s = 0;
    int e = v.size() - 1;
    while (s <= e)
    {
        swap(v[s], v[e]);
        s++;
        e--;
    }
    return v;
}
/*
approach-2
void reverseArray(vector<int> &arr, int m)
{
    int s = m + 1;
    int e = arr.size() - 1;

    while (s <= e)
    {
        swap(arr[s], arr[e]);
        s++;
        e--;
    }
}
*/
int main()
{
    vector<int> v;
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(40);
    v.push_back(50);
    cout << "Original Array ";
    for (int i : v)
    {
        cout << i << " ";
    }
    cout << endl;

    vector<int> ans = reverseArray(v);
    cout << "Reverse Array ";
    print(ans);
}
