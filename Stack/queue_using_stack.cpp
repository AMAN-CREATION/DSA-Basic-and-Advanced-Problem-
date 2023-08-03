//! Implement Queue using Stacks

#include <bits/stdc++.h>
using namespace std;

class MyQueue
{
    stack<int> s1;
    stack<int> s2;

public:
    MyQueue()
    {
    }

    void push(int x)
    {
        s1.push(x);
    }

    int pop()
    {
        int i = peek();
        s2.pop();
        return i;
    }

    int peek()
    {
        if (s2.empty())
        {
            while (!s1.empty())
            {
                s2.push(s1.top());
                s1.pop();
            }
        }
        return s2.top();
    }

    bool empty()
    {
        return s1.empty() && s2.empty();
    }
};

class Queue
{
    stack<int> s1, s2;

public:
    void enqueue(int x)
    {
        while (!s1.empty())
        {
            s2.push(s1.top());
            s1.pop();
        }

        // Push item into s1
        s1.push(x);

        // Push everything back to s1
        while (!s2.empty())
        {
            s1.push(s2.top());
            s2.pop();
        }
    }
    int pop()
    {
        int i = dequeue();
        s2.pop();
        return i;
    }
    int dequeue()
    {
        // if first stack is empty
        if (s1.empty())
        {
            // this is print statement is temporary ;
            cout << "Q is Empty";
            exit(0);
        }

        // Return top of s1
        int x = s1.top();
        s1.pop();
        return x;
    }
    bool empty()
    {
        return s1.empty() && s2.empty();
    }
};

// int main()
// {
//     Queue q;
//     q.enqueue(10);
//     q.enqueue(20);
//     q.enqueue(30);
//     q.enqueue(40);
//     q.pop();
//     cout << q.dequeue();
//     cout<<endl;

//     if (q.empty())
//         cout << "true";
//     else
//         cout << "false";
// }

int main()
{
    MyQueue q;
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.pop();

    cout << q.peek();
    if (q.empty())
        cout << "true";
    else
        cout << "false";
}