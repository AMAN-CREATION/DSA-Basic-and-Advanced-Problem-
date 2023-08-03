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

// program for sorted list
Node *uniqueSortedList(Node *head)
{
    // empty list
    if (head == NULL)
        return NULL;

    Node *curr = head;

    // non-empty list
    while (curr != NULL)
    {
        if ((curr->next != NULL) && curr->data == curr->next->data)
        {
            Node *next_next = curr->next->next;
            Node *nodeToDelete = curr->next;
            delete (nodeToDelete);
            curr->next = next_next;
        }
        else // non-empty
        {
            curr = curr->next;
        }
    }
    return head;
}

// program for unsorted list

Node *duplicateNode(Node *head)
{
    //! Approach-2 using hash map
    unordered_set<int> seen;

    Node *curr = head;
    Node *prev = NULL;

    while (curr != NULL)
    {
        // If current value is seen before
        if (seen.find(curr->data) != seen.end())
        {
            prev->next = curr->next;
            delete curr;
        }
        else
        {
            seen.insert(curr->data);
            prev = curr;
        }
        curr = prev->next;
    }
    return head;
}

void remove_duplicates(Node *head)
{

    //! Approach-1 using tow loops

    Node *curr = head;
    /* Pick elements one by one */
    while (curr != NULL && curr->next != NULL)
    {
        Node *temp = curr;
        /* Compare the picked element with the rest of the elements in the inner
         * loop. */
        while (temp->next != NULL)
        {
            /* If duplicate then delete it */
            if (curr->data == temp->next->data)
            {
                Node *nodeToDelete = temp->next;
                temp->next = temp->next->next;
                delete (nodeToDelete);
            }
            else /* if not duplicate move to next node */
                temp = temp->next;
        }
        curr = curr->next;
    }
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

void push(Node *&head, int newData)
{
    Node *new_node = new Node(newData);

    new_node->data = newData;
    new_node->next = head;

    head = new_node;
}

int main()
{
    Node *head = NULL;
    push(head, 10);
    push(head, 20);
    push(head, 30);
    push(head, 30);
    push(head, 40);
    push(head, 40);
    push(head, 50);

    cout << "Given LL ";
    print(head);

    head = uniqueSortedList(head);
    cout << "uniqueSortedList ";
    print(head);

    // remove_duplicates(head);
    // cout << "uniqueSortedList ";
    // print(head);

    return 0;
}
