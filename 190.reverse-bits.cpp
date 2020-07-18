/*
 * @lc app=leetcode id=190 lang=cpp
 *
 * [190] Reverse Bits
 */

// @lc code=start
class Solution
{
    /**
 * Time: O(1), Space: O(1)
 * 解題流程: 先取下各位的數值, 之後再從最前面填回來
 */
public:
    uint32_t reverseBits(uint32_t n)
    {
        uint32_t res = 0;
        for (int i = 0; i < 32; i++)
        {
            // 取值
            int value = (n >> i) & 1;

            // 附值
            res = res | (value << (31 - i));
        }
        return res;
    }
};
// @lc code=end
