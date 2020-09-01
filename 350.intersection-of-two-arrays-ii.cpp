/*
 * @lc app=leetcode id=350 lang=cpp
 *
 * [350] Intersection of Two Arrays II
 */

// @lc code=start
class Solution
{
public:
    /**
     * Time: O(NlogN), Space: O(1)
 */
    vector<int> intersect(vector<int> &nums1, vector<int> &nums2)
    {
        // O(NlogN)
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        int i = 0, j = 0;
        vector<int> res;
        // O(N)
        while (i < nums1.size() && j < nums2.size())
        {
            if (nums1[i] == nums2[j])
            {
                res.push_back(nums1[i]);
                i++;
                j++;
            }
            else if (nums1[i] < nums2[j])
                i++;
            else
                j++;
        }
        return res;
    }
    /**
 * Time: O(N), Space: O(N)
 */
    vector<int> intersect(vector<int> &nums1, vector<int> &nums2)
    {
        unordered_map<int, int> map;
        for (auto v : nums1)
            map[v]++;

        vector<int> res;
        for (auto v : nums2)
        {
            if (map[v] != 0)
            {
                res.push_back(v);
                map[v]--;
            }
        }
        return res;
    }
};
// @lc code=end
