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
        data = d;
        left = NULL;
        right = NULL;
    }
};

Node *buildTree(Node *root)
{
    cout << "Enter the root " << endl;
    int data;
    cin >> data;
    root = new Node(data);

    if (data == -1)
        return NULL;

    cout << "Enter the data for left Node " << data << endl;
    root->left = buildTree(root->left);
    cout << "Enter the data for right Node " << data << endl;
    root->right = buildTree(root->right);
    return root;
}

bool maxOrder(Node *root)
{
    // If it's left and right is NULL means single node is there and single node is CBT.(TRUE)
    if (root->left == NULL && root->right == NULL)
        return 1;
    // If it's left exist and right not check root->data>root->left->data if true return it
    else if (root->right == NULL)
        return root->data > root->left->data;
    // If it's left and right is not NULL check root->left and root->right and data of both left and right is greater
    else
        return maxOrder(root->left) && maxOrder(root->right) &&
               root->data > root->left->data && root->data > root->right->data;
}
bool isCBT(Node *root, int i, int size)
{
    // If root is NULL return true
    if (root == NULL)
        return 1;
    // If size is lesser than the index value means that there is some node exist which is not following CBT properity
    else if (i >= size)
        return 0;
    // check for both left and right
    else
        return isCBT(root->left, 2 * i + 1, size) && isCBT(root->right, 2 * i + 2, size);
}
int count(Node *root)
{
    if (root == NULL)
        return 0;
    return 1 + count(root->left) + count(root->right);
}
bool isHeap(Node *root)
{
    int size = count(root);
    return isCBT(root, 0, size) && maxOrder(root);
}

int main()
{
    Node *root = NULL;
    root = buildTree(root);
    if (isHeap(root))
        cout << "true";
    else
        cout << "false";
}

/*
Input:
      5
    /  \
   2    3
Output: 1
Explanation: The given tree follows max-heap property since 5,
is root and it is greater than both its children.

Example 2:

Input:
       10
     /   \
    20   30
  /   \
 40   60
Output: 0
*/