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

Node *insertIntoBST(Node *&root, int d)
{
    if (root == NULL)
    {
        root = new Node(d);
        return root;
    }
    if (d > root->data)
    {
        // insert in right part
        root->right = insertIntoBST(root->right, d);
    }
    else
    {
        // insert in left part
        root->left = insertIntoBST(root->left, d);
    }
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

int solve(Node *root, int &i, int k)
{
    if (root == NULL)
        return -1;

    // L
    int left = solve(root->left, i, k);
    if (left != -1)
        return left;

    // N
    i++;
    if (i == k)
        return root->data;

    // R
    return solve(root->right, i, k);
}

int kSmallest(Node *root, int k)
{
    int i = 0;
    int ans = solve(root, i, k);
    return ans;
}
void inOrder(Node *root)
{
    if (root == NULL)
        return;

    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}

int main()
{
    Node *root = NULL;

    // 10 8 21 7 27 5 4 3 -1
    cout << "enter the data for BST " << endl;
    takeInput(root);

    cout << "inOrder traversal ";
    inOrder(root);
    cout << endl;

    int k;
    cin >> k;
    cout << kSmallest(root, k);
}