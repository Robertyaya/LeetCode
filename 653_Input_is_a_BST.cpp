#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

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

/**
 * Time: O(N) (We need to transverse whole tree in worst case)
 * Space: O(N) (We need to build the set to find the correspond value)
 * 解題流程: 利用DFS去recursive tranverse every node, 在過程中把node加入unorder_set中並且去確認diff = target - (current_node->value)有沒有在set中
 * DFS (inorder tranverse, preorder tranverse, postorder tranverse), in here we use the concept of pre-order tranverse
 */
class Solution
{
public:
    bool findTarget(TreeNode *root, int k)
    {
        unordered_set<int> set;
        return dfs(root, set, k);
    }

    bool dfs(TreeNode *current_node, unordered_set<int> &set, int k)
    {
        // Base condition
        if (current_node == nullptr)
            return false;

        int diff = k - current_node->val;
        if (set.count(diff))
            return true;
        set.insert(current_node->value);
        return dfs(current_node->left, set, k) || dfs(current_node->right, set, k);
    }
};