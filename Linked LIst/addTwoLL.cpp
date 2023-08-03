//{ Driver Code Starts
// driver

#include <bits/stdc++.h>
using namespace std;

/* Linked list Node */
class Node
{
public:
    int data;
    Node *next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

void push(Node *&head, int newData)
{
    Node *new_node = new Node(newData);

    new_node->data = newData;
    new_node->next = head;

    head = new_node;
}

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

//  } Driver Code Ends
/* node for linked list:

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/
class Solution
{
private:
    Node *reverse(Node *head)
    {

        Node *curr = head;
        Node *prev = NULL;
        Node *next = NULL;

        while (curr != NULL)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }

    void insertAtTail(Node *&head, Node *&tail, int val)
    {

        Node *temp = new Node(val);
        //   empty list
        if (head == NULL)
        {
            head = temp;
            tail = temp;
            return;
        }
        else
        {
            tail->next = temp;
            tail = temp;
        }
    }

    Node *add(Node *first, Node *second)
    {
        int carry = 0;

        Node *ansHead = NULL;
        Node *ansTail = NULL;

        while (first != NULL || second != NULL || carry != 0)
        {

            int val1 = 0;
            if (first != NULL)
                val1 = first->data;

            int val2 = 0;
            if (second != NULL)
                val2 = second->data;

            int sum = carry + val1 + val2;

            int digit = sum % 10;

            // create node and add in answer Linked List
            insertAtTail(ansHead, ansTail, digit);

            carry = sum / 10;
            if (first != NULL)
                first = first->next;

            if (second != NULL)
                second = second->next;
        }
        return ansHead;
    }

public:
    // Function to add two numbers represented by linked list.
    Node *addTwoLists(Node *first, Node *second)
    {
        // step 1 -  reverse input LL
        first = reverse(first);
        second = reverse(second);

        // step2 - add 2 LL
        Node *ans = add(first, second);

        // step 3
        ans = reverse(ans);

        return ans;
    }
};

//{ Driver Code Starts.

int main(void)
{
    Node *res = NULL;
    Node *first = NULL;
    Node *second = NULL;

    // Create first list
    // 7->5->9->4->6
    push(first, 6);
    push(first, 4);
    push(first, 9);
    push(first, 5);
    push(first, 7);
    printf("First List is ");
    print(first);

    push(second, 4);
    push(second, 8);
    push(second, 8);
    push(second, 8);
    cout << "Second List is ";
    print(second);

    Solution obj;
    res = obj.addTwoLists(first, second);
    cout << "Resultant list is ";
    print(res);
    return 0;
}

// } Driver Code Ends


class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
           ListNode* dummy=new ListNode();
        ListNode* temp=dummy;
        int carry=0;
        while(l1!=NULL || l2!=NULL || carry){
            int sum=0;
            if(l1!=NULL){
                sum+=l1->val;
                l1=l1->next;
            }
            if(l2!=NULL){
                sum+=l2->val;
                l2=l2->next;
            }
            sum+=carry;
            carry=sum/10;
            ListNode* newnode=new ListNode(sum%10);
            temp->next=newnode;
            temp=temp->next;
        }
        return dummy->next;
    }
};