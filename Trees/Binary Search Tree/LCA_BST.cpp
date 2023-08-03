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
    if (data < root->data)
        root->left = insertIntoBST(root->left, data);
    return root;
}

void takeInput(Node *root)
{
    int data;
    cin >> data;
    while (data != -1)
    {
        insertIntoBST(root, data);
        cin >> data;
    }
}

// Node *LCA(Node *root, Node *p, Node *q)
// {
//     while (root != NULL)
//     {
//         if (root->data < p->data && root->data < q->data)
//             root = root->right;
//         else if (root->data > p->data && root->data > q->data)
//             root = root->left;
//         else
//             return root;
//     }
//     return root;
// }

Node *LCA(Node *root, int n1, int n2)
{
    while (root != NULL)
    {
        if (root->data < n1 && root->data < n2)
            root = root->right;
        else if (root->data > n1 && root->data > n2)
            root = root->left;
        else
            return root;
    }
    return root;
}

int main()
{
    Node *root = NULL;
    // 10 8 21 7 27 5 4 3 -1
    cout << "Enter data to create BST " << endl;
    takeInput(root);
    int p, q;
    cin >> p >> q;
    cout << LCA(root, p, q)->data << endl;
}