/*
 * @lc app=leetcode id=1011 lang=cpp
 *
 * [1011] Capacity To Ship Packages Within D Days
 */

// @lc code=start
class Solution
{
    /**
     * Time: O(NlogN), Space: O(1)
     * Binary search to find the minimum weight
     */
public:
    bool Ship(vector<int> &weights, int mid, int D)
    {
        int temp = 0;
        int j = 0;
        int day = 1;
        for (int i = 0; i < weights.size(); i++)
        {
            temp += weights[i];
            // 代表進去第二天
            if (temp > mid)
            {
                // 重新歸0並加上當天的數值
                temp = 0;
                temp += weights[i];
                day++;
                if (day > D)
                    return false;
            }
        }

        return true;
    }
    int shipWithinDays(vector<int> &weights, int D)
    {
        // 最小一定是ship weight裡面最大的數值, 不然就會有一個一定裝不進去
        int l = *max_element(weights.begin(), weights.end());

        // 最大則是所有weight和
        int r = 0;
        for (auto v : weights)
            r += v;

        // O(NlogN)
        while (l < r)
        {
            // Mid為target weight
            int mid = l + (r - l) / 2;
            if (Ship(weights, mid, D))
                r = mid;
            else
                l = mid + 1;
        }
        return l;
    }
};
// @lc code=end
