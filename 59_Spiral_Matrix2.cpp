#include <bits/stdc++.h>
using namespace std;
/**
 * Time: O(N^2), Space: O(N^2)
 * 解題流程: 和problem 48 相同題型
 * 思路為先填完一層再到下一層， 但此題比較簡單不用考慮如果不是方陣的情況
 */
vector<vector<int>> generateMatrix(int n)
{
  // Allocate memory
  vector<vector<int>> matrix;
  matrix.resize(n);
  for (int i = 0; i < n; i++)
    matrix[i].resize(n);

  int start_index = 0;
  int end_index = n - 1;
  int value = 1;
  while (value <= n * n)
  {
    // Top
    for (int j = start_index; j <= end_index; j++)
    {
      matrix[start_index][j] = value;
      value++;
    }
    // Right
    for (int j = start_index; j <= end_index; j++)
    {
      if (j == start_index)
        continue;
      matrix[j][end_index] = value;
      value++;
    }
    // Bottom
    for (int j = start_index; j <= end_index; j++)
    {
      if (j == start_index)
        continue;
      matrix[end_index][end_index - j + start_index] = value;
      value++;
    }
    // Left
    for (int j = start_index; j <= end_index; j++)
    {
      if (j == start_index || j == end_index)
        continue;
      matrix[end_index - i + start_index][start_index] = value;
      value++;
    }
    start_index++;
    end_index--;
  }
  return matrix;
}
