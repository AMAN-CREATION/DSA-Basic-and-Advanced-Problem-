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

void solve(Node *root, vector<int> &ans, int lvl)
{
    if (root == NULL)
        return;

    if (lvl == ans.size())
        ans.push_back(root->data);

    solve(root->left, ans, lvl + 1);
    solve(root->right, ans, lvl + 1);
}

vector<int> leftView(Node *root)
{
    vector<int> ans;
    solve(root, ans, 0);
    return ans;
}

int main()
{
    Node *root = NULL;

    root = buildTree(root);
    vector<int> ans = leftView(root);
    for (auto i : ans)
        cout << i << " ";
    cout << endl;
}

/*
Left view of following tree is 1 2 4 8.

          1
       /     \
     2        3
   /     \    /    \
  4     5   6    7
   \
     8
    1 2 4 -1 8 -1 -1 5 -1 -1 3 6 -1 -1 7 -1 -1
*/