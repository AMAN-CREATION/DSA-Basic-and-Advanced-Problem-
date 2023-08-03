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
    cout << "enter the data " << endl;
    int data;
    cin >> data;
    root = new Node(data);

    if (data == -1)
        return NULL;

    cout << "enter the data for left node " << data << endl;
    root->left = buildTree(root->left);
    cout << "enter the data for right node " << data << endl;
    ;
    root->right = buildTree(root->right);

    return root;
}

class Solution
{
public:
    void traverseLeft(Node *root, vector<int> &ans)
    {
        if ((root == NULL) || (root->left == NULL && root->right == NULL))
            return;

        ans.push_back(root->data);
        if (root->left)
            traverseLeft(root->left, ans);
        else
            traverseLeft(root->right, ans);
    }

    void traverseLeaf(Node *root, vector<int> &ans)
    {
        if (root == NULL)
            return;

        if (root->right == NULL && root->left == NULL)
        {
            ans.push_back(root->data);
            return;
        }
        traverseLeaf(root->left, ans);
        traverseLeaf(root->right, ans);
    }

    void traverseRight(Node *root, vector<int> &ans)
    {
        if ((root == NULL) || (root->left == NULL && root->right == NULL))
            return;

        if (root->right)
            traverseRight(root->right, ans);
        else
            traverseRight(root->left, ans);

        ans.push_back(root->data);
    }

    vector<int> boundary(Node *root)
    {
        vector<int> ans;
        if (root == NULL)
            return ans;

        ans.push_back(root->data);

        // left part print/store
        traverseLeft(root->left, ans);

        // traverse leaf node

        // left sub tree
        traverseLeaf(root->left, ans);

        // right sub tree
        traverseLeaf(root->right, ans);

        // right sub tree
        traverseRight(root->right, ans);
    }
};

int main()
{
    Node *root = NULL;

    root = buildTree(root);

    Solution obj;
    vector<int> ans = obj.boundary(root);
    for (auto i : ans)
        cout << i << " ";
    cout << endl;
    return 0;
}

/*
Input:
        1
      /   \
     2     3
    / \   / \
   4   5 6   7
      / \
     8   9

    1 2 4 -1 -1 5 8 -1 -1 9 -1 -1 3 6 -1 -1 7 -1 -1

Output: 1 2 4 8 9 6 7 3
*/