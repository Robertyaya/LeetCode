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

        int left = 1;
        int right = x / 2;

        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            if (pow(mid, 2) == x)
                return mid;
            else if (pow(mid, 2) > x)
            {
                right = mid - 1;
                if (pow(right, 2) < x)
                    return right;
            }
            else
            {
                left = mid + 1;
                if (pow(left, 2) > x)
                    return mid;
            }
        }
        return -1;
    }
};
// @lc code=end
