
#include <iostream>
#include <stack>
using namespace std;

void sortedInsert(stack<int> &s, int n)
{
    if (s.empty() || (!s.empty() && s.top() < n))
    {
        s.push(n);
        return;
    }
    int num = s.top();
    s.pop();

    sortedInsert(s, n);
    s.push(num);
}

void sortStack(stack<int> &s)
{
    if (s.empty())
    {
        return;
    }
    int n = s.top();
    s.pop();

    sortStack(s);
    sortedInsert(s, n);
}

int main()
{
    stack<int> st;
    st.push(9);
    st.push(7);
    st.push(2);
    st.push(5);
    st.push(-2);

    cout << "original stack ";
    while (!st.empty())
    {
        int p = st.top();
        st.pop();
        cout << p << " ";
    }
    cout << endl;

    st.push(9);
    st.push(7);
    st.push(2);
    st.push(5);
    st.push(-2);
    cout << "sorted stack ";
    sortStack(st);
    while (!st.empty())
    {
        int p = st.top();
        st.pop();
        cout << p << " ";
    }
}