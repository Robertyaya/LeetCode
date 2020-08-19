/*
 * @lc app=leetcode id=410 lang=cpp
 *
 * [410] Split Array Largest Sum
 */

// @lc code=start
class Solution
{
    /**
     * Time: O(NlogN), Space: O(1)
     * 解題流程: Same as problem 1101
     * mid的數值代表就直接是目標
     * 根據目標反推subarray數量有沒有滿足題目的m
     */
public:
    bool Feasible(vector<int> &nums, long threshold, int m)
    {
        // 根據target largest sum去切subarray, 看有沒有滿足m
        long temp = 0;
        int sub = 1;
        for (int i = 0; i < nums.size(); i++)
        {
            temp += nums[i];
            if (temp > threshold)
            {
                temp = 0;
                temp += (long)nums[i];
                sub++;
                if (sub > m)
                    return false;
            }
        }
        return true;
    }
    int splitArray(vector<int> &nums, int m)
    {
        long l = *max_element(nums.begin(), nums.end());
        long r = 0;
        for (auto v : nums)
            r += v;
        while (l < r)
        {
            // Target largest sum
            long mid = l + (r - l) / 2;
            if (Feasible(nums, mid, m))
                r = mid;
            else
                l = mid + 1;
        }
        return l;
    }
};
// @lc code=end
