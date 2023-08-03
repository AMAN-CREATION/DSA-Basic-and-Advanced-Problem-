#include <bits/stdc++.h>
using namespace std;

class Queue
{

    int *arr;
    int size;
    int qFront;
    int rear;

public:
    Queue()
    {
        size == 100001;
        arr = new int[size];
        qFront = 0;
        rear = 0;
    }

    void enqueue(int data)
    {
        if (rear == size)
        {
            cout << "queue is full " << endl;
        }
        else
        {
            arr[rear] = data;
            rear++;
        }
    }

    int dequeue()
    {
        if (qFront == rear)
        {
            return -1;
        }
        else
        {
            int ans = arr[qFront];
            arr[qFront] = -1;
            qFront++;
            if (qFront == rear)
            {
                qFront = 0;
                rear = 0;
            }
            return ans;
        }
    }

    int front()
    {
        if (qFront == rear)
            return -1;
        else
            return arr[qFront];
    }

    bool empty()
    {
        if (qFront == rear)
            return true;
        else
            return false;
    }
};

int main()
{
    Queue q;

    q.enqueue(15);
    q.enqueue(13);
    q.enqueue(10);

    cout << q.front() << endl;

    q.dequeue();
    cout << q.front() << endl;

    if (q.empty())
        cout
            << "queue is empty";
    else
        cout << "queue is not empty";
}