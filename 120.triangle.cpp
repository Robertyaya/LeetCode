/*
 * @lc app=leetcode id=120 lang=cpp
 *
 * [120] Triangle
 *
 * https://leetcode.com/problems/triangle/description/
 *
 * algorithms
 * Medium (43.80%)
 * Likes:    2053
 * Dislikes: 244
 * Total Accepted:    251.2K
 * Total Submissions: 570.4K
 * Testcase Example:  '[[2],[3,4],[6,5,7],[4,1,8,3]]'
 *
 * Given a triangle, find the minimum path sum from top to bottom. Each step
 * you may move to adjacent numbers on the row below.
 * 
 * For example, given the following triangle
 * 
 * 
 * [
 * ⁠    [2],
 * ⁠   [3,4],
 * ⁠  [6,5,7],
 * ⁠ [4,1,8,3]
 * ]
 * 
 * 
 * The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).
 * 
 * Note:
 * 
 * Bonus point if you are able to do this using only O(n) extra space, where n
 * is the total number of rows in the triangle.
 * 
 */

// @lc code=start
class Solution
{
    /**
     * Time: O(N), Space: O(1)
     * 解題流程: 此題如果利用DFS所有路徑都走過, 會超時, 因此此題利用dp
     * dp[i][j]代表是這個node(i,j)到達底部的最短路徑
     * 因此轉移方程為
     * dp[i][j] = min(dp[i+1][j], dp[i+1][j+1]) + triangle[i][j]
     * min(dp[i+1][j], dp[i+1][j+1]) 代表的是下一層兩個adj node到達底部的最短路徑選比較小的那條再加上current的triangle[i][j]就能代表[i][j]這個node到達底部的最短路徑
     * 
     * 此題利用bottom-up從底部填上來
     * ex: 每一個node都會有一個dp, 目標就是從底部填上頂部
     *    2     (11)
     *   3 4    (9,10)
     *  6 5 7   (min(4,1)+6, 6, 10) 下一層的adj node的min再加上自己
     * 4 1 8 3  (4,1,8,3) 底部的dp就直接就是自己, 因為自己就是底部
     * 可以開一個2D array來紀錄, 但這樣浩空間, 我們只需要利用一個1D vector, 每一層一直update dp的數值就好
     * 第四層會有4個dp value
     * 第三層利用這4個dp value update前3個dp value
     * ...
     * 因此更新情況會是這樣
     * [4,1,8,3]
     *  * * *
     *  * *
     *  *
     * *號代表每一層更新的數值
     */
public:
    int minimumTotal(vector<vector<int>> &triangle)
    {
        if (triangle.empty() || triangle[0].empty())
            return 0;
        if (triangle.size() == 1)
            return triangle[0][0];

        vector<int> dp(triangle.back());
        // Bottom to up to fill update the dp, 從倒數第二層開始
        for (int i = triangle.size() - 1; i >= 1; i--)
        {
            // Fill the dp
            for (int j = 0; j < i; j++)
            {
                dp[j] = min(dp[j], dp[j + 1]) + triangle[i - 1][j];
            }
        }
        return dp[0];
    }
};
// @lc code=end
