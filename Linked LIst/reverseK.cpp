#include <iostream>
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

class Solution
{
public:
    int count1 = 0;
    int length(Node *head)
    {
        int ans = 0;
        Node *temp = head;
        while (temp != NULL)
        {
            ans++;
            temp = temp->next;
        }
        return ans;
    }
    Node *reverseKGroup(Node *head, int k)
    {
        if (head == NULL)
        {
            return NULL;
        }
        count1 = length(head);
        if (count1 < k)
            return head;
        Node *curr = head;
        Node *next = NULL;
        Node *prev = NULL;
        int count = 0;
        while (count < k && curr != NULL)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            count++;
        }
        if (next != NULL)
        {
            head->next = reverseKGroup(next, k);
        }
        return prev;
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

// when data not be replace

int main()
{
    Node *head = NULL;

    push(head, 3);

    push(head, 5);

    push(head, 2);

    push(head, 7);

    push(head, 8);

    push(head, 3);

    cout << "Given LL ";
    print(head);
    int k;
    cin >> k;

    Solution obj;

    head = obj.reverseKGroup(head, k);

    print(head);
}
