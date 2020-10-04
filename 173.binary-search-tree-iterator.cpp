/*
 * @lc app=leetcode id=173 lang=cpp
 *
 * [173] Binary Search Tree Iterator
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
class BSTIterator
{
    /**
     * Iterative inorder traverse
     */
public:
    BSTIterator(TreeNode *root)
    {
        while (root)
        {
            sta.push(root);
            root = root->left;
        }
    }

    /** @return the next smallest number */
    int next()
    {
        TreeNode *todo = sta.top();
        sta.pop();
        int value = todo->val;
        if (todo->right)
        {
            todo = todo->right;
            while (todo)
            {
                sta.push(todo);
                todo = todo->left;
            }
        }
        return value;
    }

    /** @return whether we have a next smallest number */
    bool hasNext()
    {
        return !sta.empty();
    }

private:
    stack<TreeNode *> sta;
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
// @lc code=end
