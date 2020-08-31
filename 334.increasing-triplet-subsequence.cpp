/*
 * @lc app=leetcode id=334 lang=cpp
 *
 * [334] Increasing Triplet Subsequence
 */

// @lc code=start
class Solution
{
    /**
     * Time: O(N), Space: O(1)
     * 解題流程: 維護一個size為3的vector
     * 過程中不斷的去update這3個值
     * 如果這3個都有數值了, 代表nums裡面有3個數值為遞增
     * 基本概念就是整體數值要越小越好, 這樣越有機會找到
     * 因此比vec[0]小就要update vec[0]
     * 比vec[1]小但比vec[0]大就要update vec[1]
     * 比vec[2]小但比vec[1]大就要update vec[2]
     */
public:
    bool increasingTriplet(vector<int> &nums)
    {
        vector<int> vec(3, INT_MAX);
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] < vec[0])
                vec[0] = nums[i];
            else if (nums[i] > vec[0] && nums[i] < vec[1])
                vec[1] = nums[i];
            else if (nums[i] > vec[1] && nums[i] < vec[2])
                vec[2] = nums[i];

            if (vec[0] != INT_MAX && vec[1] != INT_MAX && vec[2] != INT_MAX)
                return true;
        }
        return false;
    }
};
// @lc code=end
