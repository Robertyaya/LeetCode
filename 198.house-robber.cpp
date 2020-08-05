/*
 * @lc app=leetcode id=198 lang=cpp
 *
 * [198] House Robber
 */

// @lc code=start
class Solution
{
    /**
     * Time: O(N), Space: O(N)
     * 解題流程: 相鄰兩個不能加在一起
     * 利用dp去紀錄 dp[i]代表這個位置目前的最大值
     * 轉移方程為dp[i] = nums[i] + max(dp[i-2]+dp[i-3])
     * dp[i-4]會被dp[i-2]紀錄了, 後面同樣, 因此只考慮i-2 and i-3
     */
public:
    int rob(vector<int> &nums)
    {
        if (nums.empty())
            return 0;
        if (nums.size() == 1)
            return nums[0];

        vector<int> dp(nums.size(), 0);
        dp[0] = nums[0];
        dp[1] = nums[1];
        for (int i = 2; i < nums.size(); i++)
        {
            if (i - 3 >= 0)
                dp[i] = max(dp[i - 2], dp[i - 3]) + nums[i];
            else
                dp[i] = dp[i - 2] + nums[i];
        }
        return max(dp[nums.size() - 1], dp[nums.size() - 2]);
    }
};
// @lc code=end
