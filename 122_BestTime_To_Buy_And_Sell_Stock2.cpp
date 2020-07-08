#include <bits/stdc++.h>
using namespace std;
/**
 * Greedy version
 * Time: O(N), Space: O(1)
 * 解題流程: 和下面解法不同在於
 * 下面解法是將local的最大profit算出來
 * 而greedy解法是將每一個小間隔全部的profit加起來
 * 兩者得到的都是整段的profit但作法不一樣
 * 
 *      /  *
 *     /   |
 *    /    |
 *   /     *   
 *   獲利就是這條斜線的高度, 一個是整段直接求得, greedy是把每一小段全部加起來求得
 */
int maxProfit(vector<int> &prices)
{
    int profit = 0;
    for (int i = 1; i < prices.size(); i++)
    {
        int profit_temp = prices[i] - prices[i - 1];
        if (profit_temp > 0)
            profit += profit_temp;
    }
    return profit;
}
/**
 * Time: O(N), Space: O(1)
 * 解題流程: 分成兩個mode, buy mode and sell mode
 * 當現在為buy mode時, 我們要找出local minimum->而local minimum指的就是下一個數字會比現在這個數字大的話
 * 此數字則為local minimum
 * 
 * ex: 3 2 1 2 3 -> 1為local minimum
 * 當現在為sell mode時, 我們要找出local maximum->而local maximum指的就是下一個數字會比現在這個數字小
 * 此數字則為local maximum
 * 
 * ex: 1 2 3 2 1 -> 3為local maximum
 * 那之所以不加等號的原因在於
 * ex: 7 1 1 2 2 
 *         * *   目標買在1賣出2
 * 但如果加等號就會變成
 * ex: 7 1 1 2 2 
 *       * *     買在第一個1賣在第二個1
 * 
 * 最後面需要判斷boundary case也就是最後一個的時候
 * 分成此時在buy mode and sell mode
 * 如果是buy mode 
 * ex: 1, 2, 3, 2, 1 賣出在3並進入buy mode
 * 此種情況不可能存在 因為不可能會有相對低點 已經最後一個了
 * 因此只須判斷sell mode情況
 * ex: 3, 2 ,1 5
 * 前面已經買在相對低點, 因此此時到最後一個不管有沒有找到相對高點都要直接賣掉換現金的意思 
 */

int maxProfit(vector<int> &prices)
{
    int profit = 0;

    // O(N)
    bool buy_mode = true;
    int i = 1;
    while (i < prices.size())
    {
        // In buy mode, we need to find local minimum
        if (buy_mode && prices[i] > prices[i - 1])
        {

            profit -= prices[i - 1];
            buy_mode = false;
        }
        // In sell mode, we need to find the local maximum
        if (!buy_mode && prices[i] < prices[i - 1])
        {

            profit += prices[i - 1];
            buy_mode = true;
        }

        // Boundary case
        if (i == prices.size() - 1 && !buy_mode)
            profit += prices[i];

        i++;
    }

    return profit < 0 ? 0 : profit;
}

int main()
{
    vector<int> vec = {7, 1, 1, 2, 3, 2, 1, 5};
    cout << maxProfit(vec) << endl;
}