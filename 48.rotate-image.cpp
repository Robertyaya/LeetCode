/*
 * @lc app=leetcode id=48 lang=cpp
 *
 * [48] Rotate Image
 */

// @lc code=start
class Solution
{
public:
    void rotate(vector<vector<int>> &matrix)
    {
        if (matrix.empty() || matrix[0].empty())
            return;

        int l = 0;
        int r = matrix.size() - 1;
        for (int level = 0; level < matrix.size() / 2; level++)
        {
            // Top to temp
            vector<int> temp;
            for (int i = l; i <= r; i++)
            {
                temp.push_back(matrix[level][i]);
            }

            // Left to top
            for (int i = l; i <= r; i++)
            {
                matrix[level][r - i + level] = matrix[i][level];
            }

            // Bottom to right
            for (int i = l; i <= r; i++)
            {
                matrix[i][level] = matrix[r][i];
            }

            // Right to bottom
            for (int i = l; i <= r; i++)
            {
                matrix[r][i] = matrix[r - i + level][r];
            }

            // Temp to right
            int j = 0;
            for (int i = l; i <= r; i++)
            {
                matrix[i][r] = temp[j++];
            }
            l++;
            r--;
        }
    }
};
// @lc code=end
