#include <bits/stdc++.h>
using namespace std;
/** 
 * N is the size of board
 * Time: O(N), Space: O(N) (Recursive nned to call stack)
 * 解題流程: 在邊界上的O以及跟其連在一起的O不用翻成X, 其他的O要翻成X
 * 因此關鍵在於找出所有和邊界連在一起的O
 * 因此此處先traverse邊界, 當遇到為O的地方則DFS找出所有和其連在一起的O將其設成另外一個符號'$'
 * 做完上步之後, 基本上沒有變成'$'的O就一定是和邊界沒連在一起的, 因此要變成X
 * 最後再Traverse所有數值, 遇到O設成X, 遇到$則設成原來的O
 */
void DFS(vector<vector<char>> &board, int i, int j)
{
  // 超過邊界
  if (i == board.size() || j == board[0].size() || i < 0 || j < 0)
    return;

  // 已經到達過
  if (board[i][j] == '$')
    return;
  if (board[i][j] == 'O')
  {
    board[i][j] = '$';
    DFS(board, i - 1, j);
    DFS(board, i + 1, j);
    DFS(board, i, j - 1);
    DFS(board, i, j + 1);
  }
}
void solve(vector<vector<char>> &board)
{
  if (board.empty() || board[0].empty())
    return;
  int row = board.size();
  int col = board[0].size();
  // 先掃四個邊
  for (int i = 0; i < col; i++)
  {
    // Top
    if (board[0][i] == 'O')
      DFS(board, 0, i);

    // Down
    if (board[row - 1][i] == 'O')
      DFS(board, row - 1, i);
  }
  for (int i = 1; i < row - 1; i++)
  {
    // Left
    if (board[i][0] == 'O')
      DFS(board, i, 0);
    // Right
    if (board[i][col - 1] == 'O')
      DFS(board, i, col - 1);
  }

  for (int i = 0; i < board.size(); i++)
  {
    for (int j = 0; j < board[0].size(); j++)
    {
      if (board[i][j] == '$')
        board[i][j] = 'O';
      if (board[i][j] == 'O')
        board[i][j] = 'X';
    }
  }
}
