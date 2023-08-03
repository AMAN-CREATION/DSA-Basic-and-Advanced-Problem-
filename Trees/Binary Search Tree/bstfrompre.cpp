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
Node *insertIntoBST(Node *&root, int d)
{
    if (root == NULL)
    {
        root = new Node(d);
        return root;
    }
    if (d > root->data)
    {
        // insert in right part
        root->right = insertIntoBST(root->right, d);
    }
    else
    {
        // insert in left part
        root->left = insertIntoBST(root->left, d);
    }
    return root;
}
void takeInput(Node *&root)
{
    int data;
    cin >> data;

    while (data != -1)
    {
        insertIntoBST(root, data);
        cin >> data;
    }
}
void levelOrderTraversal(Node *root)
{
    queue<Node *> q;
    q.push(root);
    q.push(NULL);
    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();
        if (temp == NULL)
        {
            cout << endl;
            if (!q.empty())
                q.push(NULL);
        }
        else
        {
            cout << temp->data << " ";
            if (temp->left)
                q.push(temp->left);
            if (temp->right)
                q.push(temp->right);
        }
    }
}

Node *solve(vector<int> &pre, int mini, int maxi, int &i)
{
    if (i >= pre.size())
        return NULL;
    if (pre[i] < mini || pre[i] > maxi)
        return NULL;

    Node *root = new Node(pre[i++]);
    root->left = solve(pre, mini, root->data, i);
    root->right = solve(pre, root->data, maxi, i);
    return root;
}

Node *preToBST(vector<int> &pre)
{
    int mini = INT_MIN;
    int maxi = INT_MAX;
    int i = 0;
    return solve(pre, mini, maxi, i);
}

void printInorder(Node *&node)
{
    if (node == NULL)
        return;
    printInorder(node->left);
    cout << node->data << " ";
    printInorder(node->right);
}

int main()
{
    Node *root = NULL;
    vector<int> arr = {15, 10, 7, 13, 21, 20, 25};
    root = preToBST(arr);
    printInorder(root);
    levelOrderTraversal(root);
}
/*
class Solution {
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int i=0;
        return build(preorder,i,INT_MAX);
    }
    TreeNode*build(vector<int> &A,int &i,int bound){
        if(i==A.size() || A[i]>bound) return NULL;
        TreeNode*root=new TreeNode(A[i++]);
        root->left=build(A,i,root->val);
        root->right=build(A,i,bound);
        return root;
    }
};
*/