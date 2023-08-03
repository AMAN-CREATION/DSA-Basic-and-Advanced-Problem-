#include <iostream>
#include <stack>
using namespace std;

bool isValidParenthesis(string exp)
{
    stack<char> s;
    for (int i = 0; i < exp.length(); i++)
    {

        char ch = exp[i];

        //*if opening brackets->stack push
        //*if closing brackets->stack top and pop

        if (ch == '(' || ch == '{' || ch == '[')
        {
            s.push(ch);
        }
        else
        {
            // for closing bracket
            if (!s.empty())
            {
                char top = s.top();
                if ((ch == ')' && top == '(') ||
                    (ch == '}' && top == '{') ||
                    (ch == ']' && top == '['))
                {
                    s.pop();
                }
                else
                {
                    return false;
                }
            }
            else
            {
                return false;
            }
        }
    }
    //! after whole stack are empty;
    if (s.empty())
        return true;
    else
        return false;
}

int main()
{
    string exp = "{()}[]";

    if (isValidParenthesis(exp))
    {
        cout << "Balanced";
    }
    else
    {
        cout << " Not Balanced";
    }
}