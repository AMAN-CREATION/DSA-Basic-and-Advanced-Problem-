
#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *prev;
};

void reverse(Node *&head)
{
    Node *temp = NULL;
    Node *curr = head;

    // swapping next and prev
    while (curr != NULL)
    {
        temp = curr->prev;
        curr->prev = curr->next;
        curr->next = temp;
        curr = curr->prev;
    }

    // check empty list and list with only one node
    if (temp != NULL)
        head = temp->prev;
}

void push(Node *&head, int newData)
{
    Node *newNode = new Node();

    newNode->data = newData;
    newNode->prev = NULL;
    newNode->next = head;

    if (head != NULL)
        head->prev = newNode;

    head = newNode;
}

void printList(Node *&head)
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

    push(head, 2);
    push(head, 4);
    push(head, 8);
    push(head, 10);

    cout << "Original Linked list" << endl;
    printList(head);

    reverse(head);

    cout << "\nReversed Linked list" << endl;
    printList(head);

    return 0;
}

// Time Complexity : O(N)
// Auxiliary Space : O(1)
