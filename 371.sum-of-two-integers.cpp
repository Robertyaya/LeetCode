/*
 * @lc app=leetcode id=371 lang=cpp
 *
 * [371] Sum of Two Integers
 */

// @lc code=start
class Solution
{
    /**
     * 解題流程:
     * a=3(011), b=5(101)
     * a^b = 110但最後面那個應該要進位, 但利用XOR會使進位消失, 因此利用&找到進位位置後左移一個取得進位的數值之後再相加
     * a&b << 1 = 010
     * 因此變成
     * 011(新的a)+010(新的b)繼續下去同樣步驟
     * 直到carry為0
     * 
     * 
     */
public:
    int getSum(int a, int b)
    {
        int carry;
        while (b != 0)
        {
            carry = a & b;
            a = a ^ b;
            // 這邊要轉成unsigned int因為-1右移一個會越界
            b = (unsigned int)carry << 1;
        }
        return a;
    }
};
// @lc code=end
