/*
 * @lc app=leetcode id=240 lang=cpp
 *
 * [240] Search a 2D Matrix II
 */

// @lc code=start
class Solution
{
    /**
     * Time: O(N), Space: O(1)
     */
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        if (matrix.empty() || matrix[0].empty())
            return false;
        int row = matrix.size() - 1;
        int col = matrix[0].size() - 1;

        // 比左上角小或比右下角大, 直接return false
        if (matrix[0][0] > target || matrix[row][col] < target)
            return false;

        // 從左下角開始搜, 因為左下角的數字, 就兩個方向, 往右變大, 往上變小
        int x = matrix.size() - 1;
        int y = 0;
        while (true)
        {
            if (matrix[x][y] == target)
                return true;
            else if (matrix[x][y] > target) // 往上搜
                x--;
            else // 往右搜
                y++;
            if (x < 0 || y >= matrix[0].size())
                break;
        }
        return false;
    }
};
// @lc code=end
