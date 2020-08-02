/*
 * @lc app=leetcode id=151 lang=cpp
 *
 * [151] Reverse Words in a String
 */

// @lc code=start
class Solution
{
    /**
     * Time: O(N), Space: O(N)
     * 解題流程: 利用two pointer, 一個指向字首, 一個代表長度
     * 當遇到 " "則代表目前的substring已經結束, push到stack中
     */
public:
    string reverseWords(string s)
    {
        stack<string> sta;
        int start = 0;
        int length = 0;
        bool flag = false;
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == ' ')
            {
                // length==0代表可能一開始的空格要先略過
                if (length != 0)
                {
                    // 代表此substring已經結束, 放到stack中
                    sta.push(s.substr(start, length));
                }
                // Reset
                length = 0;
                flag = true;
            }
            else
            {
                // 代表新的substring開始, update start並且開始update length, start要固定住
                if (flag)
                {
                    start = i;
                    flag = false;
                }
                length++;
            }
        }
        // 塞入最後一個
        if (length != 0)
        {
            sta.push(s.substr(start, length));
        }

        // 從stack一個一個pop出來接起來
        string res;
        while (!sta.empty())
        {
            string temp = sta.top();
            sta.pop();
            if (sta.empty())
                res.append(temp);
            else
                res.append(temp + " ");
        }
        return res;
    }
};
// @lc code=end
