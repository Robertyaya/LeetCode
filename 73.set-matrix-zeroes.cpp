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
     * 1. 先掃[0][i] and [i][0] 確認是否有0, 有0代表整條都會為0因此先用bool記起來後面再改數字
     * 2. 從[1][1]開始掃也就是扣除剛掃過的row and col, 如果過程中有遇到0, 先將其[i][0] and [0][i]標記成0 (記錄下來的概念)
     * 3. 再從[1][1]開始掃, 如果遇到[i][0], or [0][i]為0, 則[i][j]為0
     * 4. 根據第一步的bool, 如果row or col為true, 代表整條為0 則填為0
     */
public:
    void setZeroes(vector<vector<int>> &matrix)
    {
        if (matrix.empty() || matrix[0].empty())
            return;

        int m = matrix.size();
        int n = matrix[0].size();
        bool row = false;
        bool col = false;

        // row
        for (int i = 0; i < m; i++)
        {
            if (matrix[i][0] == 0)
                row = true;
        }

        // col
        for (int i = 0; i < n; i++)
        {
            if (matrix[0][i] == 0)
                col = true;
        }

        // 掃過一次標記
        for (int i = 1; i < m; i++)
        {
            for (int j = 1; j < n; j++)
            {
                if (matrix[i][j] == 0)
                {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }

        // Fill the zero
        for (int i = 1; i < m; i++)
        {
            for (int j = 1; j < n; j++)
            {
                if (matrix[i][0] == 0 || matrix[0][j] == 0)
                    matrix[i][j] = 0;
            }
        }

        if (row)
        {
            for (int i = 0; i < m; i++)
                matrix[i][0] = 0;
        }
        if (col)
        {
            for (int i = 0; i < n; i++)
                matrix[0][i] = 0;
        }
    }
};
// @lc code=end
