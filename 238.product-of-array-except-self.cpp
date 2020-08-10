/*
 * @lc app=leetcode id=238 lang=cpp
 *
 * [238] Product of Array Except Self
 */

// @lc code=start
class Solution
{
public:
    /**
 * Time: O(N), Space: O(N)
 * 解題流程: 此題不能用除法
 * 因此用兩個vector紀錄
 * forward紀錄的是左半邊的數值 forward[i]代表是左半邊有i個數值時的數值
 * ex: forward[0]為nums[0]時, 左半邊沒數值
 * forward[2]為nums[2]時, 左半邊有兩個數字相乘
 * backward紀錄的是右半邊的數值
 * ex: backward[3]紀錄的是2*3*4
 *     backward[2]紀錄的是3*4
 */
    vector<int> productExceptSelf(vector<int> &nums)
    {
        vector<int> res(nums.size(), 1);
        vector<int> forward(nums.size(), 1);
        vector<int> backward(nums.size(), 1);

        // Fill the forward
        for (int i = 0; i < nums.size() - 1; i++)
        {
            forward[i + 1] = forward[i] * nums[i];
        }
        // Fill the backward
        int j = 1;
        for (int i = nums.size() - 1; i > 0; i--)
        {
            backward[j] = backward[j - 1] * nums[i];
            j++;
        }

        for (int i = 0; i < res.size(); i++)
        {
            res[i] = forward[i] * backward[(res.size() - 1) - i];
        }

        return res;
    }
};
// @lc code=end
