/*
 * @lc app=leetcode id=62 lang=cpp
 *
 * [62] Unique Paths
 */

// @lc code=start
class Solution
{
    /**
     * Time: O(N), Space: O(1)
     * 解題流程: 
     * m = 4, n = 3
     * rrrrddd
     * 
     * 這7個數字排列組和
     * 7!/(4!*3!)
     * 
     * 用此算式下去做
     * 7!/(4!*3!) -> (7*6*5)/3!
     */
public:
    int uniquePaths(int m, int n)
    {
        int m_ = m - 1;
        int n_ = n - 1;
        int c_ = m_ + n_;
        if (m_ == 0 || n_ == 0)
            return 1;

        int max, min;
        if (m_ > n_)
        {
            max = m_;
            min = n_;
        }
        else
        {
            max = n_;
            min = m_;
        }

        long long temp = 1;
        for (long long i = c_; i > max; i--)
            temp *= i;

        long long temp2 = 1;
        for (long long i = 1; i <= min; i++)
            temp2 *= i;
        return temp / temp2;
    }

    /**
     * Dynamic Programming
     * Time: O(M*N), Space: O(M*N)
     * dp[i][j] 代表到那一格的總共路徑為多少條
     * dp[i][j] = dp[i-1][j]+dp[i][j-1]
     * 起點到上面那一個的路徑+起點到左邊那一個的路徑 兩個相加就是到現在這一格的總路徑
     */
    int uniquePaths(int m, int n)
    {
        int dp[m][n];
        // Initialize
        for (int i = 0; i < m; i++)
            dp[i][0] = 1;
        for (int j = 0; j < n; j++)
            dp[0][j] = 1;

        for (int i = 1; i < m; i++)
        {
            for (int j = 1; j < n; j++)
            {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
        return dp[m - 1][n - 1];
    }
};
// @lc code=end
