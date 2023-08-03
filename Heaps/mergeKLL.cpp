#include <bits/stdc++.h>
using namespace std;

//! optimize solution 2
// Expected Time Complexity: O(nk Logk)
// Expected Auxiliary Space: O(k)

class Node
{
public:
    int data;
    Node *next;
    Node(int d)
    {
        data = d;
        next = NULL;
    }
};

class compare
{
public:
    bool operator()(Node *a, Node *b)
    {
        return a->data > b->data;
    }
};

Node *mergeKList(vector<Node *> &list)
{
    priority_queue<Node *, vector<Node *>, compare> minHeap;
    int k = list.size();

    if (k == 0)
        return NULL;

    for (int i = 0; i < k; i++)
    {
        if (list[i] != NULL)
            minHeap.push(list[i]);
    }

    Node *head = NULL;
    Node *tail = NULL;

    while (!minHeap.empty())
    {
        Node *top = minHeap.top();
        minHeap.pop();

        if (top->next != NULL)
            minHeap.push(top->next);

        if (head == NULL)
        {
            head = top;
            tail = top;
        }
        else
        {
            tail->next = top;
            tail = top;
        }
    }
    return head;
}
void printList(Node *node)
{
    while (node != NULL)
    {
        cout << node->data << " ";
        node = node->next;
    }
}
Node *newNode(int data)
{
    struct Node *temp = new Node(data);
    temp->data = data;
    temp->next = NULL;
    return temp;
}
int main()
{

    int k = 3;
    int n = 4;
    vector<Node *> arr(k);

    arr[0] = newNode(1);
    arr[0]->next = newNode(3);
    arr[0]->next->next = newNode(5);
    arr[0]->next->next->next = newNode(7);

    arr[1] = newNode(2);
    arr[1]->next = newNode(4);
    arr[1]->next->next = newNode(6);
    arr[1]->next->next->next = newNode(8);
    arr[1]->next->next->next->next = newNode(8);

    arr[2] = newNode(0);
    arr[2]->next = newNode(9);
    arr[2]->next->next = newNode(10);
    arr[2]->next->next->next = newNode(11);

    // Merge all lists
    Node *head = mergeKList(arr);

    printList(head);
}
/*
//*solution 1
ListNode *mergeKLists(vector<ListNode *> &lists)
{
    vector<int> v;
    for (int i = 0; i < lists.size(); i++)
    {
        while (lists[i])
        {
            v.push_back(lists[i]->val);
            lists[i] = lists[i]->next;
        }
    }
    sort(rbegin(v), rend(v));
    ListNode *ans = NULL;
    for (int i = 0; i < v.size(); i++)
        ans = new ListNode(v[i], ans);

    return ans;
}
*/
