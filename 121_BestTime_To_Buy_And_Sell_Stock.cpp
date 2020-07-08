#include <bits/stdc++.h>
using namespace std;
/**
 * Kadane's Algorithm
 * Time: O(N), Space: O(1)
 * 解題流程: 利用計算最大子數列的方法Kadane's algorithm
 * 每一次都去update max_current and max_sofar
 * if max_current < 0, reset to zero
 * 
 */
// [7,1,5,3,6,4]
int maxProfit(vector<int> &prices)
{
    int max_current = 0;
    int max_sofar = 0;
    for (int i = 1; i < prices.size(); i++)
    {
        max_current = max(0, max_current += (prices[i] - prices[i - 1]));
        max_sofar = max(max_sofar, max_current);
    }
    return max_sofar;
}

/**
 * Time: O(N), Space: O(1)
 * 解題流程: max_profit紀錄目前最大的profit, min_price紀錄目前的最低點
 * 每次都去update min_price and max_profit
 * 因此min_price會持續指在目前的最低點
 */
int maxProfit(vector<int> &prices)
{
    int min_price = INT_MAX;
    int max_profit = 0;
    for (int i = 0; i < prices.size(); i++)
    {
        min_price = min(min_price, prices[i]);
        max_profit = max(max_profit, prices[i] - min_price);
    }
    return max_profit;
}
