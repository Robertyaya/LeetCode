/*
 * @lc app=leetcode id=538 lang=cpp
 *
 * [538] Convert BST to Greater Tree
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
 */
    void Traverse(TreeNode *node, int &sum)
    {
        if (!node)
            return;
        // Inorder traverse, 從右邊到左邊
        Traverse(node->right, sum);
        node->val += sum;
        sum = node->val;
        Traverse(node->left, sum);
    }
    TreeNode *convertBST(TreeNode *root)
    {
        int sum = 0;
        Traverse(root, sum);
        return root;
    }
};
// @lc code=end
