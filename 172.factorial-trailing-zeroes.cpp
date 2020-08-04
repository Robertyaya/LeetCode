/*
 * @lc app=leetcode id=172 lang=cpp
 *
 * [172] Factorial Trailing Zeroes
 */

// @lc code=start
class Solution
{
    /**
     * Time: O(logN), Space: O(1)
     * 解題流程: 此題要找出結尾為0
     * 10=5*2, 而2的數量一定夠, 因此此題關鍵在於找出1~n中5的各數
     * ex: 10!
     * 裡面5的個數2個, 5 and 10
     * ex: 11!
     * 也是兩個 11/5=2
     * 然後25本身就會算兩個
     * 因此25!-> 25/5=5 基本的有5個
     * 5/5=1再加1個
     * 總共6個
     * 
     */
public:
    int trailingZeroes(int n)
    {
        int res = 0;
        while (n)
        {
            res += n / 5;
            n /= 5;
        }
        return res;
    }
};
// @lc code=end

1 3 4 6 7 8 9

    11 12 13 14 15 16 17 18 19

    21 22 23 24 25 26 27 28 29
