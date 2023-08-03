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
class Solution
{
public:
    void solve(Node *root, int k, int &count, vector<int> path)
    {
        // base case
        if (root == NULL)
            return;

        path.push_back(root->data);

        // left
        solve(root->left, k, count, path);
        // right
        solve(root->right, k, count, path);

        // check for K Sum

        int size = path.size();
        int sum = 0;
        for (int i = size - 1; i >= 0; i--)
        {
            sum += path[i];
            if (sum == k)
                count++;
        }

        path.pop_back();
    }
    int sumK(Node *root, int k)
    {
        vector<int> path;
        int count = 0;
        solve(root, k, count, path);
        return count;
    }
};

int main()
{
    Node *root = NULL;
    root = buildTree(root);

    int k = 3;
    Solution ob;
    cout << ob.sumK(root, k) << "\n";

    return 0;
} // } Driver Code Ends
  /*
  Input:
  Tree =
             1
          /     \
        3        -1
      /   \     /   \
     2     1   4     5
          /   / \     \
         1   1   2     6
  K = 5
  Output: 8
  Explanation:
  The following paths sum to K.
  3 2
  3 1 1
  1 3 1
  4 1
  1 -1 4 1
  -1 4 2
  5
  1 -1 5
  
  
  
  Input:
Tree =
          1
        /   \
       2     3
K = 3
Output: 2
  */