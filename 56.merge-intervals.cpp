/*
 * @lc app=leetcode id=56 lang=cpp
 *
 * [56] Merge Intervals
 */

// @lc code=start
class Solution
{
public:
    /**
 * Time: O(NlogN), Space: O(N)
 * 解題流程: 
 * 1. 第一步要先根據start_index做sorting, 讓start_index都是從小到大
 * 2. 接著traverse每一個元素, 如果start_index > 前一個在output中的end還大,
 * 那代表不用merge, 反之則需要merge
 * 需要merge的話有兩種情況
 * ex: [1,3] [2,4] or [1,3] [2,2]
 * 因此右邊boundary是選"max index"
 * 
 */
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        if (intervals.empty())
            return {};

        // O(NlogN)
        auto cmp = [](auto a, auto b) {
            return a[0] < b[0];
        };
        sort(intervals.begin(), intervals.end(), cmp);

        vector<vector<int>> output;
        output.push_back(intervals[0]);

        // O(N)
        for (int i = 1; i < intervals.size(); i++)
        {
            int start_index = intervals[i][0];
            int end_index = intervals[i][1];
            // Don't need to merge, directly push_back in output
            if (start_index > output.back()[1])
                output.push_back(intervals[i]);
            else // Need to merge, modify the end_index, choose the max one
                output.back()[1] = max(output.back()[1], end_index);
        }
        return output;
    }
};
// @lc code=end
