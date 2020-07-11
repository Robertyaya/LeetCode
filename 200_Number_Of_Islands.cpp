#include <bits/stdc++.h>
using namespace std;

/**
 * DFS version
 * M is the row, N is the col
 * Time: O(M*N) Space: O(N*M)
 * 解釋一下time complexity: 最外層兩個迴圈為N*M次, 在DFS中, 最多就是將全部node走過一遍這樣為N*M, 但走過後
 * 之後for迴圈迭代就不用在走了, 也就是每個node在for迴圈中一定只會走過4次 上下左右DFS
 * 因此為O(4MN) = O(M*N)
 * 解釋一下space complexity: 假設全部皆為1, 那麼單一個DFS就會持續search下去直到走完全部的node, 因此此時深度為M*N
 * 解題流程: 此題和problem 130相同, 也是遇到某些特別的char後開始對單點做DFS
 */
void DFS(vector<vector<char>> &grid, int i, int j, char flag)
{
  if (i == grid.size() || j == grid[0].size() || j < 0 || i < 0)
    return;

  // 當此時到達'O'代表此島斷掉了, 或是==flag代表走到之前走過的, 所以也return
  if (grid[i][j] == '0' || grid[i][j] == flag)
    return;

  if (grid[i][j] == '1')
    grid[i][j] = flag;

  DFS(grid, i + 1, j, flag); // 往下找
  DFS(grid, i - 1, j, flag); // 往上找
  DFS(grid, i, j + 1, flag); // 往右找
  DFS(grid, i, j - 1, flag); // 往左找
}
int numIslands(vector<vector<char>> &grid)
{
  if (grid.empty() || grid[0].empty())
    return 0;

  int count = 0;
  int flag = 2; // 用來將各別一座島設成不同的char
  for (int i = 0; i < grid.size(); i++)
  {
    for (int j = 0; j < grid[0].size(); j++)
    {
      // Meet the island
      if (grid[i][j] == '1')
      {
        count++; // 島++
        char ch = flag + '0';
        DFS(grid, i, j, ch);
        flag++; // 分隔不同島
      }
    }
  }
  return count;
}
