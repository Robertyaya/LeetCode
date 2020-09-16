/*
 * @lc app=leetcode id=215 lang=cpp
 *
 * [215] Kth Largest Element in an Array
 */

// @lc code=start
class Solution
{
    /**
     * Time: O(kN), Space: O(1)
     * 解題流程: 利用Quick sort的partition來找第kth大的數字
     * pivot的選擇利用randam可以加快非常多！
     */
public:
    int Partition(vector<int> &nums, int l, int r)
    {
        int pivot_index = rand() % (r - l + 1) + l;
        swap(nums[pivot_index], nums[r]);
        int pivot = nums[r];

        int j = l;
        for (int i = l; i < r; i++)
        {
            // 因為要找第k大, 所以排列為從大到小, 大的丟pivot左邊
            if (nums[i] > pivot)
            {
                swap(nums[j], nums[i]);
                j++;
            }
        }
        swap(nums[j], nums[r]);
        return j;
    }
    int findKthLargest(vector<int> &nums, int k)
    {
        int l = 0;
        int r = nums.size() - 1;
        while (l < r)
        {
            int index = Partition(nums, l, r);
            if (index == k - 1)
                return nums[index];
            else if (index < k - 1)
                l = index + 1;
            else
                r = index - 1;
        }
        return nums[l];
    }
};
// @lc code=end
