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
        int start = 0;
        int end = matrix[0].size() - 1;
        int offset = 0;

        while (offset <= matrix.size() / 2)
        {
            // Top to temp
            vector<int> temp;
            for (int i = start; i <= end; i++)
            {
                temp.push_back(matrix[offset][i]);
            }

            // Left to top
            for (int i = start; i <= end; i++)
            {
                /**
                 * (end-i+offset)
                 * 3~0
                 * 2~1
                 */
                matrix[offset][end - i + offset] = matrix[i][offset];
            }

            // Bottom to left
            for (int i = start; i <= end; i++)
            {
                matrix[i][offset] = matrix[end][i];
            }

            // Right to bottom
            for (int i = start; i <= end; i++)
            {
                matrix[end][i] = matrix[end - i + offset][end];
            }

            // temp to right
            for (int i = start; i <= end; i++)
            {
                matrix[i][end] = temp[i - offset];
            }

            offset++;
            start++;
            end--;
        }
    }
};
// @lc code=end
