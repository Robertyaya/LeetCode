/*
 * @lc app=leetcode id=875 lang=cpp
 *
 * [875] Koko Eating Bananas
 */

// @lc code=start
class Solution
{
    /**
     * Time: O(NlogN), Space: O(1)
     * 解題流程: Binary Search去找minimum integer
     * mid為答案, 依此答案去看time是否滿足題目要求不能超過H
     */
public:
    bool Eat(vector<int> &piles, int mid, int H)
    {
        int time = 0;
        for (int i = 0; i < piles.size(); i++)
        {
            if (piles[i] % mid == 0)
                time += (piles[i] / mid);
            else
                time += (piles[i] / mid + 1);

            // time超過H, 代表此吃的速度不行, 太慢了
            if (time > H)
                return false;
        }
        return true;
    }
    int minEatingSpeed(vector<int> &piles, int H)
    {
        int l = 1;
        int r = *max_element(piles.begin(), piles.end());
        while (l < r)
        {
            int mid = l + (r - l) / 2;
            // 代表可以繼續找更小的, current mid算出來是小於H的
            if (Eat(piles, mid, H))
                r = mid;
            else
                l = mid + 1;
        }
        return l;
    }
};
// @lc code=end
