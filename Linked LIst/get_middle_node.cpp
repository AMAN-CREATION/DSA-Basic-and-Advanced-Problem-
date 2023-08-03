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
void print(Node *head)
{

    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

//! Approach -1
/*
int getLength(Node *head)
{
    int len = 0;
    Node *temp = head;
    while (temp != NULL)
    {
        len++;
        temp = temp->next;
    }
    return len;
}

Node *middleNode(Node *head)
{
    int len = getLength(head);
    int ans = len / 2;

    Node *temp = head;
    int cnt = 0;
    while (cnt < ans)
    {
        temp = temp->next;
        cnt++;
    }
    return temp;
}
*/

//! Approach-2

Node *middleNode(Node *head)
{
    if (head == NULL || head->next == NULL)
        return head;

    if (head->next->next == NULL)
        return head->next;

    Node *slow = head;
    Node *fast = head->next;

    while (fast != NULL && fast->next != NULL)
    {
        // fast = fast->next;
        fast = fast->next->next;

        // if (fast != NULL)
        // {
        //     fast = fast->next;
        // }
        slow = slow->next;
    }
    return slow;
}

int main()
{
    int n;
    cin >> n;
    int data;
    cin >> data;
    Node *head = new Node(data);
    Node *tail = head;
    for (int i = 0; i < n - 1; i++)
    {
        cin >> data;
        tail->next = new Node(data);
        tail = tail->next;
    }
    Node *res = middleNode(head);
    print(res);
}