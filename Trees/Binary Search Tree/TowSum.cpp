//! Tow sum using two pointer approach

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

void inOrder(Node *root, vector<int> &in)
{
    if (root == NULL)
        return;

    inOrder(root->left, in);
    in.push_back(root->data);
    inOrder(root->right, in);
}

bool findTarget(Node *root, int k)
{
    vector<int> in;
    // store inorder ->sorted values
    inOrder(root, in);
    int i = 0, j = in.size() - 1;
    while (i < j)
    {
        int sum = in[i] + in[j];
        if (sum == k)
            return true;
        else if (sum > k)
            j--;
        else
            i++;
    }
    return false;
}

int main()
{
    Node *root = NULL;

    // 10 8 21 7 27 5 4 3 -1
    cout << "Enter the data for BST " << endl;
    takeInput(root);

    // cout << "Printing the BST" << endl;
    // levelOrderTraversal(root);
    // cout << endl;

    int k = 7;
    if (findTarget(root, k))
        cout << "true" << endl;
    else
        cout << "false" << endl;
}