/*
 * @lc app=leetcode id=208 lang=cpp
 *
 * [208] Implement Trie (Prefix Tree)
 */

// @lc code=start
class TrieNode
{
public:
    TrieNode *child[26];
    bool isEnd;
    TrieNode()
    {
        isEnd = false;
        for (int i = 0; i < 26; i++)
            child[i] = nullptr;
    }
};
class Trie
{
public:
    /** Initialize your data structure here. */
    Trie()
    {
        root = new TrieNode();
    }

    /** Inserts a word into the trie. */
    void insert(string word)
    {
        TrieNode *node = root;
        for (auto &s : word)
        {
            // 0~25之間
            int index = s - 'a';

            // 代表此字元尚未被加入
            if (!node->child[index])
            {
                node->child[index] = new TrieNode();
            }
            node = node->child[index];
        }
        node->isEnd = true;
    }

    /** Returns if the word is in the trie. */
    bool search(string word)
    {
        TrieNode *node = root;
        for (auto &v : word)
        {
            int index = v - 'a';
            if (!node->child[index])
                return false;

            node = node->child[index];
        }
        return node->isEnd;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix)
    {
        TrieNode *node = root;
        for (auto &v : prefix)
        {
            int index = v - 'a';
            if (!node->child[index])
                return false;

            node = node->child[index];
        }
        return true;
    }

    TrieNode *root;
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
// @lc code=end
