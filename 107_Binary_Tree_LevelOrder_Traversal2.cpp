#include <bits/stdc++.h>
using namespace std;
/**
 * Time: O(N), Space: O(N)
 * 解題流程: 同problem102, 只是最後面需要reverse結果
 */
vector<vector<int>> levelOrderBottom(TreeNode *root)
{
    if (!root)
        return {};

    queue<TreeNode *> que;
    vector<vector<int>> output;
    que.push(root);
    while (!que.empty())
    {
        vector<int> current_level;
        for (int i = que.size(); i >= 1; i--)
        {
            TreeNode *node = que.front();
            que.pop();
            current_level.push_back(node->val);
            if (node->left)
                que.push(node->left);
            if (node->right)
                que.push(node->right);
        }
        output.push_back(current_level);
    }

    reverse(output.begin(), output.end());

    return output;
}