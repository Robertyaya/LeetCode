/*
 * @lc app=leetcode id=7 lang=cpp
 *
 * [7] Reverse Integer
 */

// @lc code=start
class Solution
{
    /**
 * The length of x is N
 * Time: O(N), Space: O(1)
 * 解題流程: 如果想要取一個整數的各位數字的作法就是
 * ex: 321
 * 321 % 10 = 1 *
 * 321/=10 = 32
 * 32 % 10 = 2 *
 * 32/=10 = 3
 * 3 % 10 = 3 *
 * 這樣就可以取得各位數字
 */
public:
    int reverse(int x)
    {
        int original = x;
        // 先用longlong才save答案, 避免out_of_range int
        // 確定沒越界再轉成int return
        long long res = 0;
        while (abs(x) > 0)
        {
            res = (10 * res + abs(x) % 10);
            x /= 10;
        }

        if (original < 0)
            res *= -1;

        return (res > INT_MAX || res < INT_MIN) ? 0 : res;
    }
};
// @lc code=end
