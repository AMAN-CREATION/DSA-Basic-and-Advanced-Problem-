#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
};

void moveToFront(Node *&head)
{

    if (head == NULL || head->next == NULL)
        return;

    Node *secLast = NULL;
    Node *last = head;

    while (last->next != NULL)
    {
        secLast = last;
        last = last->next;
    }

    secLast->next = NULL;

    last->next = head;

    head = last;
}

void push(Node *&head, int newData)
{
    Node *new_node = new Node();

    new_node->data = newData;
    new_node->next = head;

    head = new_node;
}

/* Function to print nodes in a given linked list */
void printList(Node *&head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

// Driver's code
int main()
{
    Node *head = NULL;

    /* The constructed linked list is:
    1->2->3->4->5 */
    push(head, 5);
    push(head, 4);
    push(head, 3);
    push(head, 2);
    push(head, 1);

    cout << "Linked list before moving last to front\n";
    printList(head);

    // Function call
    moveToFront(head);

    cout << "\nLinked list after removing last to front\n";
    printList(head);

    return 0;
}

// This code is contributed by rathbhupendra
