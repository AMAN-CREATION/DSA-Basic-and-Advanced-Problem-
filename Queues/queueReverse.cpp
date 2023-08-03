#include <bits/stdc++.h>
using namespace std;

queue<int> reverseQueue(queue<int> &q)
{
    stack<int> s;
    while (!q.empty())
    {
        int data = q.front();
        q.pop();
        s.push(data);
    }
    while (!s.empty())
    {
        int data = s.top();
        s.pop();
        q.push(data);
    }
    return q;
}

int main()
{
    queue<int> q;

    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);
    cout << "original queue ";
    while (!q.empty())
    {
        int p = q.front();
        q.pop();
        cout << p << " ";
    }
    cout << endl;
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);
    cout << "reverse queue ";

    reverseQueue(q);
    while (!q.empty())
    {
        int p = q.front();
        q.pop();
        cout << p << " ";
    }
}
