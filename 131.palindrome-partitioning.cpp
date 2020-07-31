/*
 * @lc app=leetcode id=131 lang=cpp
 *
 * [131] Palindrome Partitioning
 */

// @lc code=start
class Solution
{
    /**
     * 2^N就跟取一個string所有的substring一樣, 可以取或不取, 因此為2^N, 另外一個N為在判斷是否為回文
     * Time: O(N*2^N), Space: O(N)
     *
     */
public:
    bool CheckPalin(string &s)
    {
        if (s.length() == 1)
            return true;
        int left = 0;
        int right = s.length() - 1;
        while (left < right)
        {
            if (s[left++] != s[right--])
                return false;
        }
        return true;
    }
    void DFS(vector<vector<string>> &res, vector<string> &vec, string s)
    {
        if (s.empty())
        {
            res.push_back(vec);
            return;
        }

        // Traverse 不同長度的substr, backtracking 概念
        for (int i = 1; i <= s.length(); i++)
        {
            string str = s.substr(0, i);
            if (!CheckPalin(str)) // 不是回文就代表此substring不行
                continue;

            vec.push_back(str);
            DFS(res, vec, s.substr(i));
            vec.pop_back();
        }
    }
    vector<vector<string>> partition(string s)
    {
        vector<vector<string>> res;
        vector<string> vec;
        DFS(res, vec, s);
        return res;
    }
};
// @lc code=end
