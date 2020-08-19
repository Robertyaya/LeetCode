/*
 * @lc app=leetcode id=668 lang=cpp
 *
 * [668] Kth Smallest Number in Multiplication Table
 */

// @lc code=start
class Solution
{
    /**
     * Time: O(NlogN), Space: O(1)
     * 解題流程: mid代表的就是target num
     * 進入enough function去判斷此target num為第幾大的數字
     */
public:
    bool Enough(int &value, int &m, int &n, int &k)
    {
        // 紀錄總共超過幾個數字, 也就是input value為第幾個數字的意思
        int count = 0;
        for (int i = 1; i <= m; i++)
        {
            // value/i 代表在那一row有超過幾個數字
            int add = min(value / i, n);
            count += add;
        }

        return count >= k;
    }
    int findKthNumber(int m, int n, int k)
    {
        int l = 1;     // 最小的數字
        int r = m * n; // 最大的數字
        while (l < r)
        {
            int mid = l + (r - l) / 2;
            if (Enough(mid, m, n, k))
                r = mid;
            else
                l = mid + 1;
        }
        return l;
    }
};
// @lc code=end
