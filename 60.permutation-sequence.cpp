/*
 * @lc app=leetcode id=60 lang=cpp
 *
 * [60] Permutation Sequence
 */

// @lc code=start
class Solution
{
public:
    bool DFS(int n, int k, int &order, string &output, vector<bool> &map)
    {
        if (output.size() == n)
        {
            order++;
            if (order == k)
                return true;
            return false;
        }

        for (int i = 1; i <= n; i++)
        {
            if (!map[i])
            {
                output.append(to_string(i));
                map[i] = true;

                if (DFS(n, k, order, output, map))
                    return true;

                map[i] = false;
                output.pop_back();
            }
        }
        return false;
    }
    string getPermutation(int n, int k)
    {
        vector<bool> map(n, false);
        string output;
        int order = 0;
        DFS(n, k, order, output, map);
        return output;
    }
};
// @lc code=end
