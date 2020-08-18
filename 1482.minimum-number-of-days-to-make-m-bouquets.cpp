/*
 * @lc app=leetcode id=1482 lang=cpp
 *
 * [1482] Minimum Number of Days to Make m Bouquets
 */

// @lc code=start
class Solution
{
    /**
     * Time: O(NlogN), Space: O(1)
     * 解題流程: mid代表的是target day
     */
public:
    bool Check(vector<int> &bloomDay, int m, int k, int day)
    {
        int count_k = 0;
        int count_m = 0;
        for (int i = 0; i < bloomDay.size(); i++)
        {
            if (bloomDay[i] <= day)
                count_k++;
            else
                count_k = 0;

            if (count_k == k)
            {
                count_k = 0;
                count_m++;
            }
            if (count_m == m)
                return true;
        }
        return false;
    }
    int minDays(vector<int> &bloomDay, int m, int k)
    {
        // 所要求的花量都超過bloomday的數量, 因此一定不可能
        if (m * k > bloomDay.size())
            return -1;

        int l = 1;
        int r = *max_element(bloomDay.begin(), bloomDay.end());
        while (l < r)
        {
            int mid = l + (r - l) / 2;
            if (Check(bloomDay, m, k, mid))
                r = mid;
            else
                l = mid + 1;
        }
        return l;
    }
};
// @lc code=end
