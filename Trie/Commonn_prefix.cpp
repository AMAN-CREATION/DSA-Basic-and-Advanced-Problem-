#include <bits/stdc++.h>
using namespace std;

// ! O(m*n);
class TrieNode
{
public:
    char data;
    TrieNode *children[26];
    int countChild;
    bool isTerminal;

    TrieNode(char ch)
    {
        data = ch;
        for (int i = 0; i < 26; i++)
        {
            children[i] = NULL;
        }
        countChild = 0;
        isTerminal = false;
    }
};

class Trie
{
public:
    TrieNode *root;

    Trie(char ch)
    {
        root = new TrieNode(ch);
    }

    void insertUtil(TrieNode *root, string ch)
    {
        if (ch.length() == 0)
        {
            root->isTerminal = true;
            return;
        }

        int index = ch[0] - 'a';
        TrieNode *child;

        if (root->children[index] != NULL)
            child = root->children[index];
        else
        {
            child = new TrieNode(ch[0]);
            root->countChild++;
            root->children[index] = child;
        }
        insertUtil(child, ch.substr(1));
    }

    void insertWord(string ch)
    {
        insertUtil(root, ch);
    }

    void LCP(string str, string &ans)
    {
        for (int i = 0; i < str.length(); i++)
        {
            char ch = str[i];

            if (root->countChild == 1)
            {
                ans.push_back(ch);

                int index = ch - 'a';
                root = root->children[index];
            }
            else
                break;

            if (root->isTerminal)
                break;
        }
    }
};

//! solution-2
string longestCommonPrefix(vector<string> &strs)
{
    if (strs.size() == 0)
        return "";
    if (strs.size() == 1)
        return "";

    Trie *t = new Trie('\0');

    for (auto word : strs)
    {
        //* our trie doesn't support empty string so need to handle explicitly
        if (word.empty())
            return "";
        t->insertWord(word);
    }

    string first = strs[0];
    string ans = "";

    t->LCP(first, ans);
    return ans;
}

string LCP(vector<string> &str)
{
    string ans = "";
    for (int i = 0; i < str[0].length(); i++)
    {
        char ch = str[0][i];

        bool match = true;

        for (int j = 1; j < str.size(); j++)
        {
            if (str[j].size() < 1 || ch != str[j][i])
            {
                match = false;
                break;
            }
        }
        if (match == false)
            break;
        else
            ans.push_back(ch);
    }
    return ans;
}

int main()
{
    vector<string> arr = {"flower", "flow", "flight"};

    cout << LCP(arr);
}