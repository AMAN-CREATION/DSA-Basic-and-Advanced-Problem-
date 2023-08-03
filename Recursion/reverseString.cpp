// #include <iostream>
// using namespace std;

// void reverse(string &str, int i ,int j)
// {
//     if (i > j)
//     {
//         return;
//     }
//     swap(str[i], str[j]);
//     i++;
// j++
//     reverse(str, i,j);
// }

// int main()
// {
//     string name = "aman";

//     reverse(name, 0, name.length() - 1);
//     cout << name;
// }

// using single pointer
#include <bits/stdc++.h>

using namespace std;

string reverse(string str, int n)
{
    if (n == 0)
        return " ";
    return str[n - 1] + reverse(str, n - 1);
}

int main()
{

    string str;
    cin >> str;
    cout << reverse(str, str.size()) << endl;
}