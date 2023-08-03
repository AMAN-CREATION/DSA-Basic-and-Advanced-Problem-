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

Node *buildTree(Node *root)
{
    cout << "Enter the Data: " << endl;
    int data;
    cin >> data;
    root = new Node(data);

    if (data == -1)
        return NULL;

    cout << "Enter the data for inserting in left of " << data << endl;
    root->left = buildTree(root->left);
    cout << "Enter the data for inserting in right of " << data << endl;
    root->right = buildTree(root->right);

    return root;
}

Node *lowestCommonAncestor(Node *root, int p, int q)
{
    if (root == NULL)
        return NULL;

    if (root->data == p || root->data == q)
        return root;

    Node *leftAns = lowestCommonAncestor(root->left, p, q);
    Node *rightAns = lowestCommonAncestor(root->right, p, q);

    if (leftAns != NULL && rightAns != NULL)
        return root;
    else if (leftAns != NULL && rightAns == NULL)
        return leftAns;
    else if (leftAns == NULL && rightAns != NULL)
        return rightAns;
    else
        return NULL;
}

// Node *lowestCommonAncestor(Node *root, Node *p, Node *q)
// {
//     if (root == NULL)
//         return NULL;

//     if (root == p || root == q)
//         return root;

//     Node *leftAns = lowestCommonAncestor(root->left, p, q);
//     Node *rightAns = lowestCommonAncestor(root->right, p, q);

//     if (leftAns != NULL && rightAns != NULL)
//         return root;
//     else if (leftAns != NULL && rightAns == NULL)
//         return leftAns;
//     else if (leftAns == NULL && rightAns != NULL)
//         return rightAns;
//     else
//         return NULL;
// }

int main()
{
    Node *root = NULL;
    root = buildTree(root);
    int p, q;
    cin >> p >> q;
    cout << lowestCommonAncestor(root, p, q)->data << endl;
}

/*
Input:
n1 = 3 , n2 = 4
           5
          /
         2
        / \
       3   4
Output: 2
Explanation:
LCA of 3 and 4 is 2.
*/