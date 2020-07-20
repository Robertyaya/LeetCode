/*
 * @lc app=leetcode id=12 lang=cpp
 *
 * [12] Integer to Roman
 */

// @lc code=start
class Solution
{
public:
    /**
     * The value of num
     * Time: O(num), Space: O(1)
     * 解題流程: 利用greedy的概念, 每次都能盡量用最大面額去兌換, 如果不夠換了則換成下一個面額
     * 直到num兌換完畢
 * 
 */
    string intToRoman(int num)
    {
        // Build the dict
        vector<int> val{1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        vector<string> str{"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};

        string output = "";
        for (int i = 0; i < val.size(); i++)
        {
            // 每次都是用最大的面額去兌換的概念, 不夠了則換成下一個面額
            while (num >= val[i])
            {
                num -= val[i];
                output += str[i];

                if (num <= 0)
                    return output;
            }
        }
        return output;
    }
};
// @lc code=end
