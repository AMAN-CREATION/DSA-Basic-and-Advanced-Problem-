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
    cout << "enter the data " << endl;
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

vector<vector<int>> zigZagTraversal(Node *root)
{
    vector<vector<int>> result;
    if (root == NULL)
        return result;

    queue<Node *> q;
    q.push(root);

    bool leftToRight = true;

    while (!q.empty())
    {
        int n = q.size();
        vector<int> ans(n);

        //*level process
        for (int i = 0; i < n; i++)
        {
            Node *temp = q.front();
            q.pop();

            //*normal insert or reverse insert
            int index = leftToRight ? i : n - i - 1;
            ans[index] = temp->data;

            if (temp->left)
                q.push(temp->left);

            if (temp->right)
                q.push(temp->right);
        }

        //*set direction
        leftToRight = !leftToRight;

        result.push_back(ans);

        //!    or

        // !if one d vector function
        // for (auto i : ans)
        //     result.push_back(i);
    }
    return result;
}

int main()
{
    Node *root = NULL;
    root = buildTree(root);

    vector<vector<int>> ans;
    ans = zigZagTraversal(root);

    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j] << " ";
        }
    }
    cout << endl;
    return 0;
}

/*
intput:-3 9 -1 -1 20 15 -1 -1 7 -1 -1
output:-3 20 9 15 7
*/