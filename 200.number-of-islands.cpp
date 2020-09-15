/*
 * @lc app=leetcode id=200 lang=cpp
 *
 * [200] Number of Islands
 */

// @lc code=start
class Solution
{
public:
    void DFS(vector<vector<char>> &grid, int i, int j)
    {
        // Out of the boundary
        if (i < 0 || j < 0 || i > grid.size() - 1 || j > grid[0].size() - 1)
            return;

        if (grid[i][j] != '1')
            return;

        grid[i][j] = '0';
        DFS(grid, i + 1, j);
        DFS(grid, i - 1, j);
        DFS(grid, i, j + 1);
        DFS(grid, i, j - 1);
    }
    int numIslands(vector<vector<char>> &grid)
    {
        int res = 0;
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                if (grid[i][j] == '1')
                {
                    res++;
                    DFS(grid, i, j);
                }
            }
        }
        return res;
    }
};
// @lc code=end
