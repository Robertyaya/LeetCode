/*
 * @lc app=leetcode id=171 lang=cpp
 *
 * [171] Excel Sheet Column Number
 */

// @lc code=start
class Solution
{
    /**
     * Time: O(N), Space: O(1)
     * 解題流程:
     * ABC
     * A*26^2+B*26+C
     */
public:
    int titleToNumber(string s)
    {
        int res = 0;
        int j = 0;
        for (int i = s.length() - 1; i >= 0; i--)
        {
            int temp = s[i] - 'A' + 1;
            res += (temp * pow(26, j));
            j++;
        }
        return res;
    }
};
// @lc code=end
