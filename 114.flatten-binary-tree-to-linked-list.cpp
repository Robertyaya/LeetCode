/*
 * @lc app=leetcode id=114 lang=cpp
 *
 * [114] Flatten Binary Tree to Linked List
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
    void flatten(TreeNode *root)
    {
        if (!root)
            return;
        if (root->left)
            flatten(root->left);
        if (root->right)
            flatten(root->right);

        // 將right subtree記錄下來
        TreeNode *temp = root->right;

        // 先接上left node
        root->right = root->left;
        root->left = NULL;

        // 走到底之後再接原本的right node
        while (root->right)
            root = root->right;
        root->right = temp;
    }
};
// @lc code=end
