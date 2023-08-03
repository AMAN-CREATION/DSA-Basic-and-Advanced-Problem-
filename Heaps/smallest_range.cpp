#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    int rowIndex;
    int colIndex;

    Node(int d, int row, int col)
    {
        data = d;
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

vector<int> smallestRange(vector<vector<int>> &nums)
{
    priority_queue<Node *, vector<Node *>, compare> minHeap;
    int mini = INT_MAX, maxi = INT_MIN;

    //*step 1: create a min heap for starting element-
    //*of each list and tracking min/max value.
    int k = nums.size();
    for (int i = 0; i < k; i++)
    {
        int element = nums[i][0];
        mini = min(mini, element);
        maxi = max(maxi, element);
        minHeap.push(new Node(element, i, 0));
    }

    int start = mini, end = maxi;

    while (!minHeap.empty())
    {
        Node *temp = minHeap.top();
        minHeap.pop();

        mini = temp->data;

        //*range or answer updation
        if (maxi - mini < end - start)
        {
            start = mini;
            end = maxi;
        }

        //* if next element exist;
        int n = nums[temp->rowIndex].size();
        if (temp->colIndex + 1 < n)
        {
            int element = nums[temp->rowIndex][temp->colIndex + 1];
            maxi = max(maxi, element);
            minHeap.push(new Node(element, temp->rowIndex, temp->colIndex + 1));
        }
        else

        {
            //*if next element does not exit.
            break;
        }
    }
    //*returning the difference of range value.
    vector<int> ans;
    ans.push_back(start);
    ans.push_back(end);
    return ans;

    /*
    if return type is int
    return (end-start+1);
    */
}

int main()
{
    vector<vector<int>> arr = {{4, 10, 15, 24, 26},
                               {0, 9, 12, 20},
                               {5, 18, 22, 30},
                               {20, 24}};

    vector<int> ans = smallestRange(arr);
    for (auto i : ans)
    {
        cout << i << " ";
    }
}
/*
Input: nums = [[4,10,15,24,26],[0,9,12,20],[5,18,22,30]]
Output: [20,24]
*/