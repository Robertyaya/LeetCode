#include <bits/stdc++.h>
using namespace std;
/**
 * Time: O(N), Space: O(N)
 * 解題流程: 跟前面幾題一摸一樣, 只在於奇數層需要從right~left, 偶數層則是從left~right
 * 因此我們利用一個level去紀錄目前到了第幾層, 當目前為奇數層時, 則需要reverse目前的current_level vector
 * 但利用reverse的方法太慢, 等於要多做一步
 * 因此我們直接如果此時為奇數層, 那就直接從後面填回來就好, 這樣就可以省略掉reverse的時間
 * 
 */
vector<vector<int>> zigzagLevelOrder(TreeNode *root)
{
    if (!root)
        return {};

    vector<vector<int>> output;
    queue<TreeNode *> que;
    que.push(root);
    int level = 0;
    while (!que.empty())
    {
        vector<int> current_level;
        current_level.resize(que.size());
        int j = 0;
        for (int i = que.size(); i >= 1; i--)
        {
            TreeNode *node = que.front();
            que.pop();

            // 從後面填回來
            if (level % 2 == 1)
                current_level[i - 1] = node->val;
            else // 照順序填過去
            {
                current_level[j] = node->val;
                j++;
            }

            if (node->left)
                que.push(node->left);
            if (node->right)
                que.push(node->right);
        }
        level++;
        output.push_back(current_level);
    }
    return output;
}
