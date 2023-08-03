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

void push(Node *&head, int newData)
{
    Node *newNode = new Node(newData);
    newNode->data = newData;
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

Node *solve(Node *&list1, Node *&list2)
{
    if (list1->next == NULL)
    {
        list1->next = list2;
        return list1;
    }

    Node *curr1 = list1;
    Node *next1 = curr1->next;
    Node *curr2 = list2;
    Node *next2 = curr2->next;

    while (next1 != NULL && curr2 != NULL)
    {
        if ((curr1->data <= curr2->data) && (curr2->data <= next1->data))
        {
            // adding node in between the first list;
            curr1->next = curr2;
            next2 = curr2->next;
            curr2->next = next1;

            // update pointer;
            curr1 = curr2;
            curr2 = next2;
        }
        else
        {
            curr1 = next1;
            next1 = next1->next;

            if (next1 == NULL)
            {
                curr1->next = curr2;
                return list1;
            }
        }
    }
    return list1;
}

Node *mergeTwoSortedLL(Node *list1, Node *list2)
{
    if (list1 == NULL)
        return list2;

    if (list2 == NULL)
        return list2;

    if (list1->data <= list2->data)
    {
        return solve(list1, list2);
    }
    else
    {
        return solve(list2, list1);
    }
}

int main()
{
    int n, m;
    cin >> n >> m;

    int data;
    cin >> data;

    Node *head1 = new Node(data);
    Node *tail1 = head1;

    for (int i = 1; i < n; i++)
    {
        cin >> data;
        tail1->next = new Node(data);
        tail1 = tail1->next;
    }
    cin >> data;
    Node *head2 = new Node(data);
    Node *tail2 = head2;

    for (int i = 1; i < m; i++)
    {
        cin >> data;
        tail2->next = new Node(data);
        tail2 = tail2->next;
    }
    Node *head = mergeTwoSortedLL(head1, head2);
    print(head);
}
