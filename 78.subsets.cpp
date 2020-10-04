/*
 * @lc app=leetcode id=78 lang=cpp
 *
 * [78] Subsets
 */

// @lc code=start
/**
 * Time: O(2^N), Space: O(N)
 * 每個數字就是取或不取兩種可能, 因此time為2^N
 * 解題流程: Same as problem 40
 * 這題比較簡單, 就是tranverse所有可能塞入answer裡面, 
 * 而problem 40是要加起來等於特定的target value才能加進去
 */
class Solution
{
public:
    void DFS(vector<int> &nums, vector<int> &vec, vector<vector<int>> &res, int level)
    {
        res.push_back(vec);
        // Back tracking
        for (int i = level; i < nums.size(); i++)
        {
            vec.push_back(nums[i]);
            DFS(nums, vec, res, i + 1);
            vec.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int> &nums)
    {
        vector<vector<int>> res;
        vector<int> vec;
        DFS(nums, vec, res, 0);
        return res;
    }
};
// @lc code=end
