#include <iostream>
#include <stack>
using namespace std;

void solve(stack<int> &inputStack, int count, int size)
{
    if (count == size / 2)
    {
        inputStack.pop();
        return;
    }
    int num = inputStack.top();
    inputStack.pop();

    solve(inputStack, count + 1, size);

    inputStack.push(num);
}

void deleteMiddle(stack<int> &inputStack, int n)
{
    int count = 0;
    solve(inputStack, count, n);
}

int main()
{
    stack<int> st;

    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);
    st.push(6);

    deleteMiddle(st, st.size());

    while (!st.empty())
    {
        int p = st.top();
        st.pop();
        cout << p << " ";
    }
    return 0;
}