/*
 * @lc app=leetcode id=167 lang=cpp
 *
 * [167] Two Sum II - Input array is sorted
 */

// @lc code=start
class Solution
{
    /**
     * Time: O(N), Space: O(1)
     */
public:
    vector<int> twoSum(vector<int> &numbers, int target)
    {
        vector<int> res;
        int l = 0;
        int r = numbers.size() - 1;
        while (l < r)
        {
            if (numbers[l] + numbers[r] == target)
                return {l + 1, r + 1};
            else if (numbers[l] + numbers[r] < target)
                l++;
            else
                r--;
        }
        return {};
    }
};
// @lc code=end
