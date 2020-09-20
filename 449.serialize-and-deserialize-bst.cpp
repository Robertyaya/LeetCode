/*
 * @lc app=leetcode id=449 lang=cpp
 *
 * [449] Serialize and Deserialize BST
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec
{
public:
    // Encodes a tree to a single string.
    void Traver(TreeNode *node, string &res)
    {
        if (node == nullptr)
        {
            // 紀錄此時到達nullptr
            res += "$ ";
            return;
        }

        // 記得要空格, 這樣解碼時才能區隔數字
        string str = to_string(node->val) + " ";
        res += str;
        Traver(node->left, res);
        Traver(node->right, res);
    }
    string serialize(TreeNode *root)
    {
        if (!root)
            return "";

        // 利用string來編碼
        string res = "";
        Traver(root, res);
        return res;
    }

    TreeNode *Deserialize(queue<int> &que)
    {
        if (que.empty())
            return nullptr;
        if (que.front() == INT_MAX)
        {
            que.pop();
            return nullptr;
        }

        int value = que.front();
        que.pop();
        TreeNode *node = new TreeNode(value);
        node->left = Deserialize(que);
        node->right = Deserialize(que);
        return node;
    }

    // Decodes your encoded data to tree.
    TreeNode *deserialize(string data)
    {
        if (data.empty())
            return nullptr;

        // 利用queue來輔助解碼, 使用過的數字就pop出來
        queue<int> que;
        string str = "";
        for (int i = 0; i < data.size(); i++)
        {
            if (data[i] != ' ')
                str += data[i];
            else
            {
                if (str == "$") // INT_MAX用來區隔此時到達nullptr
                    que.push(INT_MAX);
                else
                    que.push(stoi(str));
                str = "";
            }
        }
        return Deserialize(que);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
// @lc code=end
