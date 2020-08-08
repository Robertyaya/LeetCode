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
        // pivot用random
        int pivot_index = l + rand() % (r - l + 1);
        // 將pivot換到最右邊
        swap(nums[pivot_index], nums[r]);

        int pivot = nums[r];

        int i = l - 1;
        // 大的丟pivot左邊, 小的丟pivot右邊
        for (int j = l; j < r; j++)
        {
            if (nums[j] > pivot)
            {
                i++;
                swap(nums[i], nums[j]);
            }
        }
        i++;
        swap(nums[i], nums[r]);

        // return回去的i就代表pivot在nums中為第幾大的數字
        return i;
    }
    int findKthLargest(vector<int> &nums, int k)
    {
        int l = 0;
        int r = nums.size() - 1;
        // O(KN)
        while (l < r)
        {
            // O(N)
            int index = Partition(nums, l, r);
            if (index == k - 1)
                return nums[index];
            else if (index > k - 1) // 代表一定在pivot左邊, update right pointer
                r = index - 1;
            else // 代表一定在pivot右邊, update left pointer
                l = index + 1;
        }
        return nums[r];
    }
};
// @lc code=end
