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
    void DFS(TreeNode *node, int current_sum, int &sum)
    {
        // 過程中incremental增加, 如果把全部數字save起來最後面相加的話, 會超過int, 因為很多數字可能為0
        // current_sum代表一條路線的node累加
        current_sum = current_sum * 10 + node->val;

        // Arrive the leaf
        if (!node->left && !node->right)
        {
            // 將一條路線的sum加到Global的sum
            sum += current_sum;
        }
        if (node->left)
            DFS(node->left, current_sum, sum);
        if (node->right)
            DFS(node->right, current_sum, sum);
    }
    int sumNumbers(TreeNode *root)
    {
        if (!root)
            return 0;
        int sum = 0;
        DFS(root, 0, sum);
        return sum;
    }
};
// @lc code=end
