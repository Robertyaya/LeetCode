/*
 * @lc app=leetcode id=508 lang=cpp
 *
 * [508] Most Frequent Subtree Sum
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
     * Time: O(NlogN), Space: O(N)
     */
public:
    int DFS(TreeNode *node, unordered_map<int, int> &map)
    {
        if (!node)
            return 0;
        // 計算sum
        int value = node->val + DFS(node->left, map) + DFS(node->right, map);
        map[value]++;
        return value;
    }
    vector<int> findFrequentTreeSum(TreeNode *root)
    {
        // 利用map去紀錄sum以及出現次數
        unordered_map<int, int> map;
        // O(N)
        DFS(root, map);

        vector<int> res;
        // Max heap, 根據出現次數排列
        auto cmp = [](auto a, auto b) {
            return a.second < b.second;
        };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> que(cmp);
        // O(NlogN)
        for (auto v : map)
            que.push({v.first, v.second});

        while (!que.empty())
        {
            auto v = que.top();
            que.pop();
            int count = v.second;
            res.push_back(v.first);
            v = que.top();
            // 如果count和下一個相同, 則繼續放入res中, 反之則break出來
            if (count != v.second)
                break;
        }
        return res;
    }
};
// @lc code=end
