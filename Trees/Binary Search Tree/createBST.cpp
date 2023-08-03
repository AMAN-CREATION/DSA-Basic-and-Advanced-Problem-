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

void levelOrderTraversal(Node *root)
{
    queue<Node *> q;
    q.push(root);
    q.push(NULL);
    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();
        if (temp == NULL)
        {
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

void inOrder(Node *root)
{
    if (root == NULL)
        return;

    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}

void preOrder(Node *root)
{
    if (root == NULL)
        return;

    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}

void postOrder(Node *root)
{
    if (root == NULL)
        return;

    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << " ";
}

Node *searchBST(Node *&root, int val)
{
    Node *temp = root;

    while (temp != NULL)
    {
        if (temp->data == val)
            return temp;
        if (temp->data > val)
            temp = temp->left;
        else
            temp = temp->right;
    }
    return temp;
}

Node *search(Node *&root, int val)
{
    if (root == NULL || root->data == val)
        return root;

    if (root->data < val)
        return searchBST(root->right, val);

    return searchBST(root->left, val);
}

bool searchInBST(Node *root, int data)
{
    Node *temp = root;
    while (temp != NULL)
    {
        if (temp->data == data)
            return true;

        if (temp->data > data)
            temp = temp->left;
        else
            temp = temp->right;
    }
    return false;
}

// time-complexity-o(longn)&& deletion &&searching ;
Node *insertIntoBST(Node *&root, int d)
{
    if (root == NULL)
    {
        root = new Node(d);
        return root;
    }
    if (d > root->data)
    {
        // insert in right part
        root->right = insertIntoBST(root->right, d);
    }
    else
    {
        // insert in left part
        root->left = insertIntoBST(root->left, d);
    }
    return root;
}

Node *minimum(Node *root)
{
    Node *temp = root;
    while (temp->left != NULL)
    {
        temp = temp->left;
    }
    return temp;
}

Node *maximum(Node *root)
{
    Node *temp = root;
    while (temp->right != NULL)
        temp = temp->right;

    return temp;
}

Node *deleteFromBST(Node *root, int val)
{
    // base case
    if (root == NULL)
        return NULL;

    if (root->data == val)
    {
        //* zero child
        if (root->left == NULL && root->right == NULL)
        {
            delete root;
            return NULL;
        }

        //* one child
        // left child
        if (root->left != NULL && root->right == NULL)
        {
            Node *temp = root->left;
            delete root;
            return temp;
        }

        // right child
        if (root->left == NULL && root->right != NULL)
        {
            Node *temp = root->right;
            delete root;
            return temp;
        }

        //* two child
        if (root->left != NULL && root->right != NULL)
        {
            int mini = minimum(root->right)->data;
            // copy data in root node;
            root->data = mini;
            root->right = deleteFromBST(root->right, mini);
            return root;
        }
    }
    else if (root->data > val)
    {
        // recursive call in left part
        root->left = deleteFromBST(root->left, val);
        return root;
    }
    else
    {
        /// recursive call in right part
        root->right = deleteFromBST(root->right, val);
        return root;
    }
}

Node *inOrderSuccessor(Node *root, Node *x)
{
    Node *suc = NULL;
    while (root != NULL)
    {
        if (x->data >= root->data)
            root = root->right;
        else
        {
            suc = root;
            root = root->left;
        }
    }
    return suc;
}

Node *inOrderPredecessor(Node *&root, Node *x)
{
    Node *pred = NULL;
    while (root != NULL)
    {
        if (x->data <= root->data)
            root = root->left;
        else
        {
            pred = root;
            root = root->right;
        }
    }
    return pred;
}

void findPredSucc(Node *root, Node *&pred, Node *&succ, int key)
{
    if (root == NULL)
        return;

    if (root->data == key)
    {
        if (root->left != NULL)
        {
            Node *temp = root->left;
            while (temp->right)
                temp = temp->right;
            pred = temp;
        }
        if (root->left != NULL)
        {
            Node *temp = root->right;
            while (temp->left)
                temp = temp->left;
            succ = temp;
        }
        return;
    }

    if (root->data > key)
    {
        succ = root;
        findPredSucc(root->left, pred, succ, key);
    }
    else
    {
        pred = root;
        findPredSucc(root->right, pred, succ, key);
    }
}

void takeInput(Node *&root)
{
    int data;
    cin >> data;

    while (data != -1)
    {
        insertIntoBST(root, data);
        cin >> data;
    }
}

int main()
{
    Node *root = NULL;

    // 10 8 21 7 27 5 4 3 -1
    // 50 20 70 10 30 90 110 -1
    cout << "Enter data to create BST " << endl;
    takeInput(root);
    cout << endl;

    cout << "Printing the BST" << endl;
    levelOrderTraversal(root);
    cout << endl;

    cout << "minimum value is " << minimum(root)->data << endl;
    cout << "maximum value is " << maximum(root)->data << endl;

    // int s;
    // cin >> s;

    // if (searchInBST(root, s))
    //     cout << "Node is present";
    // else
    //     cout << "Node is not present";

    cout << "inOrder Traversal ";
    inOrder(root);
    cout << endl;
    cout << "preOrder Traversal ";
    preOrder(root);
    cout << endl;
    cout << "postOrder Traversal ";
    postOrder(root);
    cout << endl;

    //! finding successor
    int k;
    cin >> k;
    Node *kNode = searchBST(root, k);

    Node *src = inOrderSuccessor(root, kNode);
    if (src == NULL)
        return -1;
    else
    {
        cout << "InOrder successor is ";
        cout << src->data << endl;
    }
    Node *pred = inOrderPredecessor(root, kNode);
    if (pred == NULL)
        return -1;
    else
    {
        cout << "InOrder Predecessor is ";
        cout << pred->data << endl;
    }

    // cout << endl;
    //! deletion code
    // root = deleteFromBST(root, 8);

    // cout << endl;
    // cout << "Printing the BST" << endl;
    // levelOrderTraversal(root);
    // cout << endl;

    // cout << "minimum value is " << minimum(root)->data << endl;
    // cout << "maximum value is " << maximum(root)->data << endl;

    // // int s;
    // // cin >> s;

    // // if (searchInBST(root, s))
    // //     cout << "Node is present";
    // // else
    // //     cout << "Node is not present";

    // cout << "inOrder Traversal ";
    // inOrder(root);
    // cout << endl;
    // cout << "preOrder Traversal ";
    // preOrder(root);
    // cout << endl;
    // cout << "postOrder Traversal ";
    // postOrder(root);

    return 0;
}