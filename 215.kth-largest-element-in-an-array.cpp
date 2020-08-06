/*
 * @lc app=leetcode id=215 lang=cpp
 *
 * [215] Kth Largest Element in an Array
 */

// @lc code=start
class Solution
{
public:
    int Partition(vector<int> &nums, int l, int r)
    {
        int pivot = nums[r];
        int i = l - 1;
        for (int j = l; j < r; j++)
        {
            if (nums[j] < pivot)
            {
                i++;
                swap(nums[i], nums[j]);
            }
        }
        i++;
        swap(nums[i], nums[r]);
        return
    }
    int findrecursive(vector<int> &nums, int l, int r, int k)
    {
    }
    int findKthLargest(vector<int> &nums, int k)
    {
        return findrecursive(nums, 0, nums.size() - 1, k);
    }
};
// @lc code=end
