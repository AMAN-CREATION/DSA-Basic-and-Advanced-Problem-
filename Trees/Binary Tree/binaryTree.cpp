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
//! using recursion
node *buildTree(node *root)
{
    cout << "Enter the Data: " << endl;
    int data;
    cin >> data;
    root = new node(data);

    if (data == -1)
        return NULL;

    cout << "Enter the data for inserting in left of " << data << endl;
    root->left = buildTree(root->left);
    cout << "Enter the data for inserting in right of " << data << endl;
    root->right = buildTree(root->right);

    return root;
}

//! using vector
//* Function to Build Tree
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
        node *currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N")
        {

            // Create the left child for the current node
            currNode->left = new node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
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
            currNode->right = new node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}

//! using recursion
// this algo is use when you need to enter
void levelOrderTraversal(node *root)
{
    queue<node *> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        node *temp = q.front();
        q.pop();

        if (temp == NULL)
        {
            // previous level traverse is complete
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

void LOT(node *root)
{
    queue<node *> q;
    q.push(root);

    while (!q.empty())
    {
        node *temp = q.front();
        cout << temp->data << " ";
        q.pop();
        if (temp->left)
            q.push(temp->left);

        if (temp->right)
            q.push(temp->right);
    }
}
void reverseLevelOrder(node *root)
{
    stack<node *> s;
    queue<node *> q;

    q.push(root);

    while (!q.empty())
    {
        root = q.front();
        q.pop();
        s.push(root);

        if (root->left)
            q.push(root->left);
        if (root->right)
            q.push(root->right);
    }

    while (!s.empty())
    {
        root = s.top();
        cout << root->data << " ";
        /* when vector is use only this line is needed
        ans.push_back(root->data);*/
        s.pop();
    }
}

//! using vector
vector<int> levelOrder(node *root)
{
    // Your code here
    vector<int> res;

    // if node is null, we return the list.
    if (root == NULL)
        return res;

    // creating an empty queue for level order traversal.
    queue<node *> q;

    q.push(root);

    while (q.empty() == false)
    {
        // storing front element of queue in list and removing it from queue.
        node *temp = q.front();
        res.push_back(temp->data);
        q.pop();

        // storing the left child of the parent node in queue.
        if (temp->left != NULL)
            q.push(temp->left);

        // storing the right child of the parent node in queue.
        if (temp->right != NULL)
            q.push(temp->right);
    }
    // returning the list.
    return res;
}

void inOrder(node *root)
{
    if (root == NULL)
        return;
    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}
void preOrder(node *root)
{
    if (root == NULL)
        return;
    cout << root->data << " ";

    preOrder(root->left);
    preOrder(root->right);
}
void postOrder(node *root)
{
    if (root == NULL)
        return;
    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << " ";
}

void buildFromLevelOrder(node *&root)
{
    queue<node *> q;
    cout << "enter the data for root " << endl;
    int data;
    cin >> data;
    root = new node(data);
    q.push(root);

    while (!q.empty())
    {
        node *temp = q.front();
        q.pop();

        cout << "enter left node for: " << temp->data << endl;
        int leftData;
        cin >> leftData;

        if (leftData != -1)
        {
            temp->left = new node(leftData);
            q.push(temp->left);
        }

        cout << "enter right node for: " << temp->data << endl;
        int rightData;
        cin >> rightData;

        if (rightData != -1)
        {
            temp->right = new node(rightData);
            q.push(temp->right);
        }
    }
}

int main()
{
    node *root = NULL;

    // 1 3 5 7 11 17 -1 -1 -1 -1 -1 -1 -1
    // buildFromLevelOrder(root);
    // levelOrderTraversal(root);

    // // creating tree
    root = buildTree(root);

    // 1 3 7 -1 -1 11 -1  -1 5 17 -1 -1 -1
    // // level order
    cout << "printing the level order traversal output " << endl;
    LOT(root);
    cout << endl;
    reverseLevelOrder(root);

    // cout << "inorder traversal : ";
    // inOrder(root);
    // cout << endl;

    // cout << "post order traversal : ";
    // postOrder(root);

    // cout << endl;

    // cout << "pre order traversal : ";
    // preOrder(root);

    return 0;
}

// int main()
// {

//     string s;
//     getline(cin, s);
//     node *root = buildTree(s);

//     vector<int> res = levelOrder(root);
//     for (int i : res)
//         cout << i << " ";
//     cout << endl;

//     return 0;
// }
/*
class Solution
{
public:
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        vector<vector<int>> ans;
        if (!root)
            return ans;
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty())
        {
            int sz = q.size();
            vector<int> v;
            while (sz--)
            {
                TreeNode *f = q.front();
                v.push_back(q.front()->val);
                q.pop();
                if (f->left)
                    q.push(f->left);
                if (f->right)
                    q.push(f->right);
            }
            ans.push_back(v);
        }
        return ans;
    }
};
*/