/*
 * @lc app=leetcode id=227 lang=cpp
 *
 * [227] Basic Calculator II
 */

// @lc code=start
class Solution
{
    /**
     * Time: O(N), Space: O(N)
     * 解題流程: 塞到stack中都是已經計算完的數字, 最後面將stack中所有數字加起來return 
     *  '-'的話則將數字取負號放入stack中
     * 3+222*33
     * 一開始op為+
     * +3+222*33
     *   *
     * 當遇到*號時, op為第一個+, num為3, 因此將3放入stack中
     * update op為*號的+, num=0
     * 
     * +3+222*33
     *       *
     * 當到*後, num為33, stack.top為222
     * 兩個數字取出來相乘再放入stack中
     */
public:
    int calculate(string s)
    {
        int num = 0;
        char op = '+'; // 紀錄的是上一個符號的值
        stack<int> sta;
        // O(N)
        for (int i = 0; i < s.size(); i++)
        {
            // 因為數字可能不止是個位數
            if (s[i] >= '0')
            {
                num = 10 * num + (s[i] - '0');
            }

            if ((s[i] != ' ' && s[i] < '0') || i == s.size() - 1)
            {
                if (op == '+')
                    sta.push(num);
                if (op == '-')
                    sta.push(-num);
                if (op == '*' || op == '/')
                {
                    int l = sta.top();
                    sta.pop();
                    if (op == '*')
                        sta.push(l * num);
                    if (op == '/')
                        sta.push(l / num);
                }
                op = s[i];
                num = 0;
            }
        }

        int res = 0;
        while (!sta.empty())
        {
            int temp = sta.top();
            sta.pop();
            res += temp;
        }
        return res;
    }
};
// @lc code=end
