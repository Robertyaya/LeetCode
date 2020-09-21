/*
 * @lc app=leetcode id=459 lang=cpp
 *
 * [459] Repeated Substring Pattern
 */

// @lc code=start
class Solution
{
public:
    /**
 * Time: O(N^2), Space: O(N)
 */
    bool DFS(string &s, string &pattern, int i)
    {
        if (i > s.size() - 1)
            return true;

        if (pattern != s.substr(i, pattern.size()))
            return false;

        // 一段一段往前移, 確認是否有和pattern相同
        return DFS(s, pattern, i + pattern.size());
    }
    bool repeatedSubstringPattern(string s)
    {
        // Traverse所有長度的pattern
        string pattern = "";
        for (int i = 0; i < s.size() / 2; i++)
        {
            pattern += s[i];
            if (s.size() % pattern.size() != 0)
                continue;

            if (DFS(s, pattern, pattern.size()))
                return true;
        }
        return false;
    }
};
// @lc code=end
