#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *random;

    Node(int d)
    {
        this->data = d;
        this->next = NULL;
        this->random = NULL;
    }
};

// approach-1 using pointer but not a optimum case
// class Solution
// {
// private:
//     void insertAtTail(Node *&head, Node *&tail, int d)
//     {
//         Node *newNode = new Node(d);
//         if (head == NULL)
//         {
//             head = newNode;
//             tail = newNode;
//             return;
//         }
//         else
//         {
//             tail->next = newNode;
//             tail = newNode;
//         }
//     }

// public:
//     Node *copyList(Node *head)
//     {
//         // step-1 create a clone list
//         Node *cloneHead = NULL;
//         Node *cloneTail = NULL;

//         // traverse
//         Node *temp = head;
//         while (temp != NULL)
//         {
//             insertAtTail(cloneHead, cloneTail, temp->data);
//             temp = temp->next;
//         }

//         // step-2 create a map
//         unordered_map<Node *, Node *> oldToNewNode;

//         Node *originalNode = head;
//         Node *cloneNode = cloneHead;
//         while (originalNode != NULL && cloneNode != NULL)
//         {
//             oldToNewNode[originalNode] = cloneNode;
//             originalNode = originalNode->next;
//             cloneNode = cloneNode->next;
//         }

//         // step 3 arrange rondom node
//         originalNode = head;
//         cloneNode = cloneHead;
//         while (originalNode != NULL)
//         {
//             /* code */
//             cloneNode->random = oldToNewNode[originalNode->random];
//             originalNode = originalNode->next;
//             cloneNode = cloneNode->next;
//         }
//         return cloneHead;
//     }
// };

// Approach 2-optimum sol with time-complexity o(n) and space complexity o(1);
class Solution
{
private:
    void insertAtTail(Node *&head, Node *&tail, int d)
    {
        Node *newNode = new Node(d);
        if (head == NULL)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
    }

public:
    Node *copyList(Node *head)
    {
        // step 1 create a clone Node
        Node *cloneHead = NULL;
        Node *cloneTail = NULL;

        Node *temp = head;
        while (temp != NULL)
        {
            insertAtTail(cloneHead, cloneTail, temp->data);
            temp = temp->next;
        }

        // step-2 cloneNode adds in btw original list
        Node *originalNode = head;
        Node *cloneNode = cloneHead;
        while (originalNode != NULL && cloneNode != NULL)
        {
            Node *next = originalNode->next;
            originalNode->next = cloneNode;
            originalNode = next;

            next = cloneNode->next;
            cloneNode->next = originalNode;
            cloneNode = next;
        }

        // step-3 random pointer copy
        temp = head;
        while (temp != NULL)
        {
            if (temp->next != NULL)
            {
                temp->next->random = temp->random ? temp->random->next : temp->random;
            }
            temp = temp->next->next;
        }

        // step-4 revert changes done in step 2
        originalNode = head;
        cloneNode = cloneHead;

        while (originalNode != NULL && cloneNode != NULL)
        {
            originalNode->next = cloneNode->next;
            originalNode = originalNode->next;

            if (originalNode != NULL)
            {
                cloneNode->next = originalNode->next;
            }
            cloneNode = cloneNode->next;
        }
        // step 5 return Answer;
        return cloneHead;
    }
};

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
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    // head->random = head->next->next;
    // head->next->random = head;
    // head->next->next->random = head->next->next->next->next;
    // head->next->next->next->random = head->next->next;
    // head->next->next->next->next->random = head->next;

    cout << "original LL ";
    printList(head);

    Solution obj;
    Node *res = obj.copyList(head);
    cout << "copy LL ";
    printList(res);

    return 0;
}