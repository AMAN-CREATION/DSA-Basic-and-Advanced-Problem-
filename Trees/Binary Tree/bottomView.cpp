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

// hd-horizontal distance

vector<int> topView(Node *root)
{
    vector<int> ans;

    if (root == NULL)
        return ans;

    map<int, int> topNode;
    queue<pair<Node *, int>> q;
    q.push(make_pair(root, 0));

    while (!q.empty())
    {
        pair<Node *, int> temp = q.front();
        q.pop();

        Node *frontNode = temp.first;
        int hd = temp.second;

        topNode[hd] = frontNode->data;

        if (frontNode->left)
            q.push(make_pair(frontNode->left, hd - 1));
        if (frontNode->right)
            q.push(make_pair(frontNode->right, hd + 1));
    }
    for (auto i : topNode)
        ans.push_back(i.second);

    return ans;
}

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

int main()
{
    Node *root = NULL;

    root = buildTree(root);
    vector<int> ans = topView(root);
    for (auto i : ans)
        cout << i << " : ";
    cout << endl;
    return 0;
}

/*
input
                      20
                    /    \
                  8       22
                /   \     /   \
              5      3 4     25
                     /    \
                 10       14
20 8 5 -1 -1 3 10 -1 -1 -1 22 4 -1 14 -1 -1 25 -1 -1
output
For the above tree the output should be 5 10 4 14 25.
*/