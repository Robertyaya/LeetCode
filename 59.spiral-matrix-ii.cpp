/*
 * @lc app=leetcode id=59 lang=cpp
 *
 * [59] Spiral Matrix II
 */

// @lc code=start
class Solution
{
    /**
     * Time: O(N^2), Space: O(1)
     */
public:
    vector<vector<int>> generateMatrix(int n)
    {
        vector<vector<int>> matrix(n, vector<int>(n, 0));
        // 先定義好右->下->左->右的方向， 當遇到牆壁或是已填過的數字代表需要換方向
        vector<pair<int, int>> direction = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        int k = 0;
        int i = 1;
        int start_x = 0;
        int start_y = 0;
        while (i <= n * n)
        {
            matrix[start_x][start_y] = i;
            // 確認下一步是否碰到牆壁或是已填過的數字, 則需要換方向
            int x = start_x + direction[k % 4].first;
            int y = start_y + direction[k % 4].second;
            if (x < 0 || x >= n || y < 0 || y >= n || matrix[x][y] != 0)
                k++;

            // update 下一步的位置
            start_x += direction[k % 4].first;
            start_y += direction[k % 4].second;
            i++;
        }
        return matrix;
    }
};
// @lc code=end
