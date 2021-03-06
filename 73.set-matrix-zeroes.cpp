/*
 * @lc app=leetcode id=73 lang=cpp
 *
 * [73] Set Matrix Zeroes
 *
 * https://leetcode.com/problems/set-matrix-zeroes/description/
 *
 * algorithms
 * Medium (42.95%)
 * Likes:    2185
 * Dislikes: 305
 * Total Accepted:    323.3K
 * Total Submissions: 751K
 * Testcase Example:  '[[1,1,1],[1,0,1],[1,1,1]]'
 *
 * Given a m x n matrix, if an element is 0, set its entire row and column to
 * 0. Do it in-place.
 * 
 * Example 1:
 * 
 * 
 * Input: 
 * [
 * [1,1,1],
 * [1,0,1],
 * [1,1,1]
 * ]
 * Output: 
 * [
 * [1,0,1],
 * [0,0,0],
 * [1,0,1]
 * ]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: 
 * [
 * [0,1,2,0],
 * [3,4,5,2],
 * [1,3,1,5]
 * ]
 * Output: 
 * [
 * [0,0,0,0],
 * [0,4,5,0],
 * [0,3,1,0]
 * ]
 * 
 * 
 * Follow up:
 * 
 * 
 * A straight forward solution using O(mn) space is probably a bad idea.
 * A simple improvement uses O(m + n) space, but still not the best
 * solution.
 * Could you devise a constant space solution?
 * 
 * 
 */

// @lc code=start
class Solution
{
    /**
     * Time: O(M*N), Space: O(1)
     * 解題流程:
     * ex: 0 1 3 5 6
     *     4 5 7 0 3
     *     0 2 1 3 5 
     *     0 1 6 7 8
     * 紀錄要變為0的row和col, 最後面再將其填為0
     */
public:
    void setZeroes(vector<vector<int>> &matrix)
    {
        if (matrix.empty() || matrix[0].empty())
            return;

        vector<int> row_index;
        vector<int> col_index;
        for (int i = 0; i < matrix.size(); i++)
        {
            for (int j = 0; j < matrix[0].size(); j++)
            {
                if (matrix[i][j] == 0)
                {
                    row_index.push_back(i);
                    col_index.push_back(j);
                }
            }
        }

        for (auto row : row_index)
        {
            for (int i = 0; i < matrix[0].size(); i++)
                matrix[row][i] = 0;
        }
        for (auto col : col_index)
        {
            for (int i = 0; i < matrix.size(); i++)
                matrix[i][col] = 0;
        }
    }
};
// @lc code=end
