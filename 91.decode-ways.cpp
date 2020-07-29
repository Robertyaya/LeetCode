/*
 * @lc app=leetcode id=91 lang=cpp
 *
 * [91] Decode Ways
 */

// @lc code=start
class Solution
{
    /**
     * Time: O(N), Space: O(N)
     * 解題流程: dp[i] 代表到此長度有多少種組合
     * ex:  
     *    2 2 0
     * dp 1 1 
     * 概念是這樣, 如果當前為0, 那麼一定不能繼承上面一個dp, 反之則可
     * 為何可以繼承上面的dp
     * ex: 2,2,1
     *  dp 1 1
     * 當前的排列組合一定可以再加上[1]變成[2][2][1] or [22][1] 至少一定會有這幾個, 假設前面有k個, 那也只是多增加這一個數字, 
     * ex: 前面有k種排列組合, 但每一種組合後面都可以加上[1]
     * 因此不會影響原本的dp數值, 因此只要不是0, 則可以直接繼承上一個dp值
     * 
     * 接著還需考慮和前面一個數字合在一起是否有小於26, 若小於26那麼會變成
     * [2][21]
     * 假設i-2個有k種排列組合
     * 每一種後面都會接上[21]這個組合, 因此會多增加k個
     * 因此若和前一個數字合在一起小於26, 則還要再加上dp[i-2]
     * 
     * 因為3位數不可能為小於26, 因此不用考慮3個數字的情況
     * 
     *  
     */
public:
    int numDecodings(string s)
    {
        int res = 0;
        vector<int> dp;
        dp.resize(s.size() + 1);
        dp[0] = 1;
        for (int i = 1; i <= s.size(); i++)
        {
            dp[i] = (s[i - 1] == '0') ? 0 : dp[i - 1];

            // 判斷和前一個數字合在一起是否要小於26
            if (i > 1 && (s[i - 2] == '1' || (s[i - 2] == '2' && s[i - 1] <= '6')))
            {
                dp[i] += dp[i - 2];
            }
        }
        return dp.back();
    }
};
// @lc code=end
