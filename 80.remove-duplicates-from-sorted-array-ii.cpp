/*
 * @lc app=leetcode id=80 lang=cpp
 *
 * [80] Remove Duplicates from Sorted Array II
 *
 * https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/description/
 *
 * algorithms
 * Medium (43.71%)
 * Likes:    1176
 * Dislikes: 705
 * Total Accepted:    266K
 * Total Submissions: 606.6K
 * Testcase Example:  '[1,1,1,2,2,3]'
 *
 * Given a sorted array nums, remove the duplicates in-place such that
 * duplicates appeared at most twice and return the new length.
 * 
 * Do not allocate extra space for another array, you must do this by modifying
 * the input array in-place with O(1) extra memory.
 * 
 * Example 1:
 * 
 * 
 * Given nums = [1,1,1,2,2,3],
 * 
 * Your function should return length = 5, with the first five elements of nums
 * being 1, 1, 2, 2 and 3 respectively.
 * 
 * It doesn't matter what you leave beyond the returned length.
 * 
 * Example 2:
 * 
 * 
 * Given nums = [0,0,1,1,1,1,2,3,3],
 * 
 * Your function should return length = 7, with the first seven elements of
 * nums being modified to 0, 0, 1, 1, 2, 3 and 3 respectively.
 * 
 * It doesn't matter what values are set beyond the returned length.
 * 
 * 
 * Clarification:
 * 
 * Confused why the returned value is an integer but your answer is an array?
 * 
 * Note that the input array is passed in by reference, which means
 * modification to the input array will be known to the caller as well.
 * 
 * Internally you can think of this:
 * 
 * 
 * // nums is passed in by reference. (i.e., without making a copy)
 * int len = removeDuplicates(nums);
 * 
 * // any modification to nums in your function would be known by the caller.
 * // using the length returned by your function, it prints the first len
 * elements.
 * for (int i = 0; i < len; i++) {
 * print(nums[i]);
 * }
 * 
 * 
 */

// @lc code=start
class Solution
{
    /**
     * Time: O(N), Space: O(1)
     * 解題流程: 
     * ex: 1 1 1 2 2 3
     * 利用two pointer的概念, v為traverse目前nums所有的int, i為遇到need to remove的數字時, 不會往前, i是為了記錄實際要return vector的index
     * 1 1 1 2 2 3
     *     *
     * 到此位置i不會往前
     * 1 1 1 2 2 3
     *     i v
     * v的數字會填到i的位置, 後面所有數字都會往前一格
     * 同理如果有兩個地方需要remove, i會落後v兩格, 代表所有數字會往前兩個
     * 
     * 1 1 2 2 3 3 
     * 接著在pop_back出多餘的數字
     */
public:
    int removeDuplicates(vector<int> &nums)
    {
        if (nums.empty() || nums.size() == 1)
            return nums.size();

        int count = 0;           // 紀錄目前重複的數字有幾個
        int pre_value = INT_MIN; // 紀錄前一個數字是什麼
        int i = 0;
        for (auto v : nums)
        {
            // 當現在int和pre相同, count++, 當count>2代表此時數字已經出現第三次, i不會往前走
            if (v == pre_value)
            {
                count++;
                if (count <= 2)
                {
                    nums[i] = v;
                    i++;
                }
            }
            else
            {
                pre_value = v;
                count = 1;
                nums[i] = v;
                i++;
            }
        }

        // Pop_back the value
        int n = nums.size() - 1;
        for (int j = 0; j <= n - i; j++)
            nums.pop_back();

        return nums.size();
    }
};
// @lc code=end
