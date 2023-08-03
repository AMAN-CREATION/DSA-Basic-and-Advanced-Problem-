// C++ Program to convert decimal number to
// roman numerals
#include <bits/stdc++.h>
using namespace std;

string intToRoman(int num)
{
    int number[] = {1, 4, 5, 9, 10, 40, 50, 90, 100, 400, 500, 900, 1000};
    string sym[] = {"I", "IV", "V", "IX", "X", "XL", "L", "XC", "C", "CD", "D", "CM", "M"};
    int i = 12;
    while (num > 0)
    {
        int div = num / number[i];
        num = num % number[i];
        while (div--)
        {
            cout << sym[i];
        }
        i--;
    }
}

// Driver program
int main()
{
    int number = 3;

    intToRoman(number);

    return 0;
}
