/*
 * @lc app=leetcode id=867 lang=cpp
 *
 * [867] Transpose Matrix
 */

// @lc code=start
class Solution
{
    /**
     * Time: O(N^2), Space: O(N^2)
     */
public:
    vector<vector<int>> transpose(vector<vector<int>> &A)
    {
        // 可能不為方陣, 因此transpose的row size and col size會和A相反
        vector<vector<int>> res(A[0].size(), vector<int>(A.size(), 0));
        for (int i = 0; i < A.size(); i++)
        {
            for (int j = 0; j < A[0].size(); j++)
            {
                res[j][i] = A[i][j];
            }
        }
        return res;
    }
};
// @lc code=end
