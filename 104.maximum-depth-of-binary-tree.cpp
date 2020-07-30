/*
 * @lc app=leetcode id=104 lang=cpp
 *
 * [104] Maximum Depth of Binary Tree
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
     * The num of tree node is N, logN is the height of tree
     * Time: O(N), Space: O(logN)
     */
public:
    int DFS(TreeNode *node)
    {
        if (!node)
            return 0;
        return max(DFS(node->left) + 1, DFS(node->right) + 1);
    }
    int maxDepth(TreeNode *root)
    {
        int depth = 1;
        return DFS(root);
    }
};
// @lc code=end
