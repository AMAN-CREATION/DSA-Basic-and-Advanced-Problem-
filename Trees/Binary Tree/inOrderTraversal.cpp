#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node *left;
    node *right;

    node(int d)
    {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

class Solution
{
private:
    void inorderunit(node *root, vector<int> &res)
    {
        if (root == NULL)
            return;
        inorderunit(root->left, res);
        res.push_back(root->data);
        inorderunit(root->right, res);
    }

public:
    // Function to return a list containing the inorder traversal of the tree.
    vector<int> inOrder(node *root)
    {
        vector<int> count;
        inorderunit(root, count);
        return count;
    }
};

//{ Driver Code Starts.

// Function to Build Tree
node *buildTree(string str)
{
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    node *root = new node(stoi(ip[0]));

    // Push the root to the queue
    queue<node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size())
    {

        // Get and remove the front of the queue
        node *currnode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N")
        {

            // Create the left child for the current node
            currnode->left = new node(stoi(currVal));

            // Push it to the queue
            queue.push(currnode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N")
        {

            // Create the right child for the current node
            currnode->right = new node(stoi(currVal));

            // Push it to the queue
            queue.push(currnode->right);
        }
        i++;
    }

    return root;
}

int main()
{
    int t;
    string tc;
    getline(cin, tc);
    t = stoi(tc);
    while (t--)
    {
        string s;
        getline(cin, s);
        node *root = buildTree(s);

        Solution ob;
        vector<int> res = ob.inOrder(root);
        for (int i = 0; i < res.size(); i++)
            cout << res[i] << " ";
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends