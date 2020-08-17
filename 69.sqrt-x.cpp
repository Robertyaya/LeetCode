/*
 * @lc app=leetcode id=69 lang=cpp
 *
 * [69] Sqrt(x)
 */

// @lc code=start
class Solution
{
    /**
     * Time: O(logN), Space: O(1)
     * 解題流程: 利用binary search來找比較快
     */
public:
    int mySqrt(int x)
    {
        if (x == 0 || x == 1)
            return x;
        int l = 1;
        int r = x / 2 + 1;
        while (l < r)
        {
            long mid = l + (r - l) / 2;
            if (mid * mid > x)
                r = mid;
            else
                l = mid + 1;
        }
        return l - 1;
    }
};
// @lc code=end
