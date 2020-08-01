/*
 * @lc app=leetcode id=150 lang=cpp
 *
 * [150] Evaluate Reverse Polish Notation
 */

// @lc code=start
class Solution
{
    /**
     * Time: O(N), Space: O(N)
     * 解題流程: 利用stack, 過程中將數字放進stack中
     * 如果遇到符號則pop兩個數字出來做運算後再塞回去
     */
public:
    int evalRPN(vector<string> &tokens)
    {
        stack<int> sta;
        for (auto v : tokens)
        {
            if (v == "+")
            {
                int value1 = sta.top();
                sta.pop();
                int value2 = sta.top();
                sta.pop();
                sta.push(value1 + value2);
            }
            else if (v == "-")
            {
                int value1 = sta.top();
                sta.pop();
                int value2 = sta.top();
                sta.pop();
                sta.push(value2 - value1);
            }
            else if (v == "*")
            {
                int value1 = sta.top();
                sta.pop();
                int value2 = sta.top();
                sta.pop();
                sta.push(value1 * value2);
            }
            else if (v == "/")
            {
                int value1 = sta.top();
                sta.pop();
                int value2 = sta.top();
                sta.pop();
                sta.push(value2 / value1);
            }
            else
            {
                sta.push(stoi(v));
            }
        }
        return sta.top();
    }
};
// @lc code=end
