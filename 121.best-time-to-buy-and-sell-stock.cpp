/*
 * @lc app=leetcode id=121 lang=cpp
 *
 * [121] Best Time to Buy and Sell Stock
 */

// @lc code=start
class Solution
{
public:
    /**
 * Time: O(N), Space: O(1)
 * 解題流程: max_profit紀錄目前最大的profit, min_price紀錄目前的最低點
 * 每次都去update min_price and max_profit
 * 因此min_price會持續指在目前的最低點
 */
    int maxProfit(vector<int> &prices)
    {
        int min_value = INT_MAX;
        int max_profit = 0;
        for (int i = 0; i < prices.size(); i++)
        {
            min_value = min(min_value, prices[i]);               // 紀錄走到目前的最低點
            max_profit = max(max_profit, prices[i] - min_value); // update max profit
        }
        return max_profit;
    }
    /**
 * Kadane's Algorithm
 * Time: O(N), Space: O(1)
 * 解題流程: 利用計算最大子數列的方法Kadane's algorithm
 * 每一次都去update max_current and max_sofar
 * if max_current < 0, reset to zero
 * ex: [1,5,3,6,4]
 * 4-2+3 = 5, 只要小於0, 則reset為0
 * 把每一小段的profit相加
 */
    int maxProfit(vector<int> &prices)
    {
        int max_current = 0;
        int max_sofar = 0;
        for (int i = 1; i < prices.size(); i++)
        {
            max_current = max(max_current += prices[i] - prices[i - 1], 0);
            max_sofar = max(max_sofar, max_current);
        }
        return max_sofar;
    }
};
// @lc code=end
