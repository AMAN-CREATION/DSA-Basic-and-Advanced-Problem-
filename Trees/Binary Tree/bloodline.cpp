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

void solve(Node *root, int sum, int &maxSum, int len, int &maxLen)
{
    if (root == NULL)
    {
        if (len > maxLen)
        {
            maxLen = len;
            maxSum = sum;
        }
        else if (len == maxLen)
            maxSum = max(sum, maxSum);
        return;
    }

    sum += root->data;

    solve(root->left, sum, maxSum, len + 1, maxLen);
    solve(root->right, sum, maxSum, len + 1, maxLen);
}

int sumOfLongRootLeafPath(Node *root)
{
    int len = 0;
    int sum = 0;

    int maxSum = INT_MIN;
    int maxLen = 0;

    solve(root, sum, maxSum, len, maxLen);

    return maxSum;
}

int main()
{
    Node *root = NULL;
    root = buildTree(root);
    cout << sumOfLongRootLeafPath(root);
}
/*
Input:
4 2 7 -1 -1 6 -1 -1 -1 5 2 -1 -1 3 -1 -1
Output: 13
*/