/*
 * @lc app=leetcode id=13 lang=cpp
 *
 * [13] Roman to Integer
 */

// @lc code=start
class Solution
{
public:
    /**
 * Time: O(N), Space: O(1)
 * 解題流程: 如果current比next還要大
 * ex: IV = -1+5
 *     XC = -10+100
 * 一般來說都是從大到小, 則直接將每一個char所代表的數值相加就好
 * 若遇到比下一個還要小, 則current的value直接變成負號
 * 
 */
    int romanToInt(string s)
    {
        int res = 0;
        unordered_map<char, int> m{{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};

        for (int i = 0; i < s.size() - 1; i++)
        {
            int value = m[s[i]];
            if (value >= m[s[i + 1]])
                res += value;
            else
                res -= value;
        }

        // 最後一個最後處理
        res += m[s[s.size() - 1]];
        return res;
    }
};
// @lc code=end
