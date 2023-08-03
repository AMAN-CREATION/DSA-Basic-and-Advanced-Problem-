//! Maximum Depth of Binary Tree or hight of binary tree

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
    cout << "enter the data" << endl;
    int data;
    cin >> data;
    root = new Node(data);

    if (data == -1)
        return NULL;

    cout << "enter the data for left node " << data << endl;
    root->left = buildTree(root->left);
    cout << "enter the data for right node " << data << endl;
    root->right = buildTree(root->right);
}
// using recursion
int height(Node *root)
{
    if (root == NULL)
        return 0;

    int left = height(root->left);
    int right = height(root->right);

    int ans = max(left, right) + 1;

    return ans;
}
//
int maxDepth(Node *root)
{
    queue<Node *> q;
    int count = 0;

    if (!root)
        return 0;

    q.push(root);

    while (!q.empty())
    {
        count++;
        int n = q.size();
        for (int i = 0; i < n; i++)
        {
            Node *temp = q.front();
            q.pop();

            if (temp->left != NULL)
                q.push(temp->left);

            if (temp->right != NULL)
                q.push(temp->right);
        }
    }
    return count;
}

int main()
{
    Node *root = NULL;

    root = buildTree(root);

    cout << height(root);
}

/*
Input:
     1
    /  \
   2    3
Output: 2
*/