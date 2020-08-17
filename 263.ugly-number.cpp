/*
 * @lc app=leetcode id=263 lang=cpp
 *
 * [263] Ugly Number
 *
 * https://leetcode.com/problems/ugly-number/description/
 *
 * algorithms
 * Easy (41.53%)
 * Likes:    527
 * Dislikes: 652
 * Total Accepted:    210.9K
 * Total Submissions: 507.1K
 * Testcase Example:  '6'
 *
 * Write a program to check whether a given number is an ugly number.
 * 
 * Ugly numbers are positive numbers whose prime factors only include 2, 3, 5.
 * 
 * Example 1:
 * 
 * 
 * Input: 6
 * Output: true
 * Explanation: 6 = 2 × 3
 * 
 * Example 2:
 * 
 * 
 * Input: 8
 * Output: true
 * Explanation: 8 = 2 × 2 × 2
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: 14
 * Output: false 
 * Explanation: 14 is not ugly since it includes another prime factor 7.
 * 
 * 
 * Note:
 * 
 * 
 * 1 is typically treated as an ugly number.
 * Input is within the 32-bit signed integer range: [−2^31,  2^31 − 1].
 * 
 */

// @lc code=start
class Solution
{
    /**
     * Time: O(N), Space: O(1)
     * 解題流程: 利用recursive分解數字下去
     */
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
};
// @lc code=end
