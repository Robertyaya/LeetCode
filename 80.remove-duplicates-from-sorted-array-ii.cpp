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
public:
    int removeDuplicates(vector<int> &nums)
    {
        if (nums.empty() || nums.size() == 1)
            return nums.size();

        int n = nums.size();
        vector<int>::iterator iter = nums.begin();
        int count = 0;
        int pre_value = -1;
        while (n >= 1)
        {

            //cout << *iter << " " << pre_value << endl;
            if (*iter == pre_value)
            {
                count++;
                if (count > 2)
                {
                    while (iter <= nums.end() && *iter == pre_value)
                    {
                        nums.erase(iter);
                        n--;
                    }
                }
                else
                {
                    iter++;
                    n--;
                }
            }
            else
            {
                pre_value = *iter;
                count = 1;
                iter++;
                n--;
            }
        }

        for (auto v : nums)
            cout << v << " ";
        cout << endl;
        return nums.size();
    }
};
// @lc code=end
