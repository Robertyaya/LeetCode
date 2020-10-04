/*
 * @lc app=leetcode id=100 lang=cpp
 *
 * [100] Same Tree
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
    bool Check(TreeNode *p, TreeNode *q)
    {
        // Base case
        if (!p && !q)
            return true;

        // 過程中滿足此條件就會return, 代表不是samre tree
        if ((p == nullptr && q != nullptr) || (p != nullptr && q == nullptr) || (p->val != q->val))
            return false;

        // 會遍歷所有node, 過程中如果有滿足上面那兩個判斷, 則會return 回來
        return Check(p->left, q->left) && Check(p->right, q->right);
    }
    bool isSameTree(TreeNode *p, TreeNode *q)
    {
        return Check(p, q);
    }
};
// @lc code=end
