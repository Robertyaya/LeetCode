/*
 * @lc app=leetcode id=222 lang=cpp
 *
 * [222] Count Complete Tree Nodes
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
     * 解題流程: 此題可以traverse所有的node來計算
     * 但這邊利用complete binary tree的性質, 每一層都是滿的, 最後一層沒滿的話也會往最左邊靠
     * 因此如果整個tree到左邊node的高度和到最右邊node的高度相等， 代表此tree為Full binary tree, 也就是全滿, 因此node數為2^h-1
     * 
     */
public:
    int countNodes(TreeNode *root)
    {
        if (!root)
            return 0;
        TreeNode *left_node = root;
        TreeNode *right_node = root;
        int l = 0;
        int r = 0;
        while (left_node)
        {
            left_node = left_node->left;
            l++;
        }
        while (right_node)
        {
            right_node = right_node->right;
            r++;
        }

        // 代表此sub tree為full binary tree, 全滿
        if (l == r)
            return pow(2, l) - 1;

        // 如果current subtree沒滿, 則recursive下去找到滿的後再return回來, 所有subtree都會滿足complete binary tree的條件
        return countNodes(root->left) + countNodes(root->right) + 1;
    }
};
// @lc code=end
