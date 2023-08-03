#include <iostream>
#include <map>
using namespace std;

class Node
{

public:
    int data;
    Node *next;

    // constructor
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }

    // destructor
    ~Node()
    {
        int value = this->data;
        // memory free
        if (this->next != NULL)
        {
            delete next;
            this->next = NULL;
        }
        cout << " memory is free for node with data " << value << endl;
    }
};

void insertNode(Node *&tail, int element, int d)
{
    // empty list
    if (tail == NULL)
    {
        Node *newNode = new Node(d);
        tail = newNode;
        newNode->next = newNode;
    }
    else
    {
        // non-empyt list
        Node *curr = tail;
        while (curr->data != element)
        {
            curr = curr->next;
        }
        Node *temp = new Node(d);
        temp->next = curr->next;
        curr->next = temp;
    }
}
void print(Node *&tail)
{
    Node *temp = tail;
    if (tail == NULL)
    {
        cout << "list is empty" << endl;
        return;
    }

    do
    {
        cout << tail->data << " ";
        tail = tail->next;
    } while (tail != temp);
    cout << endl;
}

void deleteNode(Node *&tail, int value)
{
    if (tail == NULL)
    {
        cout << "List is empty,please check again" << endl;
        return;
    }
    else
    {
        Node *prev = tail;
        Node *curr = prev->next;

        while (curr->data != value)
        {
            prev = curr;
            curr = curr->next;
        }
        prev->next = curr->next;

        // 1 node linked list
        if (curr == prev)
        {
            tail = NULL;
        }
        //=>2 linked list
        if (tail == curr)
        {
            tail = prev;
        }

        curr->next = NULL;
        delete curr;
    }
}

bool isCircularList(Node *&head)
{
    // empty list
    if (head == NULL)
    {
        return true;
    }
    Node *temp = head->next;
    while (temp != NULL && temp != head)
    {
        temp = temp->next;
    }
    if (temp == head)
    {
        return true;
    }

    return false;
}

// !Approach-1
bool detectLoop(Node *&head)
{
    if (head == NULL)
    {
        return false;
    }
    map<Node *, bool> visited;
    Node *temp = head;
    while (temp != NULL)
    {
        if (visited[temp] == true)
        {
            cout << "Present on element" << temp->data << endl;
            return true;
        }
        visited[temp] = true;
        temp = temp->next;
        cout << "Present on element" << temp->data << endl;
    }
    return false;
}

//! Approach-2
Node *floydDetectLoop(Node *head)
{
    if (head == NULL)
        return NULL; // false

    Node *slow = head;
    Node *fast = head;
    while (slow != NULL && fast != NULL)
    {
        fast = fast->next;
        if (fast != NULL)
            fast = fast->next;

        if (slow == fast)
        {
            cout << slow->data << endl;
            return slow; // true
        }
    }
    return NULL; // false
}

int main()
{
    Node *tail = NULL;
    Node *head = NULL;

    insertNode(tail, 5, 3);

    insertNode(tail, 3, 5);

    insertNode(tail, 5, 7);
    insertNode(tail, 7, 9);
    insertNode(tail, 9, 11);
    print(tail);

    // cout << "tail " << tail->data << endl;
    // tail->next = tail->next;

    // cout << "head " << head->data << endl;
    // cout << "tail " << tail->data << endl;
    // print(head);

    if (floydDetectLoop(tail) != NULL)
    {
        cout << "loop is present" << endl;
    }
    else
    {
        cout << "loop is not present" << endl;
    }
    // if (detectLoop(tail))
    // {
    //     cout << "loop is present" << endl;
    // }
    // else
    // {
    //     cout << "loop is not present" << endl;
    // }

    // deleteNode(tail, 3);
    // print(tail);

    if (isCircularList(tail))
    {
        cout << "linked list is circular in nature" << endl;
    }
    else
    {
        cout << "linked list is not circular in nature";
    }

    return 0;
}
