/*
 * @lc app=leetcode id=347 lang=cpp
 *
 * [347] Top K Frequent Elements
 */

// @lc code=start
class Solution
{
    /**
     * Time: O(NlogN), Space: O(N)
     * 解題流程: 利用unordered_map統計各數字出現的次數
     * 再將數字以及對應的count放入priority_queue中
     * 其中first為count value, second才為數字
     * 因為要依造數字排大小
     * 接著最後再依序pop出來
     */
public:
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        // O(1)
        unordered_map<int, int> map;
        for (int i = 0; i < nums.size(); i++)
            map[nums[i]]++;

        // Max heap, O(logN)
        priority_queue<pair<int, int>> queue;
        for (auto v : map)
        {
            // 依據數字出現次數做排序, 因此second放前面
            queue.push({v.second, v.first});
        }

        vector<int> res;
        // O(NlogN)
        for (int i = 1; i <= k; i++)
        {
            auto v = queue.top();
            res.push_back(v.second);
            queue.pop();
        }
        return res;
    }
};
// @lc code=end
