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

void inorder(Node *node)
{
    if (!node)
        return;
    /* first recur on left child */
    inorder(node->left);
    /* then print the data of node */
    cout << node->data << " ";
    /* now recur on right child */
    inorder(node->right);
}

/* Function to merge given two binary trees*/
Node *MergeTrees(Node *t1, Node *t2)
{
    if (!t1)
        return t2;
    if (!t2)
        return t1;
    t1->data += t2->data;
    t1->left = MergeTrees(t1->left, t2->left);
    t1->right = MergeTrees(t1->right, t2->right);
    return t1;
}

int main()
{

    Node *root1 = NULL;
    root1 = buildTree(root1);
    cout << endl;
    cout << endl;
    inorder(root1);
    Node *root2 = NULL;
    cout << endl;
    root2 = buildTree(root2);
    inorder(root2);
    cout << endl;
    Node *root3 = MergeTrees(root1, root2);
    printf("The Merged Binary Tree is:\n");
    inorder(root3);
    return 0;
}