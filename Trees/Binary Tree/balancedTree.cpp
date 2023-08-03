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
    cout << "Enter the Data " << endl;
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

pair<bool, int> balanced(Node *root)
{
    if (root == NULL)
    {
        pair<bool, int> p = make_pair(true, 0);
        return p;
    }
    pair<int, int> left = balanced(root->left);
    pair<int, int> right = balanced(root->right);

    int leftAns = left.first;
    int rightAns = right.first;

    int diff = abs(left.second - right.second) <= 1;

    pair<bool, int> ans;
    ans.second = max(left.second, right.second) + 1;

    if (leftAns && rightAns && diff)
        ans.first = true;
    else
        ans.first = false;
    return ans;
}
bool isBalanced(Node *root)
{
    return balanced(root).first;
}

int main()
{
    Node *root = NULL;
    root = buildTree(root);

    if (isBalanced(root))
        cout << "true";
    else
        cout << "false";
}
/*
output
3 9 -1 -1 20 15 -1 -1 7 -1 -1
true
*/