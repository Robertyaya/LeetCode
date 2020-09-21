/*
 * @lc app=leetcode id=647 lang=cpp
 *
 * [647] Palindromic Substrings
 */

// @lc code=start
class Solution
{
    /**
     * Time: O(N^2), Space: O(N^2)
     * 區間dp, dp[i][j]代表[i,j]這個區間內, 有幾個回文
     */
public:
    int countSubstrings(string s)
    {
        int res = 0;
        int n = s.size();
        vector<vector<bool>> dp(n, vector<bool>(n));
        // 左邊界
        for (int i = n - 1; i >= 0; i--)
        {
            // 右邊界
            for (int j = i; j < n; j++)
            {
                // 當s[i]==s[j]則去check往內縮一個字串是否為回文, dp[i+1][j-1]
                // 這邊要注意一個條件是j-i<=2, 代表指向同一個或是中間夾一個, 但因為s[i] == s[j]
                // 因此這個一定是回文
                // ex: b a b dp[0][2], s[0]==s[2], j-i<=2, 因此一定是回文
                if (s[i] == s[j] && (j - i <= 2 || dp[i + 1][j - 1]))
                {
                    dp[i][j] = true;
                    res++;
                }
            }
        }
        return res;
    }
};
// @lc code=end
