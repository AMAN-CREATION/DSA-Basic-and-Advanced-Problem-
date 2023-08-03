#include <bits/stdc++.h>
using namespace std;

int main()
{
    int arr[100], n;
    cout << "enter number of element " << endl;
    cin >> n;
    cout << "enter element" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    //*this loop pick the element one by one
    for (int i = 0; i < n; i++)
        //*this loop check the element is not repeated
        for (int j = i + 1; j < n; j++)
            if (arr[i] == arr[j])
            {
                cout << "first repeating integer is " << arr[i];
                return 0;
            }
    cout << "no integer repeated ";
    return 0;
}