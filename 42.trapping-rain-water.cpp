/*
 * @lc app=leetcode id=42 lang=cpp
 *
 * [42] Trapping Rain Water
 */

// @lc code=start
/**
 * Time: O(N), Space: O(N)
 * Monotone stack
 * 
 */
class Solution
{
public:
    int trap(vector<int> &height)
    {
        stack<int> sta;
        int i = 0, res = 0;
        while (i < height.size())
        {
            if (sta.empty() || height[i] <= height[sta.top()])
                sta.push(i++);
            else
            {
                int compare_height = height[sta.top()];
                sta.pop();
                if (sta.empty())
                    continue;

                // width
                int w = i - 1 - sta.top();

                // 此處為高度差值, 前一個和前前一個, 那如果高度超過現在的高度, 那存水量的高度就會是現在的高度為主
                // ex: 3,2,1,4
                /**
                 * 2,1造成的存水量 高為2-1, 寬為1
                 * 3,2造成的存水量 高為3-2, 寬為2
                 */
                int h = min(height[sta.top()], height[i]) - compare_height;
                res += w * h;
            }
        }
        return res;
    }
};
// @lc code=end
