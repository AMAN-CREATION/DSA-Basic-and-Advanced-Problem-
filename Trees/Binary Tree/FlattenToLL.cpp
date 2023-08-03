//! Flatten Binary Tree to Linked List
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

void flatten(Node *root)
{
    Node *curr = root;
    while (curr != NULL)
    {
        if (curr->left)
        {
            // finding predecessor
            Node *pred = curr->left;
            while (pred->right)
                pred = pred->right;

            pred->right = curr->right;
            curr->right = curr->left;
            curr->left = NULL;
        }
        curr = curr->right;
    }
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
    root = buildTree(root);
    flatten(root);
    inOrder(root);
}

/*
Input :
          1
        /   \
       2     5
      / \     \
     3   4     6
     1 2 3 -1 -1 4 -1 -1 5 -1 6 -1 -1
Output :
1 2 3 4 5 6
*/