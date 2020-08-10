/*
 * @lc app=leetcode id=235 lang=cpp
 *
 * [235] Lowest Common Ancestor of a Binary Search Tree
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

class Solution
{
    /**
     * Time: O(N), Space: O(logN)
     * 解題流程: 此題為"Binary search tree"左邊node, 右邊node比較大
     * 此題有個關鍵概念, 如果p and q分別在左右兩邊, 那他們的LCA一定就會是中間的root
     * 
     */
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        // 當p跟q都在left subtree
        if (root->val > max(p->val, q->val))
            return lowestCommonAncestor(root->left, p, q);
        // 當p跟q都在right subtree
        else if (root->val < min(p->val, q->val))
            return lowestCommonAncestor(root->right, p, q);
        // 當p跟q在左右兩邊, 或是root等於其中一個
        else
            return root;
    }
};
// @lc code=end
