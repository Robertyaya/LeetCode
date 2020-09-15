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

        vector<int> prev = {1};
        for (int i = 1; i <= rowIndex; i++)
        {
            vector<int> cur;
            cur.push_back(1);
            for (int j = 0; j < prev.size() - 1; j++)
            {
                cur.push_back(prev[j] + prev[j + 1]);
            }
            cur.push_back(1);
            prev = cur;
        }
        return prev;
    }
};
// @lc code=end
