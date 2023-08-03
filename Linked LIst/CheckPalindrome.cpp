#include <iostream>
#include <vector>
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
// this not optimize code
// class Solution
// {

// private:
//     bool checkPalindrome(vector<int> arr)
//     {
//         int n = arr.size();
//         int s = 0;
//         int e = n - 1;
//         while (s <= e)
//         {
//             if (arr[s] != arr[e])
//             {
//                 return 0;
//             }
//             s++;
//             e--;
//         }
//         return 1;
//     }

// public:
//     // Function to check whether the list is palindrome.
//     bool isPalindrome(Node *head)
//     {
//         vector<int> arr;
//         Node *temp = head;
//         while (temp != NULL)
//         {
//             arr.push_back(temp->data);
//             temp = temp->next;
//         }
//         return checkPalindrome(arr);
//     }
// };

class Solution
{
private:
    Node *getMid(Node *head)
    {
        Node *slow = head;
        Node *fast = head->next;
        while (fast != NULL && fast->next != NULL)
        {
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }
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

public:
    bool isPalindrome(Node *head)
    {
        if (head->next == NULL)
        {
            return 1;
        }
        // step 1 find the middle
        Node *middle = getMid(head);

        // step 2 reverse list after middle
        Node *temp = middle->next;
        middle->next = reverse(temp);

        // compare both halves or optional
        Node *head1 = head;
        Node *head2 = middle->next;

        while (head2 != NULL)
        {
            if (head1->data != head2->data)
            {
                return false;
            }
            head1 = head1->next;
            head2 = head2->next;
        }
        temp = middle->next;
        middle->next = reverse(temp);
        return true;
    }
};

int main()
{
    int T, n, l, firstData;
    cout << "enter how many time execute the programe ";
    cin >> T;
    while (T--)
    {
        Node *head = NULL;
        Node *tail = NULL;
        cout << "enter the length of input ";
        cin >> n;
        // taking first data of LL
        cout << "enter the data of Palindrome " << endl;
        cin >> firstData;
        head = new Node(firstData);
        tail = head;
        // taking remaining of LL
        for (int i = 1; i < n; i++)
        {
            cin >> l;
            tail->next = new Node(l);
            tail = tail->next;
        }
        cout << endl;
        Solution obj;
        cout << "Answer is " << obj.isPalindrome(head) << endl;
    }
    return 0;
}