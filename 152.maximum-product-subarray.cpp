/*
 * @lc app=leetcode id=152 lang=cpp
 *
 * [152] Maximum Product Subarray
 */

// @lc code=start
class Solution
{
    /**
     * Time: O(N), Space: O(1)
     * 解題流程: 類似於Problem 53, 然而因為這題為"相乘", 因此局部最小可能為全局最大
     * 如果只用一般的方法, 局部最小就會被捨棄掉
     * 因此過程中要紀錄局部最大也要紀錄局部最小, 並update
     */
public:
    int maxProduct(vector<int> &nums)
    {
        if (nums.empty())
            return 0;
        if (nums.size() == 1)
            return nums[0];

        int maxcur = 1;
        int mincur = 1;
        int maxfar = INT_MIN;

        for (int i = 0; i < nums.size(); i++)
        {
            // 將前一個的局部最大和局部最小和現在的value相乘, 計算出現在的局部最小和局部最大
            int max_temp = max(maxcur * nums[i], mincur * nums[i]);
            int min_temp = min(maxcur * nums[i], mincur * nums[i]);
            // 再將update過的局部最小和局部最大, 和當下value比較, 得出目前數列的局部最小和最大
            maxcur = max(max_temp, nums[i]);
            mincur = min(min_temp, nums[i]);

            maxfar = max(maxfar, maxcur);
        }
        return maxfar;
    }
};
// @lc code=end
