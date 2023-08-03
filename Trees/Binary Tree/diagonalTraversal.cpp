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

vector<int> diagonalTraversal(Node *root)
{
    vector<int> ans;
    if (root == NULL)
        return ans;

    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();
        while (temp)
        {
            if (temp->left)
                q.push(temp->left);
            ans.push_back(temp->data);
            temp = temp->right;
        }
    }
    return ans;
}

int main()
{
    Node *root = NULL;
    root = buildTree(root);

    vector<int> ans = diagonalTraversal(root);
    for (auto i : ans)
        cout << i << " ";
    cout << endl;
}

/*
Input :
            8
         /     \
        3      10
      /   \      \
     1     6     14
         /   \   /
        4     7 13
    8 3 1 -1 -1 6 4 -1 -1 7 -1 -1 10 -1 14 13 -1 -1 -1
Output : 8 10 14 3 6 7 13 1 4
*/