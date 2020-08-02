#include <bits/stdc++.h>
using namespace std;
bool Check(vector<vector<int>> &grid)
{
  for (int i = 0; i < grid.size(); i++)
  {
    if (grid[i][i] != 1)
      return false;
  }
  return true;
}

void Swap(vector<vector<int>> &grid, int row1, int row2)
{
  if (row1 == row2)
    return;
  for (int i = row2; i > row1; i--)
  {
    swap(grid[i], grid[i - 1]);
  }
}
void Print(vector<vector<int>> &grid)
{
  for (int i = 0; i < grid.size(); i++)
  {
    for (int j = 0; j < grid[0].size(); j++)
      cout << grid[i][j] << " ";
    cout << endl;
  }
  cout << endl;
}
bool Switch(vector<vector<int>> &grid, int &count, int level)
{
  if (level == grid.size() - 1 && Check(grid))
    return true;

  for (int i = level; i < grid.size(); i++)
  {

    if (grid[i][level] == 1)
    {
      Swap(grid, level, i);
      count += (i - level);
      //Print(grid);

      if (Switch(grid, count, level + 1))
        return true;

      count -= (i - level);
      Swap(grid, level, i);
      //Print(grid);
    }
  }
  return false;
}

int minSwaps(vector<vector<int>> &grid)
{
  if (grid.size() == 0 || grid[0].size() == 0 || Check(grid))
    return 0;
  int count = 0;

  if (!Switch(grid, count, 0))
    return -1;

  return count;
}
