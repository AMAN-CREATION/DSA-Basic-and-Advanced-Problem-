//! Merge k Sorted Arrays
#include <bits/stdc++.h>
using namespace std;

//* Expected Time Complexity: O(n*k Log(K))
//* Expected Auxiliary Space: O(n*k)

class Node
{
public:
    int data;
    int rowIndex;
    int colIndex;
    Node(int data, int row, int col)
    {
        this->data = data;
        rowIndex = row;
        colIndex = col;
    }
};

class compare
{
public:
    bool operator()(Node *a, Node *b)
    {
        return a->data > b->data;
    }
};

vector<int> mergeKArrays(vector<vector<int>> &arr, int k)
{
    priority_queue<Node *, vector<Node *>, compare> minHeap;

    //* step 1: insert all k first element in array

    for (int i = 0; i < k; i++)
    {
        Node *temp = new Node(arr[i][0], i, 0);
        minHeap.push(temp);
    }
    vector<int> ans;

    while (!minHeap.empty())
    {
        Node *temp = minHeap.top();

        ans.push_back(temp->data);
        minHeap.pop();

        int i = temp->rowIndex;
        int j = temp->colIndex;

        if (j + 1 < arr[i].size())
        {
            Node *next = new Node(arr[i][j + 1], i, j + 1);
            minHeap.push(next);
        }
    }
    return ans;
}

int main()
{
    vector<vector<int>> arr = {{1, 2, 3, 4},
                               {2, 2, 3, 4},
                               {5, 5, 6, 6},
                               {7, 8, 9, 9}};
    int k = 4;
    vector<int> ans = mergeKArrays(arr, k);
    for (int i = 0; i < k * k; i++)
    {
        cout << ans[i] << " ";
    }
}

/*
Input:
K = 4
arr[][]={{1,2,3,4},{2,2,3,4},
         {5,5,6,6},{7,8,9,9}}
Output:
1 2 2 2 3 3 4 4 5 5 6 6 7 8 9 9
*/