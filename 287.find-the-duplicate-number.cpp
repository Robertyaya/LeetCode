/*
 * @lc app=leetcode id=287 lang=cpp
 *
 * [287] Find the Duplicate Number
 */

// @lc code=start
class Solution
{
public:
    /**
 * Time: O(NlogN), Space: O(1)
 * 解題流程: Binary Search
 * 利用總共n+1個數字的限制
 */
    bool Count(vector<int> &nums, int mid)
    {
        int count = 0;
        for (auto v : nums)
        {
            if (v <= mid)
                count++;
        }
        // 代表mid以下不可能有duplicate number, 有的話就會超過mid的數字
        return count <= mid;
    }
    int findDuplicate(vector<int> &nums)
    {
        int l = 1;
        int r = nums.size();
        while (l < r)
        {
            int mid = l + (r - l) / 2;
            if (Count(nums, mid))
                l = mid + 1;
            else
                r = mid;
        }
        return l;
    }
    /**
     * Time: O(NlogN), Space: O(1)
     */
    int findDuplicate(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        int res;
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] == nums[i - 1])
                res = nums[i];
        }
        return res;
    }
};
// @lc code=end
