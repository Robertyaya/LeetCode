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
    /**
     * Time: O(N^2), Space: O(N)
     * 解題流程: ugly number* 2,3,5一樣是ugly number
     * 先放入第一個ugly number 1
     * 各別乘上2,3,5再放入heap中
     */
public:
    int nthUglyNumber(int n)
    {
        priority_queue<long, vector<long>, greater<long>> pq;
        pq.push(1);
        int pre = 0;
        int t;
        // O(N^2)
        for (int i = 1; i <= n; i++)
        {
            // O(logN)
            t = pq.top();
            pq.pop();
            // 有可能會有相同數字， 不斷pop出來直到和pre ugly number不一樣
            while (!pq.empty() && t == pre)
            {
                t = pq.top();
                pq.pop();
            }

            // O(N)
            pq.push((long)t * 2);
            pq.push((long)t * 3);
            pq.push((long)t * 5);
            pre = t;
        }
        return t;
    }
};
// @lc code=end
