/*
 * @lc app=leetcode id=349 lang=cpp
 *
 * [349] Intersection of Two Arrays
 */

// @lc code=start
class Solution
{
    /**
     * Time: O(N), Space: O(N)
     */
public:
    vector<int> intersection(vector<int> &nums1, vector<int> &nums2)
    {
        unordered_set<int> set;
        for (auto v : nums1)
        {
            if (!set.count(v))
                set.insert(v);
        }

        vector<int> res;
        for (auto v : nums2)
        {
            if (set.count(v))
            {
                res.push_back(v);
                set.erase(v);
            }
        }
        return res;
    }
};
// @lc code=end
