/*
 * @lc app=leetcode id=129 lang=cpp
 *
 * [129] Sum Root to Leaf Numbers
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
     * The num of total node is N
     * Time: O(N), Space; O(logN)
     * 
     */
public:
    void DFS(TreeNode *node, int &sum, int temp)
    {
        temp += node->val; // 加上current node value

        // Arrive the leaf
        if (!node->left && !node->right)
        {
            sum += temp;
            return;
        }
        if (node->left)
            DFS(node->left, sum, 10 * temp);
        if (node->right)
            DFS(node->right, sum, 10 * temp);
    }
    int sumNumbers(TreeNode *root)
    {
        if (!root)
            return 0;

        // 紀錄total sum
        int sum = 0;
        DFS(root, sum, 0);
        return sum;
    }
};
// @lc code=end
