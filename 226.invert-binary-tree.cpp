/*
 * @lc app=leetcode id=226 lang=cpp
 *
 * [226] Invert Binary Tree
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
     * 解題流程: 此題直接利用整個subtree交換, 而不是單純數字交換
     */
public:
    TreeNode *invertTree(TreeNode *root)
    {
        if (!root)
            return root;

        TreeNode *left = root->left;
        TreeNode *right = root->right;
        root->left = right; // 左邊接到right subtree
        root->right = left; // 右邊接到left subtree

        // Traverse下去
        if (root->left)
            invertTree(root->left);
        if (root->right)
            invertTree(root->right);
        return root;
    }
};
// @lc code=end
