/*
 * @lc app=leetcode id=279 lang=cpp
 *
 * [279] Perfect Squares
 */

// @lc code=start
class Solution
{
    /**
     * Time: O(N^2), Space: O(N)
     * 解題流程: Use dynamic programming
     * dp[i]代表n=i時, 最少能夠滿足的個數
     * ex: dp[7]
     * dp[7]=1+dp[6]
     * dp[7]=4+dp[3]
     * 
     */
public:
    int numSquares(int n)
    {
        vector<int> dp(n + 1, 0);
        dp[0] = 0;
        dp[1] = 1;
        for (int i = 2; i <= n; i++)
        {
            int min_dp = INT_MAX;
            int j = 1;
            int current = i;
            while (j * j <= i)
            {
                int index = current - (j * j);
                min_dp = min(min_dp, dp[index]);
                j++;
            }
            dp[i] = dp[min_dp] + 1;
        }
        return dp[n];
    }
};
// @lc code=end
