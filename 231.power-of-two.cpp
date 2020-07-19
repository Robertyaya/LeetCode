/*
 * @lc app=leetcode id=231 lang=cpp
 *
 * [231] Power of Two
 */

// @lc code=start
class Solution
{
    /**
 * Time: O(1), Space: O(1)
 * 解題流程: 要判斷是否為2的倍數, 以二進制來看2的倍數就是
 * ex: 10, 100, 1000, 10000 ....
 * 也就是只會有一個1
 * 因此流程就是取各位數字, 當遇到1之後進去判斷是否有和原本數值相同, 相同則代表就是只有一個1因此為2的倍數
 * 反之則不是
 * ex: 1010
 * 遇到第一個1之後將和0010取&來判斷
 * 1010
 * 0010 &
 * ------
 * 0010 != 1010
 * 因此這個不是2的倍數
 * 
 * ex: 1001000
 * 1001000
 * 0001000 &
 * --------
 * 0001000 != 1001000
 * 因此也不是2的倍數
 */
public:
    bool isPowerOfTwo(int n)
    {
        if (n < 0)
            return false;

        for (int i = 0; i < 32; i++)
        {
            // 取出各位數字
            int value = (n >> i) & 1;
            if (value)
            {
                return n == (n & (1 << i));
            }
        }
        return false;
    }
};
// @lc code=end
