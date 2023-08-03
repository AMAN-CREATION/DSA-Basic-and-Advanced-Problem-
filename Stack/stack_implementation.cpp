#include <iostream>
using namespace std;

//! Stack Implementation with array.
class Stack
{
    //* properties
public:
    int *arr;
    int top;
    int size;
    // * behaviour
    Stack(int size)
    {
        this->size = size;
        arr = new int[size];
        top = -1;
    }

    void push(int element)
    {
        if (size - top > 1)
        {
            top++;
            arr[top] = element;
        }
        else
        {
            cout << "Stack OverFlow" << endl;
        }
    }
    void pop()
    {
        if (top >= 0)
        {
            top--;
        }
        else
        {
            cout << "Stack UnderFlow" << endl;
        }
    }
    int peek()
    {
        if (top >= 0)
            return arr[top];
        else
        {
            cout << "Stack is Empty" << endl;
            return -1;
        }
    }

    bool isEmpty()
    {
        if (top == -1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};

//! Stack Implementation using linked list

class Node
{
public:
    int data;
    Node *next;

    //*constructor
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

class Stack1
{
    Node *top;

public:
    //* constructor
    Stack1()
    {
        top = NULL;
    }

    void push(int element)
    {
        Node *temp = new Node(element);

        //*check is stack heap is full.
        if (!temp)
        {
            cout << "Stack overflow" << endl;
            exit(1);
        }
        temp->data = element;

        temp->next = top;

        top = temp;
    }

    bool isEmpty()
    {
        return top == NULL;
    }
    int peek()
    {
        if (!isEmpty())
            return top->data;
        else
            cout << "stack is empty";
        return -1;
    }

    void pop()
    {
        Node *temp;

        if (top == NULL)
        {
            cout << "stack underflow" << endl;
            exit(1);
        }
        else
        {
            temp = top;

            top = top->next;

            free(temp);
        }
    }

    void display()
    {
        Node *temp;

        if (top == NULL)
        {
            cout << "stack is underflow" << endl;
            exit(1);
        }
        else
        {
            temp = top;
            while (temp != NULL)
            {
                cout << temp->data;
                temp = temp->next;
                cout << endl;
            }
        }
    }
};

int main()
{
    Stack1 st;

    st.push(22);
    st.push(11);
    st.push(41);

    st.pop();
    st.pop();
    st.pop();
    st.display();

    // cout << st.peek() << endl;

    if (st.isEmpty())
        cout << "stack is empty";
    else
        cout << "stack is  not empty";
}