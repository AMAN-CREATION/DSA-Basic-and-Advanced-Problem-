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

class Solution
{
public:
    Node *solve(int *in, int *pre, int &index, int inOrderStart, int inOrderEnd, int n)
    {
        if (index >= n || inOrderStart > inOrderEnd)
            return NULL;

        int element = pre[index++];

        int i = inOrderStart;

        while (i < n)
        {
            if (in[i] == element)
                break;
            i++;
        }
        Node *root = new Node(element);

        root->left = solve(in, pre, index, inOrderStart, i - 1, n);
        root->right = solve(in, pre, index, i + 1, inOrderEnd, n);
        return root;
    }

    Node *buildTree(int *in, int *pre, int n)
    {
        int preOrderIndex = 0;
        Node *ans = solve(in, pre, preOrderIndex, 0, n - 1, n);
        return ans;
    }
};

void postorder(Node *root)
{
    if (root == NULL)
        return;

    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

int main()
{
    int n;
    cin >> n;
    int in[n], pre[n];
    for (int i = 0; i < n; i++)
        cin >> in[i];
    for (int i = 0; i < n; i++)
        cin >> pre[i];

    Solution obj;
    Node *root = obj.buildTree(in, pre, n);
    postorder(root);
    cout << endl;
}
/*

! same solution but using vector
class Solution1
{
public:
    void createMapping(vector<int> &inorder, map<int, int> &nodeToIndex, int n)
    {
        for (int i = 0; i < n; i++)
            nodeToIndex[inorder[i]] = i;
    }
    Node *solve(vector<int> &preorder, vector<int> &inorder, int &index, int inorderStart, int inorderEnd, map<int, int> &nodeToIndex)
    {
        if ((index >= inorder.size()) || (inorderStart > inorderEnd))
            return NULL;

        int element = preorder[index++];
        int i = nodeToIndex[element];

        Node *root = new Node(element);
        root->left = solve(preorder, inorder, index, inorderStart, i - 1, nodeToIndex);
        root->right = solve(preorder, inorder, index, i + 1, inorderEnd, nodeToIndex);
        return root;
    }

    Node *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        int preOrderIndex = 0;
        map<int, int> nodeToIndex;
        createMapping(inorder, nodeToIndex, inorder.size());
        Node *ans = solve(preorder, inorder, preOrderIndex, 0, inorder.size() - 1, nodeToIndex);
        return ans;
    }
};
int main()
{
    int n;
    cin >> n;
    vector<int> in(n);
    vector<int> pre(n);
    for (int i = 0; i < n; i++)
        cin >> in[i];
    for (int i = 0; i < n; i++)
        cin >> pre[i];

    Solution1 obj;
    Node *root = obj.buildTree(in, pre);

    printPostOrder(root);
    cout << endl;
}
*/

/*

Input:
N = 4
inorder[] = {1 6 8 7}
preorder[] = {1 6 7 8}
Output: 8 7 6 1
*/

//! some this solution does not work
// class Solution
// {
// public:
//     void createMapping(int in[], map<int, int> &nodeToIndex, int n)
//     {
//         for (int i = 0; i < n; i++)
//         {
//             nodeToIndex[in[i]] = i;
//         }
//     }

//     Node *solve(int in[], int pre[], int &index,
//                 int inorderStart, int inorderEnd, int n, map<int, int> &nodeToIndex)
//     {
//         if (index >= n || inorderStart > inorderEnd)
//         {
//             return NULL;
//         }
//         int element = pre[index++];
//         Node *root = new Node(element);
//         int p = nodeToIndex[element];

//         root->left = solve(in, pre, index, inorderStart, p - 1, n, nodeToIndex);
//         root->right = solve(in, pre, index, p + 1, inorderEnd, n, nodeToIndex);

//         return root;
//     }

//     Node *buildTree(int in[], int pre[], int n)
//     {
//         int preOrderIndex = 0;
//         map<int, int> nodeToIndex;
//         createMapping(in, nodeToIndex, n);
//         Node *ans = solve(in, pre, preOrderIndex, 0, n - 1, n, nodeToIndex);
//         return ans;
//     }
// };