/*
 * @lc app=leetcode id=84 lang=cpp
 *
 * [84] Largest Rectangle in Histogram
 */

// @lc code=start
class Solution
{
    /**
     * Time: O(N), Space: O(N)
     * Monotone stack
     */
public:
    int largestRectangleArea(vector<int> &heights)
    {
        // 避免edge case情況
        heights.insert(heights.begin(), 0);
        heights.push_back(0);
        int max_area = 0;
        stack<int> sta;
        for (int i = 0; i < heights.size(); i++)
        {
            if (sta.empty() || heights[i] > heights[sta.top()])
            {
                sta.push(i);
            }
            else // 當現在的height比stack top的height還小時, 則開始計算面積
            {
                while (heights[sta.top()] > heights[i])
                {
                    int h = sta.top();
                    sta.pop();
                    /**
                     * 跳出條件為遇到比現在heigh還矮的高度
                     * ex:[3,4,5,2] 計算[3,4,5]
                     * 5*1, 4*2, 3*3 看哪個大
                     * i-1-sta.top()為width
                     */
                    max_area = max(max_area, heights[h] * (i - 1 - sta.top()));
                }
                sta.push(i);
            }
        }
        return max_area;
    }
};
// @lc code=end
