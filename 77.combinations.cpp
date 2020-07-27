/*
 * @lc app=leetcode id=77 lang=cpp
 *
 * [77] Combinations
 */

// @lc code=start
class Solution
{
    /**
     * Time: O(N!), Space: O(k)
     * Back tracking
     */
public:
    void DFS(vector<vector<int>> &res, vector<int> &temp, int k, int n, int level)
    {
        if (temp.size() == k)
        {
            res.push_back(temp);
            return;
        }

        if (level > n)
            return;

        for (int i = level; i <= n; i++)
        {
            temp.push_back(i);
            DFS(res, temp, k, n, i + 1);
            temp.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k)
    {
        if (k > n)
            return {};

        vector<vector<int>> res;
        vector<int> temp;
        for (int i = 1; i <= n; i++)
        {
            temp.push_back(i);
            DFS(res, temp, k, n, i + 1);
            temp.pop_back();
        }
        return res;
    }
};
// @lc code=end
