#include <bits/stdc++.h>
using namespace std;

int prefixEvaluation(string s)
{
    char n = s.size();
    stack<int> st;

    for (int i = n - 1; i >= 0; i--)
    {
        if (s[i] >= '0' && s[i] <= '9')
            st.push(s[i] - '0');

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

            case '%':
                st.push(a % b);
                break;
            }
        }
    }
    return st.top();
}

int main()
{
    cout << prefixEvaluation("-+7*45^20") << endl;
    return 0;
}