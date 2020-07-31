/*
 * @lc app=leetcode id=119 lang=cpp
 *
 * [119] Pascal's Triangle II
 *
 * https://leetcode.com/problems/pascals-triangle-ii/description/
 *
 * algorithms
 * Easy (48.63%)
 * Likes:    844
 * Dislikes: 197
 * Total Accepted:    287.2K
 * Total Submissions: 587.8K
 * Testcase Example:  '3'
 *
 * Given a non-negative index k where k ≤ 33, return the k^th index row of the
 * Pascal's triangle.
 * 
 * Note that the row index starts from 0.
 * 
 * 
 * In Pascal's triangle, each number is the sum of the two numbers directly
 * above it.
 * 
 * Example:
 * 
 * 
 * Input: 3
 * Output: [1,3,3,1]
 * 
 * 
 * Follow up:
 * 
 * Could you optimize your algorithm to use only O(k) extra space?
 * 
 */

// @lc code=start
class Solution
{
    /**
     * Time: O(N^2), Space: O(1)
     * 解題流程: 只用一個vector去紀錄上一層的數值就好
     */
public:
    vector<int> getRow(int rowIndex)
    {
        if (rowIndex == 0)
            return {1};
        if (rowIndex == 1)
            return {1, 1};

        vector<int> res;
        vector<int> pre = {1, 1};

        for (int i = 2; i <= rowIndex + 1; i++)
        {
            res.resize(i, 1);
            int index = 0;
            for (int j = 1; j < i - 1 && index < pre.size(); j++)
            {
                res[j] = pre[index] + pre[index + 1];
                index++;
            }
            pre = res;
        }
        return res;
    }
};
// @lc code=end
