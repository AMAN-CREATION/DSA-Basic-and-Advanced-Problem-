#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *child;

    Node(int d)
    {
        this->data = d;
        this->next = NULL;
        this->child = NULL;
    }
};
Node *head = NULL;

Node *merge(Node *down, Node *right)
{
    // If first linked list is empty then second
    if (down == NULL)
        return right;

    // If second linked list is empty then first
    if (right == NULL)
        return down;

    // Compare the data members of the two linked
    Node *temp = NULL;

    if (down->data < right->data)
    {
        temp = down;
        temp->child = merge(down->child, right);
    }
    else
    {
        temp = right;
        temp->child = merge(down, right->child);
    }
    temp->next = NULL;
    return temp;
}

Node *flattenLL(Node *head)
{
    // base case
    if (head == NULL || head->next == NULL)
    {
        return head;
    }

    // recur for list on right
    head->next = flattenLL(head->next);

    // merge
    head = merge(head, head->next);

    return head;
}

Node *push(Node *head, int newData)
{
    Node *new_node = new Node(newData);

    new_node->data = newData;
    new_node->next = NULL;
    new_node->child = head;

    head = new_node;

    return head;
}

void printList()
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->child;
    }
    cout << endl;
}

int main()
{

    /* Let us create the following linked list
        5 -> 10 -> 19 -> 28
        | |	 |	 |
        V V	 V	 V
        7 20 22 35
        |		 |	 |
        V		 V	 V
        8		 50 40
        |			 |
        V			 V
        30			 45
    */

    head = push(head, 30);
    head = push(head, 8);
    head = push(head, 7);
    head = push(head, 5);

    head->next = push(head->next, 20);
    head->next = push(head->next, 10);

    head->next->next = push(head->next->next, 50);
    head->next->next = push(head->next->next, 22);
    head->next->next = push(head->next->next, 19);
    push(head->next->next->next, 45);

    head->next->next->next = push(head->next->next->next, 40);
    head->next->next->next = push(head->next->next->next, 35);
    head->next->next->next = push(head->next->next->next, 28);

    head = flattenLL(head);

    printList();

    return 0;
}