// !Implement Stack using Queues

#include <bits/stdc++.h>
using namespace std;

class MyStack
{
    queue<int> q;

public:
    MyStack()
    {
    }

    void push(int x)
    {
        q.push(x);
        for (int i = 0; i < q.size() - 1; i++)
        {
            q.push(q.front());
            q.pop();
        }
    }

    int pop()
    {
        int temp = q.front();
        q.pop();
        return temp;
    }

    int top()
    {
        if (q.empty())
            return -1;
        return q.front();
    }

    bool empty()
    {
        return q.empty();
    }
};

int main()
{
    MyStack s;
    // s.push(10);
    // s.push(20);
    // s.push(30);
    // s.push(40);
    // s.pop();

    cout << s.top() << endl;

    if (s.empty())
        cout << "stack is empty";
    else
        cout << "stack is not empty";
}