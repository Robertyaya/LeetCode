/*
 * @lc app=leetcode id=98 lang=cpp
 *
 * [98] Validate Binary Search Tree
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
 * 解題流程: 過程中去update max_value and min_value, 違反條件則return false
 * recursive就直接return
 */
    bool Check(TreeNode *node, long min_value, long max_value)
    {
        if (!node)
            return true;

        // 代表違反條件, 不是binary search tree
        if (node->val <= min_value || node->val >= max_value)
            return false;

        // update max_value, min_value
        return Check(node->left, min_value, node->val) && Check(node->right, node->val, max_value);
    }
    bool isValidBST(TreeNode *root)
    {
        // 因為node的數字可能剛好跟INT_MAX相同
        long min_value = LONG_MIN;
        long max_value = LONG_MAX;
        return Check(root, min_value, max_value);
    }
    /**
 * Method 1: Use inorder to do
 * Time: O(N), Space: O(logN)
 * Inorder會從小排到大, 所以只要違反這個原則, 代表就不是Binary search tree
 */
    bool Inorder(TreeNode *node, int &prev)
    {
        if (!node)
            return true;

        if (!Inorder(node->left, prev))
            return false;

        if (prev == -1)
            prev = node->val;
        else
        {
            if (prev >= node->val)
                return false;
            prev = node->val;
        }

        if (!Inorder(node->right, prev))
            return false;

        return true;
    }
    bool isValidBST(TreeNode *root)
    {
        int prev = -1;
        return Inorder(root, prev);
    }
};
// @lc code=end
