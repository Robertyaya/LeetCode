/*
 * @lc app=leetcode id=268 lang=cpp
 *
 * [268] Missing Number
 */

// @lc code=start
class Solution
{
public:
    /**
     * Time: O(N), Space: O(1)
     * 解題流程: [0,1,3]
     * 現有數字全部相加 0+1+3=4
     * 等差數列公式 0+1+2+3=6
     * return 6-4=2
     */
    int missingNumber(vector<int> &nums)
    {
        int sum = 0;
        for (auto v : nums)
        {
            sum += v;
        }
        int n = nums.size();
        return 0.5 * n * (n + 1) - sum;
    }
    // Time : O(NlogN), Space : O(1)
    int missingNumber(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        int l = 0;
        int r = nums.size();
        while (l < r)
        {
            int mid = l + (r - l) / 2;
            if (mid == nums[mid])
                l = mid + 1;
            else
                r = mid;
        }
        return l;
    }
};
// @lc code=end
