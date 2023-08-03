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

class Solution1
{
public:
    vector<int> verticalOrder(Node *root)
    {
        map<int, map<int, vector<int>>> nodes;
        queue<pair<Node *, pair<int, int>>> q;
        vector<int> ans;

        if (root == NULL)
            return ans;

        q.push(make_pair(root, make_pair(0, 0)));

        while (!q.empty())
        {
            pair<Node *, pair<int, int>> temp = q.front();
            q.pop();
            Node *frontNode = temp.first;
            int hd = temp.second.first;
            int lvl = temp.second.second;

            nodes[hd][lvl].push_back(frontNode->data);

            if (frontNode->left)
                q.push(make_pair(frontNode->left, make_pair(hd - 1, lvl + 1)));

            if (frontNode->right)
                q.push(make_pair(frontNode->right, make_pair(hd + 1, lvl + 1)));
        }
        for (auto i : nodes)
        {
            for (auto j : i.second)
            {
                for (auto k : j.second)
                {
                    ans.push_back(k);
                }
            }
        }
        return ans;
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

// int main()
// {
//     Node *root = NULL;
//     root = buildTree(root);

//     Solution1 obj;
//     vector<int> ans = obj.verticalOrder(root);

//     for (auto i : ans)
//         cout << i << " ";
//     cout << endl;
// }

class Solution2
{
public:
    map<int, vector<pair<int, int>>> mp;
    void preOrder(Node *root, int hd, int lvl)
    {
        if (root == NULL)
            return;

        mp[hd].push_back({lvl, root->data});
        preOrder(root->left, hd - 1, lvl + 1);
        preOrder(root->right, hd + 1, lvl + 1);
    }

    vector<vector<int>> verticalTraversal(Node *root)
    {
        preOrder(root, 0, 0);
        vector<vector<int>> ans;
        int k = 0;
        for (auto i : mp)
        {
            sort(i.second.begin(), i.second.end());
            ans.push_back({});
            for (auto j : i.second)
                ans[k].push_back(j.second);

            k++;
        }
        return ans;
    }
};

int main()
{
    Node *root = NULL;
    root = buildTree(root);

    Solution2 obj;
    vector<vector<int>> ans = obj.verticalTraversal(root);

    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j] << " ";
        }
    }
    cout << endl;
}
// Input:
//        1
//     /    \
//    2       3
//  /    \      \
// 4      5      6
// 1 2 4 -1 -1 5 -1 -1 3 -1 6 -1 -1
// Output: 4 2 1 5 3 6