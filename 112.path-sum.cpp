/*
 * @lc app=leetcode id=112 lang=cpp
 *
 * [112] Path Sum
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
    /**
     * Time: O(N), Space: O(logN)
     */
public:
    bool DFS(TreeNode *node, int sum)
    {
        if (!node)
            return false;

        if (!node->left && !node->right && node->val == sum)
            return true;

        return DFS(node->left, sum - node->val) || DFS(node->right, sum - node->val);
    }
    bool hasPathSum(TreeNode *root, int sum)
    {
        return DFS(root, sum);
    }
};
// @lc code=end
