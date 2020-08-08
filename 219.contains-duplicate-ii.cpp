/*
 * @lc app=leetcode id=219 lang=cpp
 *
 * [219] Contains Duplicate II
 */

// @lc code=start
class Solution
{
    /**
     * Time: O(N), Space: O(N)
     */
public:
    bool containsNearbyDuplicate(vector<int> &nums, int k)
    {
        unordered_map<int, int> map;
        for (int i = 0; i < nums.size(); i++)
        {
            if (auto iter = map.find(nums[i]) != map.end())
            {
                if (i - map[nums[i]] <= k)
                    return true;
            }
            map[nums[i]] = i;
        }
        return false;
    }
};
// @lc code=end
