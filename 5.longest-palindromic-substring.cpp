/*
 * @lc app=leetcode id=5 lang=cpp
 *
 * [5] Longest Palindromic Substring
 */

// @lc code=start
class Solution
{
public:
    int ExpandFromCenter(string &s, int l, int r)
    {
        while (l >= 0 && r < s.length() && s[l] == s[r])
        {
            l--;
            r++;
        }
        return r - l - 1;
    }
    string longestPalindrome(string s)
    {
        if (s.empty())
            return s;
        int length;
        int max_length = 0;
        int max_index;
        for (int i = 0; i < s.length(); i++)
        {
            length = max(ExpandFromCenter(s, i, i), ExpandFromCenter(s, i, i + 1));
            if (length > max_length)
            {
                max_length = length;
                max_index = i;
            }
        }

        int start_index;
        if (max_length % 2 == 0)
            start_index = max_index - max_length / 2 + 1;
        else
            start_index = max_index - max_length / 2;
        return s.substr(start_index, max_length);
    }
};
// @lc code=end
