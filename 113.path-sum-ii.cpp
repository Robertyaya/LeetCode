/*
 * @lc app=leetcode id=113 lang=cpp
 *
 * [113] Path Sum II
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
    void DFS(TreeNode *node, int sum, vector<vector<int>> &res, vector<int> &vec)
    {
        if (!node)
            return;

        vec.push_back(node->val);
        // 剛好抵達leaf
        if (!node->left && !node->right && sum == node->val)
        {
            res.push_back(vec);
            vec.pop_back();
            return;
        }

        DFS(node->left, sum - node->val, res, vec);
        DFS(node->right, sum - node->val, res, vec);
        vec.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode *root, int sum)
    {
        vector<vector<int>> res;
        vector<int> vec;
        DFS(root, sum, res, vec);
        return res;
    }
};
// @lc code=end
