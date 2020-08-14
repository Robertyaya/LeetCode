/*
 * @lc app=leetcode id=258 lang=cpp
 *
 * [258] Add Digits
 */

// @lc code=start
class Solution
{
public:
    /**
     * Time: O(1)
     * 1~9為一個循環
     * 需要特別處理的是0時為return 0
     * 或是為9的倍數時, ex: 45
     * 45%9==0 但應該要return 9
     * 因此修改為 44%9+1
     */
    int addDigits(int num)
    {
        if (num == 0)
            return 0;
        return (num - 1) % 9 + 1;
    }
    /**
     * Iterative version
     */
    int addDigits(int num)
    {
        int temp = 0;
        while (1)
        {
            while (num != 0)
            {
                // 各位數字相加
                temp += num % 10;
                num /= 10;
            }
            // 相加後為個位數, return
            if (temp / 10 == 0)
                break;
            num = temp;
            temp = 0;
        }
        return temp % 10;
    }
};
// @lc code=end
