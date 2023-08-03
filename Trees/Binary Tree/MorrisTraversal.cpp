// Inorder tree traversal without recursion ans stack
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

void morrisTraversal(Node *root)
{
    if (root == NULL)
        return;

    // creating a dumy node for re-traversal
    Node *curr = root;

    while (curr != NULL)
    {
        if (curr->left == NULL)
        {
            cout << curr->data << " ";
            curr = curr->right;
        }
        else
        {
            // finding the predecessor
            Node *pred = curr->left;
            while (pred->right != NULL && pred->right != curr)
            {
                pred = pred->right;
            }
            if (pred->right == NULL)
            {
                pred->right = curr;
                curr = curr->left;
            }
            else
            {
                pred->right = NULL;
                cout << curr->data << " ";
                curr = curr->right;
            }
        }
    }
}

int main()
{
    Node *root = NULL;
    root = buildTree(root);
    morrisTraversal(root);
}

/*
input:- 1 2 4 -1 -1 5 -1 -1 3 -1 -1
output:- 4 2 5 1 3
*/