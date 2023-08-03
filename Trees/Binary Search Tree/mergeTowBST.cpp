#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int d)
    {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

Node *insertIntoBST(Node *&root, int data)
{
    if (root == NULL)
    {
        root = new Node(data);
        return root;
    }
    if (data > root->data)
        root->right = insertIntoBST(root->right, data);
    else
        root->left = insertIntoBST(root->left, data);
    return root;
}

void takeInput(Node *&root)
{
    int data;
    cin >> data;
    while (data != -1)
    {
        insertIntoBST(root, data);
        cin >> data;
    }
}

void levelOrderTraversal(Node *root)
{
    queue<Node *> q;
    q.push(root);
    q.push(NULL);
    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();
        if (temp == NULL)
        {
            cout << endl;
            if (!q.empty())
                q.push(NULL);
        }
        else
        {
            cout << temp->data << " ";
            if (temp->left)
                q.push(temp->left);
            if (temp->right)
                q.push(temp->right);
        }
    }
}

//! approach -1 but not optimum solution
void inOrder(Node *root, vector<int> &in)
{
    if (root == NULL)
        return;

    inOrder(root->left, in);
    in.push_back(root->data);
    inOrder(root->right, in);
}

vector<int> mergeArray(vector<int> &a, vector<int> &b)
{
    vector<int> ans(a.size() + b.size());
    int i = 0, j = 0;
    int k = 0;
    while (i < a.size() && j < b.size())
    {
        if (a[i] < b[j])
            ans[k++] = a[i++];
        else
            ans[k++] = b[j++];
    }
    while (i < a.size())
        ans[k++] = a[i++];
    while (j < b.size())
        ans[k++] = b[j++];

    return ans;
}

Node *inOrderToBST(int s, int e, vector<int> &in)
{
    if (s > e)
        return NULL;

    int mid = (s + e) / 2;
    Node *root = new Node(in[mid]);
    root->left = inOrderToBST(s, mid - 1, in);
    root->right = inOrderToBST(mid + 1, e, in);
    return root;
}

// Node *mergeBST(Node *root1, Node *root2)
// {
//     // step 1: store inorder-
//     vector<int> bst1, bst2;
//     inOrder(root1, bst1);
//     inOrder(root2, bst2);

//     // step 2: merge both sorted array
//     vector<int> mergedArray = mergeArray(bst1, bst2);

//     // step 3: use merge inorder array to build bst
//     int s = 0;
//     int e = mergedArray.size() - 1;
//     return inOrderToBST(s, e, mergedArray);
// }

//! approach-2 optimum solution
// time complexity = o(m + n);
// space complexity = o(h1 + h2);
void convertIntoSortedDLL(Node *root, Node *&head)
{
    if (root == NULL)
        return;

    convertIntoSortedDLL(root->right, head);
    root->right = head;
    if (head != NULL)
        head->left = root;

    head = root;
    convertIntoSortedDLL(root->left, head);
}

Node *mergeLL(Node *head1, Node *head2)
{
    Node *head = NULL;
    Node *tail = NULL;

    while (head1 != NULL && head2 != NULL)
    {
        if (head1->data < head2->data)
        {
            if (head == NULL)
            {
                head = head1;
                tail = head1;
                head1 = head1->right;
            }
            else
            {
                tail->right = head1;
                head1->left = tail;
                tail = head1;
                head1 = head1->right;
            }
        }
        else
        {
            if (head == NULL)
            {
                head = head2;
                tail = head2;
                head1 = head2->right;
            }
            else
            {
                tail->right = head2;
                head2->left = tail;
                tail = head2;
                head2 = head2->right;
            }
        }
    }
    while (head1 != NULL)
    {
        tail->right = head1;
        head1->left = tail;
        tail = head1;
        head1 = head1->right;
    }
    while (head2 != NULL)
    {
        tail->right = head2;
        head2->left = tail;
        tail = head2;
        head2 = head2->right;
    }
    return head;
}

int countNodes(Node *&head)
{
    int len = 0;
    Node *temp = head;
    while (temp != NULL)
    {
        len++;
        temp = temp->right;
    }
    return len;
}

Node *sortedLLToBST(Node *&head, int n)
{
    // base case
    if (n <= 0 || head == NULL)
        return NULL;

    Node *left = sortedLLToBST(head, n / 2);
    Node *root = head;
    root->left = left;
    head = head->right;
    root->right = sortedLLToBST(head, n - n / 2 - 1);
    return root;
}

Node *mergeBST(Node *&root1, Node *&root2)
{
    // step 1: convert BST into Sorted DLL in-place
    Node *head1 = NULL;
    convertIntoSortedDLL(root1, head1);
    head1->left = NULL;

    Node *head2 = NULL;
    convertIntoSortedDLL(root2, head2);
    head2->left = NULL;

    // step 2 :merge Sorted linked list
    Node *head = mergeLL(head1, head2);

    // step 3: convert Sorted LL in BST;
    return sortedLLToBST(head, countNodes(head));
}

void printInOrder(Node *root)
{
    if (root == NULL)
        return;

    printInOrder(root->left);
    cout << root->data << " ";
    printInOrder(root->right);
}

int main()
{
    // 10 8 21 7 27 5 4 3 -1
    // 50 20 70 10 30 90 110 -1
    Node *root1 = NULL;
    cout << "Enter the data for bst 1 " << endl;
    takeInput(root1);

    Node *root2 = NULL;
    cout << "Enter the data for bst 2" << endl;
    takeInput(root2);

    Node *ans = mergeBST(root1, root2);
    printInOrder(ans);
}

// time complexity - o(m + n);

// 10 8 21 7 27 5 4 3 -1
// 50 20 70 10 30 90 110 -1