/*
 * @lc app=leetcode id=46 lang=cpp
 *
 * [46] Permutations
 */

// @lc code=start
/**
 * Time: O(N!), Space: O(N)
 * 解題流程: 一樣為Back tracking題型, 這題目的要找出所有的permutation
 * 因此在每一次for迴圈都要從0開始找起, 且遇到已經放在permut vector裡面的值需要跳過
 * 因此在這邊利用unordered_set來確認是否存在於permut vector裡面
 * ex:
 * 1
 * 1,2
 * 1,2,3
 * pop
 * 第二層的for指到下一個
 * 1,3
 * 又從頭開始找, 有在vector裡面跳過
 * 1,3,1(跳過), 1,3,2(push back), 1,3,3(跳過)
 */
class Solution
{
public:
    void DFS(vector<vector<int>> &res, vector<int> &vec, vector<int> &nums, unordered_set<int> &set)
    {
        if (vec.size() == nums.size())
        {
            res.push_back(vec);
            return;
        }

        for (int i = 0; i < nums.size(); i++)
        {
            if (!set.count(nums[i]))
            {
                vec.push_back(nums[i]);
                set.insert(nums[i]);
                DFS(res, vec, nums, set);
                vec.pop_back();
                set.erase(nums[i]);
            }
        }
    }
    vector<vector<int>> permute(vector<int> &nums)
    {
        vector<vector<int>> res;
        vector<int> vec;
        unordered_set<int> set;
        DFS(res, vec, nums, set);
        return res;
    }
};
// @lc code=end
