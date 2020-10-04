/*
 * @lc app=leetcode id=20 lang=cpp
 *
 * [20] Valid Parentheses
 */

// @lc code=start
class Solution
{
public:
    bool isValid(string s)
    {
        stack<char> sta;
        for (int i = 0; i < s.length(); i++)
        {
            // 代表stack裡面並沒有左邊的括號可以和右邊括號抵銷, return false
            if (sta.empty() && (s[i] == ')' || s[i] == ']' || s[i] == '}'))
                return false;

            // 左括號則直接放入
            if (s[i] == '(' || s[i] == '[' || s[i] == '{')
                sta.push(s[i]);
            else
            {
                // pop出來和欲進來的比較, 是否形成一個括號
                char ch = sta.top();
                if ((ch == '(' && s[i] == ')') || (ch == '[' && s[i] == ']') || (ch == '{' && s[i] == '}'))
                {
                    sta.pop();
                }
                else
                    return false;
            }
        }
        return sta.empty();
    }
};
// @lc code=end
