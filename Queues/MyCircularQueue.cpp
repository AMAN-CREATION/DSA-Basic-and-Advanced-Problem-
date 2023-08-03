#include <bits/stdc++.h>
using namespace std;

//! using with array
class MyCircularQueue1
{
public:
    int *arr;
    int front;
    int rear;
    int size;
    MyCircularQueue1(int k)
    {
        arr = new int[k];
        front = -1;
        rear = -1;
        size = k;
    }
    bool enQueue(int value)
    {
        // if queue is full
        if (isFull())
            return false;

        // if queue is empty
        if (isEmpty())
            front = 0;

        // insert single elements
        rear = (rear + 1) % size;
        arr[rear] = value;
        return true;
    }
    bool deQueue()
    {
        // to check queue is full
        if (isEmpty())
            return false;
        // if single element is present
        if (front == rear)
            front = rear = -1;
        else
            front = (front + 1) % size;
        return true;
    }
    int Front()
    {
        if (isEmpty())
            return -1;
        return arr[front];
    }
    int Rear()
    {
        if (isEmpty())
            return -1;
        return arr[rear];
    }
    bool isEmpty()
    {
        return front == -1;
    }
    bool isFull()
    {
        return ((rear + 1) % size) == front;
    }
};
class Node
{
public:
    int data;
    Node *next;
    Node *prev;
    Node(int data)
    {
        this->data = data;
        next = NULL;
        prev = NULL;
    }
};
//! using linked List
class MyCircularQueue2
{
private:
    Node *head;
    Node *tail;
    int size;

public:
    MyCircularQueue2(int k)
    {
        size = k;
        head = new Node(0);
        tail = new Node(0);
        head->next = tail;
        tail->prev = head;
    }

    bool enQueue(int value)
    {
        if (isFull())
            return false;
        Node *temp = new Node(value);
        temp->next = tail;
        temp->prev = tail->prev;
        tail->prev->next = temp;
        tail->prev = temp;
        size--;
        return true;
    }

    bool deQueue()
    {
        if (isEmpty())
            return false;
        Node *temp = head->next;
        head->next = head->next->next;
        head->next->prev = head;
        delete temp;
        size++;
        return true;
    }

    int Front()
    {
        if (isEmpty())
            return -1;
        return head->next->data;
    }

    int Rear()
    {
        if (isEmpty())
            return -1;
        return tail->prev->data;
    }

    bool isEmpty()
    {
        if (head->next == tail)
            return true;
        return false;
    }

    bool isFull()
    {
        if (size == 0)
            return true;
        return false;
    }
};

int main()
{
    MyCircularQueue1 q(5);

    q.enQueue(23);
    q.enQueue(11);
    q.enQueue(5);

    q.deQueue();
    cout << q.Front() << endl;

    if (q.isEmpty())
        cout << "queue is empty";
    else
        cout << "queue is not empty";
}