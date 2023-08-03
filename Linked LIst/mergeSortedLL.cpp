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

Node *findMid(Node *head)
{
    if (head == NULL)
    {
        return NULL;
    }
    Node *slow = head;
    Node *fast = head->next;

    while (fast != NULL && fast->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}

Node *merge(Node *left, Node *right)
{
    if (left == NULL)
        return right;
    if (right == NULL)
        return left;

    Node *ans = new Node(-1);
    Node *temp = ans;

    // merge sorted LL
    while (left != NULL && right != NULL)
    {
        if (left->data < right->data)
        {
            temp->next = left;
            temp = left;
            left = left->next;
        }
        else
        {
            temp->next = right;
            temp = right;
            right = right->next;
        }
    }

    while (left != NULL)
    {
        temp->next = left;
        temp = left;
        left = left->next;
    }
    while (right != NULL)
    {
        temp->next = right;
        temp = right;
        right = right->next;
    }
    ans = ans->next;
    return ans;
}

Node *mergeSort(Node *head)
{
    // base case
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    // break LL into 2 halvs,after finding mid
    Node *middle = findMid(head);
    Node *left = head;
    Node *right = middle->next;
    middle->next = NULL;

    // recursive call to sort both halves
    left = mergeSort(left);
    right = mergeSort(right);

    // merge both left and right halves
    Node *result = merge(left, right);

    return result;
}

void push(Node *&head, int newData)
{
    Node *new_node = new Node(newData);

    new_node->data = newData;
    new_node->next = head;

    head = new_node;
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

    push(head, 8);
    push(head, 7);
    push(head, 4);
    push(head, 9);
    push(head, 3);
    push(head, 2);
    push(head, 1);
    push(head, 5);
    cout << "Given linked list ";
    printList(head);
    head = mergeSort(head);

    cout << "Reversed Linked list ";
    printList(head);
    return 0;
}