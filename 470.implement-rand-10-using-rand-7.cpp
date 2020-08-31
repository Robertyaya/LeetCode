/*
 * @lc app=leetcode id=470 lang=cpp
 *
 * [470] Implement Rand10() Using Rand7()
 */

// @lc code=start
// The rand7() API is already defined for you.
// int rand7();
// @return a random integer in the range 1 to 7

class Solution
{
    /**
     */
public:
    int rand10()
    {
        int value = 40;
        while (value >= 40)
        {
            // 此處將1~7範圍擴大到0~48
            // 如果出來數字大於40則繼續嘗試
            value = (rand7() - 1) * 7 + (rand7() - 1);
        }
        return value % 10 + 1;
    }
};
// @lc code=end
