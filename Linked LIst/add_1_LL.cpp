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

Node *reverse(Node *head)
{
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
}
Node *addOneUnit(Node *head)
{
    Node *res = head;
    Node *temp = NULL;
    int carry = 1;

    while (head != NULL)
    {
        int sum = carry + head->data;
        carry = (sum >= 10) ? 1 : 0;
        sum = sum % 10;
        head->data = sum;
        temp = head;
        head = head->next;
    }
    if (carry > 0)
    {
        temp->next = new Node(carry);
    }
    return res;
}

Node *addOne(Node *head)
{
    head = reverse(head);

    Node *ans = addOneUnit(head);

    ans = reverse(head);

    return ans;
}

int main()
{
    Node *head = NULL;

    push(head, 9);
    push(head, 9);
    push(head, 9);
    push(head, 1);

    print(head);

    head = addOne(head);

    print(head);
}