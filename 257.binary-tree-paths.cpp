/*
 * @lc app=leetcode id=257 lang=cpp
 *
 * [257] Binary Tree Paths
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
    void Path(TreeNode *node, vector<string> &vec, string str)
    {
        // Represent arrive the leaf
        if (!node->left && !node->right)
        {
            str += to_string(node->val);
            vec.push_back(str);
            return;
        }

        string temp;
        temp = to_string(node->val);
        temp += "->";
        if (node->left)
            Path(node->left, vec, str + temp);
        if (node->right)
            Path(node->right, vec, str + temp);
    }
    vector<string> binaryTreePaths(TreeNode *root)
    {
        if (!root)
            return {};
        vector<string> vec;
        Path(root, vec, "");
        return vec;
    }
};
// @lc code=end
