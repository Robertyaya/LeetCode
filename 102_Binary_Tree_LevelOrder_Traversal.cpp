#include <bits/stdc++.h>
using namespace std;
/**
 * Time: O(N), Space: O(N)
 * 解題流程: 此法更為簡潔, 每次強迫都是一層一層push_back到current_level裡面
 * 做完這層才進入到下一層
 */

vector<vector<int>> levelOrder(TreeNode *root)
{
    if (!root)
        return {};
    vector<vector<int>> output;
    queue<TreeNode *> que;
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
    return output;
}
/**
 * Time: O(N), Space: O(N) (Record the output data)
 * 解題流程: 此題為level-order變形, 要一層一層分開, 所以關鍵在於如何將同一層的treenode放在一個vector裡面
 * 塞到output中
 * 因此我們修改原本的queue為同時紀錄treenode以及此treenode所在的層數
 * 有了treenode所在的層數我們就可以判斷如果pop出來的node和current level相同則代表是同一層, 因此將其放在一起
 * 如果pop出來的node和current level不同層了, 代表現在level-order traverse已進入到下一層
 * 因此update現在的current_level並將上一層的所有node塞到output中
 */
vector<vector<int>> levelOrder(TreeNode *root)
{
    // Edge case
    if (!root)
        return {};

    // Rcord the output
    vector<vector<int>> output;

    // Record the treenode and its level index
    queue<pair<TreeNode *, int>> que;
    int current_level = 1;
    que.push(make_pair(root, current_level));

    vector<int> current_level_node;
    while (!que.empty())
    {
        pair<TreeNode *, int> current_pair = que.front();
        que.pop();

        TreeNode *current_node = current_pair.first;
        if (current_pair.second == current_level)
            current_level_node.push_back(current_node->val);
        else
        {
            // Enter to next level, update the current_level
            current_level = current_pair.second;
            // Push_back the previous level to output
            output.push_back(current_level_node);
            // Reset the current_level node
            current_level_node.clear();
            // Put the current node into vector
            current_level_node.push_back(current_node->val);
        }

        if (current_node->left)
            que.push(make_pair(current_node->left, current_level + 1));
        if (current_node->right)
            que.push(make_pair(current_node->right, current_level + 1));
    }

    output.push_back(current_level_node);
    return output;
}
