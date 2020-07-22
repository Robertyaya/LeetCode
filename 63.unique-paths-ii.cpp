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
        int dp[m][n];

        // Initialize dp, 當在initialize時遇到障礙物時, 後面一定都沒辦法到達, 因此flag變成true, 後面都填0
        // Initial row
        bool flag = false;
        for (int i = 0; i < m; i++)
        {
            if (obstacleGrid[i][0])
                flag = true;

            if (flag)
                dp[i][0] = 0;
            else
                dp[i][0] = 1;
        }

        // Initial col
        flag = false;
        for (int i = 0; i < n; i++)
        {
            if (obstacleGrid[0][i])
                flag = true;

            if (flag)
                dp[0][i] = 0;
            else
                dp[0][i] = 1;
        }

        // Update dp array
        for (int i = 1; i < m; i++)
        {
            for (int j = 1; j < n; j++)
            {
                if (!obstacleGrid[i][j])
                    dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
                else
                    dp[i][j] = 0;
            }
        }
        return dp[m - 1][n - 1];
    }
};
// @lc code=end
