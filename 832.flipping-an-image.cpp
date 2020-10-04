/*
 * @lc app=leetcode id=832 lang=cpp
 *
 * [832] Flipping an Image
 */

// @lc code=start
class Solution
{
    /**
     * Time: O(N^2), Space: O(N^2)
     */
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>> &A)
    {
        if (A.empty() || A[0].empty())
            return {};

        // Reverse every row
        for (int i = 0; i < A.size(); i++)
            reverse(A[i].begin(), A[i].end());

        for (int i = 0; i < A.size(); i++)
        {
            for (int j = 0; j < A[i].size(); j++)
                A[i][j] ^= 1; // 利用XOR
        }
        return A;
    }
};
// @lc code=end
