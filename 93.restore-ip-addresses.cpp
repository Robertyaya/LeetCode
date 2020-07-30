/*
 * @lc app=leetcode id=93 lang=cpp
 *
 * [93] Restore IP Addresses
 */

// @lc code=start
class Solution
{
    /**
     * Recursion stack最深也只會4層
     * Time: O(3^N), Space: O(1)
     */
public:
    bool isValid(string str)
    {
        int value = stoi(str);
        if (value > 255 || value < 0)
            return false;
        // 01 or 011為不存在
        if (str.size() > 1 && (str[0] - '0') == 0)
            return false;
        return true;
    }
    // k為紀錄是否到達4個數字了
    void DFS(string &s, int k, string str, vector<string> &res)
    {
        // 提早pruning, 最大一定3位數要為一個數字, 如果此時已經k==1,但位數大於3位數代表一定還有2個數字以上
        if (k < 0 || (k == 1 && s.size() > 3) || (k == 2 && s.size() > 6) || (k == 3 && s.size() > 9) || (k == 4 && s.size() > 12))
            return;

        if (k == 0 && s.empty())
        {
            res.push_back(str);
            return;
        }

        // 3條路可以走, 長度1~3
        for (int i = 1; i <= 3; i++)
        {
            if (i <= s.size() && isValid(s.substr(0, i)))
            {
                // 每次當取剩下的substring為下一層的s
                string temp = s.substr(i);
                if (k == 1) // 代表已經是最後一個數字了
                    DFS(temp, k - 1, str + s.substr(0, i), res);
                else
                    DFS(temp, k - 1, str + s.substr(0, i) + ".", res);
            }
        }
    }

    vector<string> restoreIpAddresses(string s)
    {
        vector<string> res;
        int start_index = 0;
        DFS(s, 4, "", res);
        return res;
    }
};
// @lc code=end
