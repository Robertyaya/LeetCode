/*
 * @lc app=leetcode id=211 lang=cpp
 *
 * [211] Add and Search Word - Data structure design
 */

// @lc code=start
class WordNode
{
public:
    WordNode()
    {
        isEnd = false;
        for (int i = 0; i < 26; i++)
            child[i] = nullptr;
    }
    WordNode *child[26];
    bool isEnd;
};
class WordDictionary
{
public:
    /**
 * Trie結合DFS
 */
    /** Initialize your data structure here. */
    WordDictionary()
    {
        root = new WordNode();
    }

    /** Adds a word into the data structure. */
    void addWord(string word)
    {
        WordNode *node = root;
        for (auto &v : word)
        {
            int index = v - 'a';
            if (!node->child[index])
                node->child[index] = new WordNode();
            node = node->child[index];
        }
        node->isEnd = true;
    }

    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word)
    {
        WordNode *node = root;
        return DFS(node, word, 0);
    }

    bool DFS(WordNode *node, string &word, int i)
    {
        // The last element
        if (i == word.size())
        {
            return node->isEnd;
        }

        // 當char為'.'時可以用任何一個char替代, 只要在child裡面有, 都必須去Search, 所以這邊要traverse所有可能
        if (word[i] == '.')
        {
            for (int k = 0; k < 26; k++)
            {
                if (node->child[k])
                {
                    // 因為要嘗試不同可能, 因此僅有當return true時, 才可以直接return true, 反之則換不同的路線繼續search
                    if (DFS(node->child[k], word, i + 1))
                        return true;
                }
            }
            return false;
        }
        else // 當char不為'.'時, 則跟一般的trie search一樣
        {
            int index = word[i] - 'a';
            if (!node->child[index]) // 沒有在child裡面, 直接return false;
                return false;
            else
                return DFS(node->child[index], word, i + 1);
        }

        return true;
    }

    WordNode *root;
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
// @lc code=end
