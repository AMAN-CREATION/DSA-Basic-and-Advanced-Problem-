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

    cout << "enter the data for left node " << data << endl;
    root->left = buildTree(root->left);
    cout << "enter the data for right node " << data << endl;
    root->right = buildTree(root->right);

    return root;
}

pair<int, int> diameterFast(Node *root)
{
    if (root == NULL)
    {
        pair<int, int> p = make_pair(0, 0);
        return p;
    }
    pair<int, int> left = diameterFast(root->left);
    pair<int, int> right = diameterFast(root->right);

    int op1 = left.first;
    int op2 = right.first;
    int op3 = left.second + right.second;

    // in case you need to add root
    // int op3 = left.second, right.second+1;

    pair<int, int> ans;
    ans.first = max(op1, max(op2, op3));

    ans.second = max(left.second, right.second) + 1;
    return ans;
}

int diameter(Node *root)
{
    return diameterFast(root).first;
}

int main()
{
    Node *root = NULL;
    root = buildTree(root);
    cout << diameter(root) << endl;
}

// input= 10 20 40 -1 -1 60 -1 -1 30 -1 -1
//  Output: 4
// input 1 2 4 -1 -1 5 -1 -1 3 -1 -1
// output=3