/*
 * @lc app=leetcode id=63 lang=cpp
 *
 * [63] Unique Paths II
 */

// @lc code=start
class Solution
{
    /**
     * DP
     * Time: O(M*N), Space: O(M*N)
     * 解題流程: 和problem62相同, 去udpate dp[i][j]
     * 差別在於有障礙物, 遇到障礙物時, 則那一點的dp value = 0
     * 並且在initialize時, 如果先遇到了障礙物, 那後面的dp皆為0, 因為一定沒辦法到達
     * ex:
     * x x 1 x x
     * x ..
     * 1 ..
     * x
     * 假設上面那種狀況, 那一遇到1之後, 後面都不可能到達, 因此都要填0
     */
public:
    int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
    {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        // initial row
        for (int i = 0; i < m; i++)
        {
            if (obstacleGrid[i][0] == 1)
                break;
            dp[i][0] = 1;
        }
        // Initial col
        for (int i = 0; i < n; i++)
        {
            if (obstacleGrid[0][i] == 1)
                break;
            dp[0][i] = 1;
        }

        // update dp
        for (int i = 1; i < m; i++)
        {
            for (int j = 1; j < n; j++)
            {
                // 上面加左邊的路徑個數=現在這個點的路徑個數
                if (obstacleGrid[i][j] == 0)
                    dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
        return dp[m - 1][n - 1];
    }
};
// @lc code=end
