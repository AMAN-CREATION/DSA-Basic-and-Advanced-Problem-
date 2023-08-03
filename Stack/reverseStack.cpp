#include <iostream>
#include <stack>
using namespace std;

void insertATBottom(stack<int> &s, int x)
{
    if (s.empty())
    {
        s.push(x);
        return;
    }
    int num = s.top();
    s.pop();

    insertATBottom(s, x);
    s.push(num);
}

void reverseStack(stack<int> &s)
{
    if (s.empty())
    {
        return;
    }
    int num = s.top();
    s.pop();

    reverseStack(s);

    insertATBottom(s, num);
}

int main()
{
    stack<int> st;

    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    st.push(50);

    cout << "Original Stack" << endl;
    while (!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }
    cout << endl;

    // function to reverse
    // the stack
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    st.push(50);
    reverseStack(st);
    cout << "Reversed Stack" << endl;
    // printing the stack after reversal
    while (!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }
    return 0;
}