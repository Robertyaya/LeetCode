/*
 * @lc app=leetcode id=199 lang=cpp
 *
 * [199] Binary Tree Right Side View
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    /**
 * Time: O(N), Space: O(logN)
 * 利用preorder, level用來判斷那一層是否有數字加入了
 */
    void Preorder(TreeNode *node, vector<int> &res, int level)
    {
        if (!node)
            return;

        // This level not yet put the value in res
        if (level > res.size())
            res.push_back(node->val);
        Preorder(node->right, res, level + 1);
        Preorder(node->left, res, level + 1);
    }
    vector<int> rightSideView(TreeNode *root)
    {
        vector<int> res;
        Preorder(root, res, 1);
        return res;
    }
    /**
 * Time: O(N), Space: O(N)
 * 利用level-order, 一層一層traverse, 當i==0代表到達那一層最右邊的那個node, 則將其放入res中
 */
    vector<int> rightSideView(TreeNode *root)
    {
        if (!root)
            return {};
        vector<int> res;
        queue<TreeNode *> que;
        que.push(root);
        while (!que.empty())
        {
            for (int i = que.size() - 1; i >= 0; i--)
            {
                TreeNode *node = que.front();
                que.pop();
                // 到達最右邊那個node
                if (i == 0)
                    res.push_back(node->val);

                if (node->left)
                    que.push(node->left);
                if (node->right)
                    que.push(node->right);
            }
        }
        return res;
    }
};
// @lc code=end
