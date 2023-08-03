#include <bits/stdc++.h>
using namespace std;

int evalRPN(string s)
{

    stack<int> st;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] >= '0' && s[i] <= '9')
        {
            st.push(s[i] - '0');
        }
        else
        {
            int a = st.top();
            st.pop();
            int b = st.top();
            st.pop();

            switch (s[i])
            {
            case '+':
                st.push(a + b);
                break;

            case '-':
                st.push(a - b);
                break;
            case '*':
                st.push(a * b);
                break;
            case '/':
                st.push(a / b);
                break;
            case '^':
                st.push(pow(a, b));
                break;
            }
        }
    }
    return st.top();
}

int main()
{
    cout << evalRPN("46+2/5*7+") << endl;
}