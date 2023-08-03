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

void splitList(Node *&head, Node *&head1, Node *&head2)
{
    Node *slow = head;
    Node *fast = head;

    if (head == NULL)
    {
        return;
    }

    /* If there are odd nodes in the circular list then
   fast_ptr->next becomes head and for even nodes
   fast_ptr->next->next becomes head */
    while (fast->next != head && fast->next->next != head)
    {
        fast = fast->next->next;
        slow = slow->next;
    }

    /* If there are even elements in list
       then move fast_ptr */
    if (fast->next->next == head)
    {
        fast = fast->next;
    }

    /* Set the head pointer of first half */
    head1 = head;

    /* Set the head pointer of second half */
    if (head->next != head)
    {
        head2 = slow->next;
    }

    /* Make second half circular */
    fast->next = slow->next;

    /* Make first half circular */
    slow->next = head;
}
void push(Node *&head, int newData)
{
    Node *newNode = new Node(newData);
    Node *temp = head;
    newNode->data = newData;
    newNode->next = head;

    /* If linked list is not NULL then
       set the next of last node */
    if (head != NULL)
    {
        while (temp->next != head)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    else
        newNode->next = newNode;

    head = newNode;
}

// void push(Node *&head, int newData)
// {
//     Node *newNode = new Node();
//     Node *temp = head;
//     newNode->data = newData;
//     newNode->next = head;

//     /* If linked list is not NULL then
//        set the next of last node */
//     if (head != NULL)
//     {
//         while (temp->next != head)
//             temp = temp->next;
//         temp->next = newNode;
//     }
//     else
//         newNode->next = newNode; /*For the first node */

//     head = newNode;
// }

void print(Node *&head)
{
    Node *temp = head;
    if (head != NULL)
    {
        cout << endl;
        do
        {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);
    }
}
int main()
{
    int list_size, i;

    /* Initialize lists as empty */
    Node *head = NULL;
    Node *head1 = NULL;
    Node *head2 = NULL;

    /* Created linked list will be 12->56->2->11 */
    push(head, 12);
    push(head, 56);
    push(head, 2);
    push(head, 11);

    cout << "Original Circular Linked List";
    print(head);

    /* Split the list */
    splitList(head, head1, head2);

    cout << "\nFirst Circular Linked List";
    print(head1);

    cout << "\nSecond Circular Linked List";
    print(head2);
    return 0;
}