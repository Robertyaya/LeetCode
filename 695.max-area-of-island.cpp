/*
 * @lc app=leetcode id=695 lang=cpp
 *
 * [695] Max Area of Island
 */

// @lc code=start
class Solution
{
    /**
     * Time: O(N), Space: O(N)(system stack)
     * 解題流程: DFS
     */
public:
    void Island(vector<vector<int>> &grid, int i, int j, int &island)
    {
        // 超過邊界
        if (i >= grid.size() || i < 0 || j >= grid[0].size() || j < 0)
            return;

        if (grid[i][j] == 1)
        {
            island++;
            grid[i][j] = -1;
        }
        else // 若不為1, 則代表island斷掉了, return回去
            return;

        // 往4個方向搜
        Island(grid, i - 1, j, island);
        Island(grid, i + 1, j, island);
        Island(grid, i, j - 1, island);
        Island(grid, i, j + 1, island);
    }
    int maxAreaOfIsland(vector<vector<int>> &grid)
    {
        if (grid.empty() || grid[0].empty())
            return 0;

        int max_island = 0;
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                if (grid[i][j] == 1)
                {
                    int island = 0;
                    Island(grid, i, j, island);
                    max_island = max(max_island, island);
                }
            }
        }
        return max_island;
    }
};
// @lc code=end
