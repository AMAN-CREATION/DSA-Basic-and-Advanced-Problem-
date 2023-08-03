#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *prev;
    Node *next;

    // constructor
    Node(int d)
    {
        this->data = d;
        this->prev = NULL;
        this->next = NULL;
    }

    ~Node()
    {
        int val = this->data;
        if (next != NULL)
        {
            delete next;
            next = NULL;
        }
        cout << "memory free for node with data " << val << endl;
    }
};

// traversing a linked list
void print(Node *head)
{
    Node *temp = head;

    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// gives length of Linked List
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
void insertAtHead(Node *&tail, Node *&head, int d)
{

    // empty list
    if (head == NULL)
    {
        Node *temp = new Node(d);
        head = temp;
        tail = temp;
    }
    else
    {
        Node *temp = new Node(d);
        temp->next = head;
        head->prev = temp;
        head = temp;
    }
}

void insertAtTail(Node *&tail, Node *&head, int d)
{
    if (tail == NULL)
    {
        Node *temp = new Node(d);
        tail = temp;
        head = temp;
    }
    else
    {
        Node *temp = new Node(d);
        tail->next = temp;
        temp->prev = tail;
        tail = temp;
    }
}

void insertAtPosition(Node *&tail, Node *&head, int position, int d)
{

    // insert at Start
    if (position == 1)
    {
        insertAtHead(tail, head, d);
        return;
    }

    Node *temp = head;
    int cnt = 1;

    while (cnt < position - 1)
    {
        temp = temp->next;
        cnt++;
    }

    // inserting at Last Position
    if (temp->next == NULL)
    {
        insertAtTail(tail, head, d);
        return;
    }

    // creating a node for d
    Node *nodeToInsert = new Node(d);

    nodeToInsert->next = temp->next;
    temp->next->prev = nodeToInsert;
    temp->next = nodeToInsert;
    nodeToInsert->prev = temp;
}

void deleteNode(int position, Node *&head)
{

    // deleting first or start node
    if (position == 1)
    {
        Node *temp = head;
        temp->next->prev = NULL;
        head = temp->next;
        temp->next = NULL;
        delete temp;
    }
    else
    {
        // deleting any middle node or last node
        Node *curr = head;
        Node *prev = NULL;

        int cnt = 1;
        while (cnt < position)
        {
            prev = curr;
            curr = curr->next;
            cnt++;
        }

        curr->prev = NULL;
        prev->next = curr->next;
        curr->next = NULL;

        delete curr;
    }
}

bool isCircular(Node *head)
{
    if (head == NULL)
        return true;

    Node *temp = head->next;
    while (temp != NULL && temp != head)
    {
        temp = temp->next;
    }
    if (temp == head)
        return true;

    return false;
}
bool detectLoop(Node *head)
{
    if (head == NULL)
        return NULL;

    map<Node *, bool> visited;
    Node *temp = head;
    while (temp != NULL)
    {
        if (visited[temp] == true)
        {
            return true;
        }
        visited[temp] = true;
        temp = temp->next;
    }
    return false;
}

Node *floydDetectLoop(Node *head)
{
    if (head == NULL)
        return NULL;

    Node *slow = head;
    Node *fast = head;

    while (slow != NULL && fast != NULL)
    {
        fast = fast->next;
        if (fast != NULL)
        {
            fast = fast->next;
        }
        slow = slow->next;

        if (slow == fast)
            return slow;
    }
    return NULL;
}

Node *getStartingNode(Node *head)
{
    if (head == NULL)
        return NULL;

    Node *intersection = floydDetectLoop(head);
    Node *slow = head;

    while (slow != intersection)
    {
        slow = slow->next;
        intersection = intersection->next;
    }
    return slow;
}

Node *removeLoop(Node *head)
{
    if (head == NULL)
        return head;

    Node *startedLoop = getStartingNode(head);
    Node *temp = startedLoop;
    while (temp->next != startedLoop)
    {
        temp = temp->next;
    }
    temp->next = NULL;
}

int main()
{
    // Node *node1 = new Node(10);
    Node *head = NULL;
    Node *tail = NULL;

    insertAtHead(tail, head, 12);
    insertAtHead(tail, head, 10);
    // print(head);

    insertAtTail(tail, head, 15);
    // print(head);

    insertAtPosition(tail, head, 4, 22);
    print(head);

    // cout << getLength(head) << endl;

    // deleteNode(4, head);
    // print(head);

    // if (isCircular(head))
    //     cout << "list is circular" << endl;
    // else
    //     cout << "list is not circular" << endl;

    tail->next = head->next;

    Node *loop = getStartingNode(head);
    cout << "loop start at " << loop->data << endl;

    removeLoop(head);
    print(head);

    if (floydDetectLoop(head) != NULL)
        cout << "loop is present" << endl;
    else
        cout << "loop is not present" << endl;

    // if (detectLoop(head))
    //     cout << "loop is present" << endl;
    // else
    //     cout << "loop is not present" << endl;
}