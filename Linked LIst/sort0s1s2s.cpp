#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int d)
    {
        this->data = d;
        this->next = NULL;
    }
};

//! Approach-1 replacing data

Node *sort012(Node *head)
{
    int oneCount = 0;
    int zeroCount = 0;
    int twoCount = 0;

    Node *temp = head;

    while (temp != NULL)
    {
        if (temp->data == 0)
            zeroCount++;
        else if (temp->data == 1)
            oneCount++;
        else if (temp->data == 2)
            twoCount++;

        temp = temp->next;
    }

    temp = head;
    while (temp != NULL)
    {
        if (zeroCount != 0)
        {
            temp->data = 0;
            zeroCount--;
        }
        else if (oneCount != 0)
        {
            temp->data = 1;
            oneCount--;
        }
        else if (twoCount != 0)
        {
            temp->data = 2;
            twoCount--;
        }
        temp = temp->next;
    }

    return head;
}

//! Approach -2 if data cant not be replace
void insertAtTail(Node *&tail, Node *curr)
{
    tail->next = curr;
    tail = curr;
}
Node *sortList(Node *head)
{
    Node *zeroHead = new Node(-1);
    Node *zeroTail = zeroHead;
    Node *oneHead = new Node(-1);
    Node *oneTail = oneHead;
    Node *twoHead = new Node(-1);
    Node *twoTail = twoHead;

    Node *curr = head;

    // create separate list 0s, 1s and 2s
    while (curr != NULL)
    {

        int value = curr->data;

        if (value == 0)
        {
            insertAtTail(zeroTail, curr);
        }
        else if (value == 1)
        {
            insertAtTail(oneTail, curr);
        }
        else if (value == 2)
        {
            insertAtTail(twoTail, curr);
        }
        curr = curr->next;
    }

    // merge 3 sublist

    // 1s list not empty
    if (oneHead->next != NULL)
    {
        zeroTail->next = oneHead->next;
    }
    else
    {
        // 1s list -> empty
        zeroTail->next = twoHead->next;
    }

    oneTail->next = twoHead->next;
    twoTail->next = NULL;

    // setup head
    head = zeroHead->next;

    // delete dummy nodes
    delete zeroHead;
    delete oneHead;
    delete twoHead;

    return head;
}
void push(Node *&head, int data)
{
    // allocating space
    Node *newNode = new Node(data);

    // inserting the required data
    newNode->data = data;
    newNode->next = head;

    head = newNode;
}

/* Function to print linked list */
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

/* Driver program to test above function*/
int main(void)
{
    Node *head = NULL;

    push(head, 0);
    push(head, 2);
    push(head, 1);
    push(head, 2);
    push(head, 1);
    push(head, 0);
    push(head, 2);

    printf("Linked List Before Sorting\n");
    printList(head);

    head = sortList(head);

    printf("Linked List After Sorting\n");
    printList(head);

    return 0;
}