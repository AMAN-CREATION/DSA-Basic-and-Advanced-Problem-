#include <bits/stdc++.h>
using namespace std;

void reverse(char name[], int n)
{
    int s = 0;
    int e = n - 1;
    while (s <= e)
    {
        swap(name[s++], name[e--]);
    }
}
int getLength(char name[])
{
    int count = 0;
    for (int i = 0; name[i] != '\0'; i++)
    {
        count++;
    }
    return count;
}

// int main()
// {
//     char name[100];
//     cin >> name;
//     int len = getLength(name);

//     reverse(name, len);
//     cout << name << endl;
// }

void reverseString(vector<char> &s)
{
    int st = 0;
    int e = s.size() - 1;
    while (st < e)
    {
        swap(s[st++], s[e--]);
    }
}
