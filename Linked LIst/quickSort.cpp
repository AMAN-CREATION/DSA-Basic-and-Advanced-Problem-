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

class Solution
{
public:
    Node *partition(Node *s, Node *e)
    {
        if (s == e)
            return s;

        Node *head = s;
        Node *temp = NULL;
        Node *prev = head;
        int value = head->data;
        while (prev != e)
        {
            temp = prev->next;
            if (temp == e)
                break;
            if (temp && temp->data < value)
            {
                prev->next = temp->next;
                temp->next = head;
                head = temp;
            }
            else
            {
                prev = temp;
            }
        }
        return head;
    }

    Node *quickSort(Node *s, Node *e)
    {
        if (s == e)
            return s;
        Node *head = partition(s, e);
        Node *h1 = quickSort(head, s);
        Node *h2 = quickSort(s->next, e);

        s->next = h2;

        return h1;
    }

    Node *sortList(Node *head)
    {
        return quickSort(head, NULL);
    }
};

int main()
{
    Node *head = NULL;

    push(head, 1);
    push(head, 3);
    push(head, 2);
    push(head, 6);
    push(head, 8);
    push(head, 5);
    push(head, 9);
    push(head, 10);
    push(head, 4);

    print(head);

    Solution obj;

    head = obj.sortList(head);
    print(head);
}