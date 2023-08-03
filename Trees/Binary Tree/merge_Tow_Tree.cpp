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
    cout << "Enter the data " << endl;
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

Node *mergeTrees(Node *root1, Node *root2)
{
    if (!root1)
        return root2;
    if (!root2)
        return root1;

    root1->data += root2->data;
    root1->left = mergeTrees(root1->left, root2->left);
    root1->right = mergeTrees(root1->right, root2->right);
    return root1;
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
    Node *root1 = NULL;
    root1 = buildTree(root1);

    Node *root2 = NULL;
    root2 = buildTree(root2);

    Node *root3 = mergeTrees(root1, root2);

    inOrder(root3);
    return 0;
}
// class Solution
// {
// public:
//     TreeNode *mergeTrees(TreeNode *root1, TreeNode *root2)
//     {
//         if (root1 && root2)
//         {
//             root1->val += root2->val;
//             root1->left = mergeTrees(root1->left, root2->left);
//             root1->right = mergeTrees(root1->right, root2->right);
//         }
//         else if (root2)
//         {
//             return root2;
//         }
//         return root1;
//     }
// };
