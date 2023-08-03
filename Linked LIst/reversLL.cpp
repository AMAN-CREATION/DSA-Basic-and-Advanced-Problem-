#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

//! Approach - 3 using recursion
Node *reverse1(Node *head)
{
    if (head == NULL || head->next == NULL)
        return head;

    Node *smallHead = reverse1(head->next);
    head->next->next = head;
    head->next = NULL;
    return smallHead;
}

//! Approach - 2 using recursion
void reverse(Node *&head, Node *curr, Node *prev)
{
    // base case;
    if (curr == NULL)
    {
        head = prev;
        return;
    }

    Node *forward = curr->next;
    reverse(head, forward, curr);
    curr->next = prev;
}

Node *reverseLinkedList(Node *head)
{
    //*Approach- 3 recursively
    reverse1(head);

    //* Approach-2 recursively
    /*
    Node *curr = head;
    Node *prev = NULL;
    reverse(head, curr, prev);
    return head;
    */

    //* Approach - 1 Iteratively
    /*

        if (head == NULL || head->next == NULL)
            return head;

        Node *curr = head;
        Node *prev = NULL;
        Node *forward = NULL;

        while (curr != NULL)
        {
            forward = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forward;
        }
        return prev;
        */
}

void push(Node *&head, int val)
{
    Node *newNode = new Node(val);
    newNode->data = val;
    newNode->next = head;
    head = newNode;
}

void print(Node *&head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main()
{
    Node *head = NULL;

    push(head, 12);
    push(head, 10);
    push(head, 15);
    push(head, 22);
    push(head, 25);

    cout << "Given LL ";
    print(head);

    cout << "Reverse LL ";
    head = reverseLinkedList(head);
    print(head);
}