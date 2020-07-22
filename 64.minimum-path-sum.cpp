/*
 * @lc app=leetcode id=64 lang=cpp
 *
 * [64] Minimum Path Sum
 */

// @lc code=start
class Solution
{
    /**
     * Dynamic Programming
     * Time: O(M*N), Space: O(M*N)
     * 
     * dp[i][j] 紀錄到達此點的最短路徑
     * dp[i][j] = (此點的value) + min((上面那一點的最短路徑dp[i][j-1]), (左邊那點的最短路徑dp[i-1][j]))
     */
public:
    int minPathSum(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        int dp[m][n];

        // Initial row
        dp[0][0] = grid[0][0];
        for (int i = 1; i < m; i++)
            dp[i][0] = grid[i][0] + dp[i - 1][0];

        // Initial col
        for (int i = 1; i < n; i++)
            dp[0][i] = grid[0][i] + dp[0][i - 1];

        // Update dp

        for (int i = 1; i < m; i++)
        {
            for (int j = 1; j < n; j++)
            {
                dp[i][j] = grid[i][j] + min(dp[i - 1][j], dp[i][j - 1]);
            }
        }
        return dp[m - 1][n - 1];
    }
};
// @lc code=end
