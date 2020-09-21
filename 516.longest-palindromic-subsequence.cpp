/*
 * @lc app=leetcode id=516 lang=cpp
 *
 * [516] Longest Palindromic Subsequence
 */

// @lc code=start
class Solution
{
    /**
     * Time: O(N^2), Space: O(N^2)
     * 解題流程: 區間dp, dp[i][j]代表在[i,j]這個區間內的最長回文subsequence
     * s[i] == s[j]代表左右兩邊相同, i,j往內縮+2
     * 0 1 2 3 4 5
     * b b a a b b
     * dp[1][4] = 4
     * dp[0][5]=?, s[0]==s[5]所以dp[0][5] = dp[1][4]+2 
     * 
     * 0 1 2 3 4
     * b b b a b
     * dp[1][3]=2, s[0]==s[4]所以dp[0][4]=dp[1][3]+2
     * 
     * s[i] != s[j]i或j往內縮, 取決於哪個大
     */
public:
    int longestPalindromeSubseq(string s)
    {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n));

        // i 代表左邊的區間
        for (int i = n - 1; i >= 0; i--)
        {
            dp[i][i] = 1;
            // j 代表右邊的區間
            for (int j = i + 1; j < n; j++)
            {
                // 相同, 左邊和右邊區間都往內縮, 並且長度加2
                if (s[i] == s[j])
                    dp[i][j] = dp[i + 1][j - 1] + 2;
                else
                    dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
            }
        }
        return dp[0][n - 1];
    }
};
// @lc code=end
