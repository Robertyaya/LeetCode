/*
 * @lc app=leetcode id=228 lang=cpp
 *
 * [228] Summary Ranges
 */

// @lc code=start
class Solution
{
    /**
     * Time: O(N), Space: O(N)
     */
public:
    vector<string> summaryRanges(vector<int> &nums)
    {
        if (nums.empty())
            return {};

        string str = "";
        vector<string> res;
        int j = 0;
        for (int i = 1; i < nums.size(); i++)
        {
            // Avoid overflow
            long long temp = (long long)nums[i] - nums[i - 1];
            if (temp > 1)
            {
                if (j == i - 1)
                    str += (to_string(nums[j]));
                else
                {
                    str += (to_string(nums[j]));
                    str += "->";
                    str += (to_string(nums[i - 1]));
                }
                j = i;
                res.push_back(str);
                str = "";
            }
        }

        // 最後面的情況
        if (j != nums.size() - 1)
        {
            str += (to_string(nums[j]));
            str += "->";
            str += (to_string(nums[nums.size() - 1]));
            res.push_back(str);
        }
        else
            res.push_back(to_string(nums[j]));

        return res;
    }
};
// @lc code=end
