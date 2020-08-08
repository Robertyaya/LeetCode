/*
 * @lc app=leetcode id=221 lang=cpp
 *
 * [221] Maximal Square
 */

// @lc code=start
class Solution
{
    /**
     * Time: O(N^2), Space: O(N^2)
     * 解題流程: 此題利用DP可以降為O(N^2)
     * dp[i][j]代表此格可形成最大的正方形
     * 其代表的是正方形的左下角
     * 轉移方程為 dp[i][j] = min(dp[i-1][j], dp[i][j-1], dp[i-1][j-1])
     * 左邊,上面, 以及左上角取min
     * 但這前提是current要為1, 如果不為1則此格一定為0
     */

public:
    int maximalSquare(vector<vector<char>> &matrix)
    {
        if (matrix.empty() || matrix[0].empty())
            return 0;

        // 全部先填0
        vector<vector<int>> dp(matrix.size(), vector<int>(matrix[0].size(), 0));

        // Initialize dp value, 遇到1則填1
        int square = 0;
        for (int i = 0; i < matrix.size(); i++)
        {
            if (matrix[i][0] == '1')
            {
                dp[i][0] = 1;
                square = 1;
            }
        }
        for (int i = 0; i < matrix[0].size(); i++)
        {
            if (matrix[0][i] == '1')
            {
                dp[0][i] = 1;
                square = 1;
            }
        }

        // Fill the dp
        for (int i = 1; i < matrix.size(); i++)
        {
            for (int j = 1; j < matrix[0].size(); j++)
            {
                if (matrix[i][j] == '1')
                {
                    dp[i][j] = min(min(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1]) + 1;
                    square = max(square, dp[i][j]);
                }
            }
        }
        return pow(square, 2);
    }
};
// @lc code=end
