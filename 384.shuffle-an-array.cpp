/*
 * @lc app=leetcode id=384 lang=cpp
 *
 * [384] Shuffle an Array
 */

// @lc code=start
class Solution
{
public:
    Solution(vector<int> &nums)
    {
        vec.assign(nums.begin(), nums.end());
    }

    /** Resets the array to its original configuration and return it. */
    vector<int> reset()
    {
        return vec;
    }

    /** Returns a random shuffling of the array. */
    vector<int> shuffle()
    {
        vector<int> res(vec);
        for (int i = 0; i < vec.size(); i++)
        {
            // 隨機選當下i的後面的index
            int t = i + rand() % (res.size() - i);
            swap(res[i], res[t]);
        }
        return res;
    }

private:
    vector<int> vec;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */
// @lc code=end
