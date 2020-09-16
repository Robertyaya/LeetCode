/*
 * @lc app=leetcode id=236 lang=cpp
 *
 * [236] Lowest Common Ancestor of a Binary Tree
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
     * 解題流程: 如果left and right都存在也就是題目中example1, 則return 3
     * 如果只有其中一個存在, 則return存在的那個node
     * 目標就是要找到left and right都存在的情況, 沒有的話則會一直return target node回到上一層
     * 基本概念就是, 不用確定到底target node在哪一層, 只要知道他到底在哪個subtree的right subtree or left subtree
     * ex: 假設p=6, q=7
     * 當root為5時
     * left會return 6
     * right則是會recursive到最下面那一層才會找到
     * 但當找到之後會一直return回去, 我們就能確定7是在5的right subtree中出現
     * 因此此時當root為5時, 此時left and right都不為null, 因此5就是共同的ancestor
     */
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        if (!root)
            return nullptr;
        // 遇到target則return node
        if (root->val == p->val || root->val == q->val)
            return root;
        TreeNode *left = lowestCommonAncestor(root->left, p, q);
        TreeNode *right = lowestCommonAncestor(root->right, p, q);

        // 代表各從兩邊來, 因此ancestor一定就是現在root
        if (left && right)
            return root;

        // 如果right存在則return right, 反之也有可能都不存在或是left存在, 都return left
        return right ? right : left;
    }
};
// @lc code=end
