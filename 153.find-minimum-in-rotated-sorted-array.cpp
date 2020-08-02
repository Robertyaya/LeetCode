/*
 * @lc app=leetcode id=153 lang=cpp
 *
 * [153] Find Minimum in Rotated Sorted Array
 */

// @lc code=start
class Solution
{
    /**
     * Time: O(logN), Space: O(1)
     * 解題流程: 利用如果mid大於right的話, 代表rotated point"一定"在mid右邊, 因此可update l到mid+1
     */
public:
    int findMin(vector<int> &nums)
    {
        int l = 0;
        int r = nums.size() - 1;
        while (l < r)
        {
            int mid = l + (r - l) / 2;
            // 代表rotated point在mid右邊
            if (nums[mid] > nums[r])
            {
                l = mid + 1;
            }
            else // 可能mid剛好就是rotated point或是在mid左邊
            {
                r = mid;
            }
        }
        return nums[r];
    }
};
// @lc code=end
