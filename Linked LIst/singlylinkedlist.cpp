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

void insertAtHead(Node *&head, int d)
{
    if (head == NULL)
    {
        Node *temp = new Node(d);
        head = temp;
    }
    // new node create
    Node *temp = new Node(d);
    temp->next = head;
    head = temp;
}

void insertAtTail(Node *&tail, int d)
{
    // new node create
    Node *temp = new Node(d);
    tail->next = temp;
    tail = temp;
}

void print(Node *&head)
{

    if (head == NULL)
    {
        cout << "List is empty " << endl;
        return;
    }
    Node *temp = head;

    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void insertAtPosition(Node *&tail, Node *&head, int position, int d)
{

    // insert at Start
    if (position == 1)
    {
        insertAtHead(head, d);
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
        insertAtTail(tail, d);
        return;
    }

    // creating a node for d
    Node *nodeToInsert = new Node(d);

    nodeToInsert->next = temp->next;

    temp->next = nodeToInsert;
}

//! approach -1 for deleting node
void deleteNode(int position, Node *&head)
{

    // deleting first or start node
    if (position == 1)
    {
        Node *temp = head;
        head = head->next;
        // memory free start ndoe
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

        prev->next = curr->next;
        curr->next = NULL;
        delete curr;
    }
}

//! approach -2 for deleting node using given value
Node *removeNode(Node *head, int val)
{
    if (head == NULL)
        return head;

    while (head != NULL && head->data == val)
    {
        head = head->next;
    }
    Node *curr = head;
    while (curr != NULL && curr->next != NULL)
    {
        if (curr->next->data == val)
        {
            curr->next = curr->next->next;
        }
        else
        {
            curr = curr->next;
        }
    }
    return head;
}

bool isCircularList(Node *head)
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
bool detectLoop(Node *head)
{

    if (head == NULL)
        return false;

    map<Node *, bool> visited;

    Node *temp = head;

    while (temp != NULL)
    {

        // cycle is present
        if (visited[temp] == true)
        {
            cout << "Present on element " << temp->data << endl;
            return true;
        }

        visited[temp] = true;
        temp = temp->next;
    }
    return false;
}
// !Approach-2
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
        {
            // cout << slow->data << endl;
            cout << "present at " << slow->data << endl;
            return slow;
        }
    }

    return NULL;
}

// bool hasCycle(ListNode *head)
// {

//     // if head is NULL then return false;
//     if (head == NULL)
//         return false;

//     // making two pointers fast and slow and assignning them to head
//     ListNode *fast = head;
//     ListNode *slow = head;

//     // till fast and fast-> next not reaches NULL
//     // we will increment fast by 2 step and slow by 1 step
//     while (fast != NULL && fast->next != NULL)
//     {
//         fast = fast->next->next;
//         slow = slow->next;

//         // At the point if fast and slow are at same address
//         // this means linked list has a cycle in it.
//         if (fast == slow)
//             return true;
//     }

//     // if traversal reaches to NULL this means no cycle.
//     return false;
// }

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

    Node *startOfLoop = getStartingNode(head);
    Node *temp = startOfLoop;

    while (temp->next != startOfLoop)
    {
        temp = temp->next;
    }

    temp->next = NULL;
    return head;
}

int main()
{

    // created a new node
    Node *node1 = new Node(10);
    // cout << node1 -> data << endl;
    // cout << node1 -> next << endl;

    // head pointed to node1
    Node *head = node1;
    Node *tail = node1;
    // print(head);

    insertAtTail(tail, 12);

    // print(head);

    insertAtTail(tail, 15);
    // print(head);

    insertAtPosition(tail, head, 3, 22);
    print(head);

    // removeNode(head, 15);
    // print(head);

    cout << "head " << head->data << endl;
    cout << "tail " << tail->data << endl;

    // deleteNode(4, head);

    tail->next = head->next;

    // cout << "head " << head->data << endl;
    // cout << "tail " << tail->data << endl;

    // if (floydDetectLoop(head) != NULL)
    // {
    //     cout << "Cycle is present " << endl;
    // }
    // else
    // {
    //     cout << "no cycle" << endl;
    // }

    // if (detectLoop(head))
    // {
    //     cout << "loop is present" << endl;
    // }
    // else
    //     cout << "loop is not present" << endl;

    Node *loop = getStartingNode(head);

    cout << "loop starts at " << loop->data << endl;

    removeLoop(head);
    print(head);

    print(head);

    if (isCircularList(head))
    {
        cout << " Linked List is Circular in nature" << endl;
    }
    else
    {
        cout << "Linked List is not Circular " << endl;
    }

    return 0;
}