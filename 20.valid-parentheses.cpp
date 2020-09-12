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
            if (sta.empty() && (s[i] == ')' || s[i] == ']' || s[i] == '}'))
                return false;

            if (s[i] == '(' || s[i] == '[' || s[i] == '{')
                sta.push(s[i]);
            else
            {
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
