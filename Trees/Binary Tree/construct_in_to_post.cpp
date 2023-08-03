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

void preOrder(Node *root)
{
    if (root == NULL)
        return;
    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}

void createMapping(int in[], map<int, int> &nodeToIndex, int n)
{
    for (int i = 0; i < n; i++)
    {
        nodeToIndex[in[i]] = i;
    }
}

Node *solve(int in[], int post[], int &index, int inorderStart, int inorderEnd, int n, map<int, int> &nodeToIndex)
{
    if (index < 0 || inorderStart > inorderEnd)
        return NULL;

    int element = post[index--];

    int p = nodeToIndex[element];
    Node *root = new Node(element);

    root->right = solve(in, post, index, p + 1, inorderEnd, n, nodeToIndex);
    root->left = solve(in, post, index, inorderStart, p - 1, n, nodeToIndex);

    return root;
}

Node *buildTree(int in[], int post[], int n)
{
    int postOrderIndex = n - 1;
    map<int, int> nodeToIndex;
    createMapping(in, nodeToIndex, n);

    Node *ans = solve(in, post, postOrderIndex, 0, n - 1, n, nodeToIndex);
    return ans;
}

int main()
{
    int n;
    cin >> n;
    int in[n], post[n];
    for (int i = 0; i < n; i++)
        cin >> in[i];
    for (int i = 0; i < n; i++)
        cin >> post[i];

    Node *root = buildTree(in, post, n);
    preOrder(root);
    cout << endl;
}

/*
Input:
N = 8
in[] = 4 8 2 5 1 6 3 7
post[] =8 4 5 2 6 7 3 1
Output: 1 2 4 8 5 3 6 7

*/
class Solution
{
public:
    void createMapping(vector<int> &inorder, map<int, int> &nodeToIndex, int n)
    {
        for (int i = 0; i < n; i++)
            nodeToIndex[inorder[i]] = i;
    }

    Node *solve(vector<int> &inorder, vector<int> &postorder, int &index,
                int inorderStart, int inorderEnd, map<int, int> &nodeToIndex)
    {
        if (index < 0 || inorderStart > inorderEnd)
            return NULL;

        int element = postorder[index--];
        Node *root = new Node(element);
        int p = nodeToIndex[element];

        root->right = solve(inorder, postorder, index, p + 1, inorderEnd, nodeToIndex);
        root->left = solve(inorder, postorder, index, inorderStart, p - 1, nodeToIndex);

        return root;
    }

    Node *buildTree(vector<int> &inorder, vector<int> &postorder)
    {
        int postOrderIndex = postorder.size() - 1;
        map<int, int> nodeToIndex;
        createMapping(inorder, nodeToIndex, inorder.size());
        Node *ans = solve(inorder, postorder, postOrderIndex, 0,
                          inorder.size() - 1, nodeToIndex);
        return ans;
    }
};

// int main()
// {

//     int n;
//     cin >> n;
//     vector<int> in(n);
//     vector<int> post(n);
//     for (int i = 0; i < n; i++)
//     {
//         cin >> in[i];
//     }
//     for (int i = 0; i < n; i++)
//     {
//         cin >> post[i];
//     }
//     Solution obj;
//     Node *root = obj.buildTree(in, post);
//     preOrder(root);
//     cout << endl;
// }