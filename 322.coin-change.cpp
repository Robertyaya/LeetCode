/*
 * @lc app=leetcode id=322 lang=cpp
 *
 * [322] Coin Change
 */

// @lc code=start
class Solution
{
    /**
     * Time: O(N^2), Space: O(N)
     * 解題流程: dp[i]代表的是amount i 時的最小coin數
     */
public:
    int coinChange(vector<int> &coins, int amount)
    {
        sort(coins.begin(), coins.end());
        vector<int> dp(amount + 1, 0);

        for (int i = 1; i <= amount; i++)
        {
            int min_coin = INT_MAX;
            for (int j = 0; j < coins.size(); j++)
            {
                int index = i - coins[j];
                if (index >= 0 && dp[index] >= 0)
                {
                    min_coin = min(min_coin, dp[index]);
                }
            }
            // 代表沒辦法換coin
            if (min_coin == INT_MAX)
                dp[i] = -1;
            else
                dp[i] = min_coin + 1;
        }
        return dp.back();
    }
};
// @lc code=end
