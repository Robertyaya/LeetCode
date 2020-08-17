/*
 * @lc app=leetcode id=264 lang=cpp
 *
 * [264] Ugly Number II
 *
 * https://leetcode.com/problems/ugly-number-ii/description/
 *
 * algorithms
 * Medium (41.87%)
 * Likes:    2008
 * Dislikes: 123
 * Total Accepted:    181.3K
 * Total Submissions: 431.1K
 * Testcase Example:  '10'
 *
 * Write a program to find the n-th ugly number.
 * 
 * Ugly numbers are positive numbers whose prime factors only include 2, 3,
 * 5. 
 * 
 * Example:
 * 
 * 
 * Input: n = 10
 * Output: 12
 * Explanation: 1, 2, 3, 4, 5, 6, 8, 9, 10, 12 is the sequence of the first 10
 * ugly numbers.
 * 
 * Note:  
 * 
 * 
 * 1 is typically treated as an ugly number.
 * n does not exceed 1690.
 * 
 */

// @lc code=start
class Solution
{
public:
    bool isUgly(int num)
    {
        // Base case
        if (num == 0)
            return false;
        if (num == 1 || num == 2 || num == 3 || num == 5)
            return true;

        if (num % 2 == 0 && isUgly(num / 2))
            return true;
        if (num % 3 == 0 && isUgly(num / 3))
            return true;
        if (num % 5 == 0 && isUgly(num / 5))
            return true;
        return false;
    }
    int nthUglyNumber(int n)
    {
        int i = 1;
        int count = 0;
        while (count < n)
        {
            if (isUgly(i))
            {
                count++;
            }
            i++;
        }
        return i - 1;
    }
};
// @lc code=end
