/*
 * @lc app=leetcode id=213 lang=cpp
 *
 * [213] House Robber II
 */

// @lc code=start
class Solution
{
    /**
     * Time: O(N), Space: O(N)
     * 解題流程: Same as problem198
     * 差別在於此題為環狀, 因此頭跟尾算是adj node
     * 因此分成兩個dp, 一個扣掉尾巴, 一個扣掉頭
     * 兩個分別算出來後取max return 
     */
public:
    int rob(vector<int> &nums)
    {
        // Edge case
        if (nums.empty())
            return 0;
        if (nums.size() == 1)
            return nums[0];
        if (nums.size() == 2)
            return max(nums[0], nums[1]);

        // 扣掉頭
        vector<int> dp(nums.size() - 1, 0);
        dp[0] = nums[1];
        dp[1] = nums[2];
        for (int i = 2; i < nums.size() - 1; i++)
        {
            if (i == 2)
            {
                dp[i] = dp[i - 2] + nums[i + 1];
                continue;
            }
            dp[i] = max(dp[i - 2], dp[i - 3]) + nums[i + 1];
        }

        // 扣掉尾
        vector<int> dp_(nums.size() - 1, 0);
        dp_[0] = nums[0];
        dp_[1] = nums[1];
        for (int i = 2; i < nums.size() - 1; i++)
        {
            if (i == 2)
            {
                dp_[i] = dp_[i - 2] + nums[i];
                continue;
            }
            dp_[i] = max(dp_[i - 2], dp_[i - 3]) + nums[i];
        }

        // max(dp[nums.size() - 2], dp[nums.size() - 3]) 為扣掉頭最大的數值
        // max(dp_[nums.size() - 2], dp_[nums.size() - 3]) 為扣掉尾最大的數值
        return max(max(dp[nums.size() - 2], dp[nums.size() - 3]),
                   max(dp_[nums.size() - 2], dp_[nums.size() - 3]));
    }
};
// @lc code=end
