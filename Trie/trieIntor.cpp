#include <bits/stdc++.h>
using namespace std;

/*
! Time complexity:
    * insertion = O(L);
    * searching = O(L);
    * Deletion = O(L);
    ! L -> is length of word
*/

class TrieNode
{
public:
    char data;
    TrieNode *children[26];
    bool isTerminal;

    TrieNode(char ch)
    {
        data = ch;
        for (int i = 0; i < 26; i++)
        {
            children[i] = NULL;
        }
        isTerminal = false;
    }
};

class Trie
{
public:
    TrieNode *root;

    Trie()
    {
        //*root node is NULL;
        root = new TrieNode('\0');
    }

    //! insertion

    void insertUtil(TrieNode *root, string word)
    {
        // base case
        if (word.length() == 0)
        {
            root->isTerminal = true;
            return;
        }
        //*assumption, word will be in CAPS
        int index = word[0] - 'A';
        TrieNode *child;

        //*present
        if (root->children[index] != NULL)
        {
            child = root->children[index];
        }
        else
        { //*absent
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }

        // recursive call
        insertUtil(child, word.substr(1));
    }

    void insertWord(string word)
    {
        insertUtil(root, word);
    }

    //! Searching
    bool searchUtil(TrieNode *root, string word)
    {
        // base case
        if (word.length() == 0)
            return root->isTerminal;

        int index = word[0] - 'A';
        TrieNode *child;

        //*present
        if (root->children[index] != NULL)
            child = root->children[index];
        else
            return false;

        return searchUtil(child, word.substr(1));
    }

    bool searchWord(string word)
    {
        return searchUtil(root, word);
    }

    bool prefixUtil(TrieNode *root, string word)
    {
        // base case
        if (word.length() == 0)
            return true;

        int index = word[0] - 'A';
        TrieNode *child;

        //*present
        if (root->children[index] != NULL)
            child = root->children[index];
        else
            return false;

        return prefixUtil(child, word.substr(1));
    }

    bool startsWith(string prefix)
    {
        return prefixUtil(root, prefix);
    }

    //! Remove
};

int main()
{
    Trie *t = new Trie();
    t->insertWord("ARM");
    t->insertWord("DO");
    t->insertWord("TIME");

    cout << "Present or Not " << t->searchWord("ARM") << endl;
    cout << "Prefix Present or Not " << t->startsWith("AR") << endl;

    return 0;
}