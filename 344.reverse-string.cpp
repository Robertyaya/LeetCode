/*
 * @lc app=leetcode id=344 lang=cpp
 *
 * [344] Reverse String
 */

// @lc code=start
class Solution
{
public:
    void reverseString(vector<char> &s)
    {
        int l = 0;
        int r = s.size() - 1;
        while (l < r)
        {
            swap(s[l], s[r]);
            l++;
            r--;
        }
    }
};
// @lc code=end
