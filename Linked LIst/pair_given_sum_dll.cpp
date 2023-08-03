#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *prev;
    Node(int d)
    {
        this->data = d;
        this->next = NULL;
        this->prev = NULL;
    }
};

Node *pairSum(Node *head, int x)
{
    Node *first = head;
    Node *second = head;

    //*set second pointer to end of the DLL;
    while (second->next != NULL)
    {
        second = second->next;
    }

    bool found = false;

    while (first != second && second->next != first)
    {
        if (first->data + second->data == x)
        {
            found = true;

            cout << first->data << " , " << second->data << endl;

            first = first->next;
            second = second->prev;
        }
        else
        {
            if (first->data + second->data < x)
            {
                first = first->next;
            }
            else
            {
                second = second->prev;
            }
        }
    }
    if (found == false)
        cout << " not found" << endl;

    return head;
}

void push(Node *&head, int d)
{
    Node *newNode = new Node(d);
    newNode->data = d;
    newNode->next = head;

    if (head != NULL)
        head->prev = newNode;

    head = newNode;
}
int main()
{
    Node *head = NULL;

    push(head, 9);
    push(head, 8);
    push(head, 7);
    push(head, 6);
    push(head, 5);
    push(head, 4);
    push(head, 2);
    push(head, 1);

    int x = 10;

    pairSum(head, x);
    return 0;
}