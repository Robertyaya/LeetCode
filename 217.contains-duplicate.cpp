/*
 * @lc app=leetcode id=217 lang=cpp
 *
 * [217] Contains Duplicate
 */

// @lc code=start
class Solution
{
    /**
     * Time: O(N), Space: O(N)
     */
public:
    bool containsDuplicate(vector<int> &nums)
    {
        unordered_set<int> set;
        for (auto v : nums)
        {
            if (set.count(v))
                return true;
            set.insert(v);
        }
        return false;
    }
};
// @lc code=end
