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

Node *insertIntoBST(Node *&root, int data)
{
    if (root == NULL)
    {
        root = new Node(data);
        return root;
    }
    if (data > root->data)
        root->right = insertIntoBST(root->right, data);
    else
        root->left = insertIntoBST(root->left, data);
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

void inOrder(Node *root, vector<int> &in)
{
    if (root == NULL)
        return;
    inOrder(root->left, in);
    in.push_back(root->data);
    inOrder(root->right, in);
}

Node *inToBST(int s, int e, vector<int> &in)
{
    if (s > e)
        return NULL;
    int mid = s + (e - s) / 2;

    Node *root = new Node(in[mid]);
    root->left = inToBST(s, mid - 1, in);
    root->right = inToBST(mid + 1, e, in);
    return root;
}

Node *balancedBST(Node *root)
{
    vector<int> in;
    // store inorder ->sorted values
    inOrder(root, in);

    return inToBST(0, in.size() - 1, in);
}

void print(Node *root)
{
    Node *temp = root;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->right;
    }
    cout << endl;
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

int main()
{
    Node *root = NULL;
    cout << "Enter  data to create BST " << endl;
    // 10 8 21 7 27 5 4 3 -1
    takeInput(root);
    // cout << endl;
    // cout << "Printing the BST" << endl;
    // levelOrderTraversal(root);
    // cout << endl;
    print(balancedBST(root));
}
/*
input:- 10 8 21 7 27 5 4 3 -1
output:-7 10 21 27
this is not the full output but is correct;
*/
/*
class Solution {
public:
    void inOrder(TreeNode*root,vector<int>&in){
        if(root==NULL)
            return;
        inOrder(root->left,in);
        in.push_back(root->val);
        inOrder(root->right,in);
    }
    TreeNode*inToBST(int s,int e,vector<int>&in){
        if(s>e)
            return NULL;
        int mid=s+(e-s)/2;
        TreeNode*root=new TreeNode(in[mid]);
        root->left=inToBST(s,mid-1,in);
        root->right=inToBST(mid+1,e,in);
        return root;
    }

    TreeNode* balanceBST(TreeNode* root) {
        vector<int>in;
        inOrder(root,in);

        return inToBST(0,in.size()-1,in);
   }
};
*/