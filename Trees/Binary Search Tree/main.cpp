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

    if (data < root->data)
        root->left = insertIntoBST(root->left, data);
    else
        root->right = insertIntoBST(root->right, data);
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

int solve(Node *root, int &i, int n)
{
    if (root == NULL)
        return -1;
    int left = solve(root->left, i, n);
    if (left != -1)
        return left;
    i++;
    if (i == n)
        return root->data;
    return solve(root->right, i, n);
}

int kSmallest(Node *root, int n)
{
    int i = 0;
    int ans = solve(root, i, n);
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