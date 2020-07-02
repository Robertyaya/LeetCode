#include <bits/stdc++.h>
using namespace std;
/**
 * Time: O(N), Space: O(N)
 * 解題流程: 自行定義string格式放到set中, 程式碼簡單, 但因為string比較長, 因此花費時間較多
 * char 如果要和string相加, 只能利用operator+=.
 * 直接相加不行, 或是利用stringstream, 將char pass to stringstream, then pass stringstream to string 
 */
bool isValidSudoku(vector<vector<char>> &board)
{
  unordered_set<string> set;
  for (int i = 0; i < board.size(); i++)
  {
    for (int j = 0; j < board[i].size(); j++)
    {
      // char to string
      char value = board[i][j];
      std::stringstream ss;
      ss << value;
      string value_s;
      ss >> s;
      if (value != '.')
      {
        // Row
        string row_key = "";
        row_key += (value_s + "in row" + to_string(i));
        if (set.count(row_key))
          return false;
        else
          set.insert(row_key);

        // Col
        string col_key = "";
        col_key += (value_s + "in col" + to_string(i));
        if (set.count(col_key))
          return false;
        else
          set.insert(col_key);

        // Block
        string block_key = "";
        block_key += (value_s + "in block" + to_string(i / 3) + "-" + to_string(j / 3));
        if (set.count(block_key))
          return false;
        else
          set.insert(block_key);
      }
    }
  }
  return true;
}

/**
 * Time: O(3N)(N is the size of board), Space: O(1)
 * 解題流程: 直接暴力解, 分成三種各別判斷是否有違反數獨規則
 */
bool isValidSudoku(vector<vector<char>> &board)
{
  unordered_set<int> map;
  // 檢查row
  for (int i = 0; i < board.size(); i++)
  {
    for (int j = 0; j < board[i].size(); j++)
    {
      if (board[i][j] == '.')
        continue;

      // 已經在map裡面
      if (map.count(board[i][j]))
        return false;
      map.insert(board[i][j]);
    }
    map.clear();
  }

  // 檢查col
  for (int i = 0; i < board.size(); i++)
  {
    for (int j = 0; j < board[i].size(); j++)
    {
      if (board[j][i] == '.')
        continue;

      // 已經在map裡面
      if (map.count(board[j][i]))
        return false;
      map.insert(board[j][i]);
    }
    map.clear();
  }

  // 檢查block
  for (int i = 0; i < 9; i += 3)
  {
    for (int j = 0; j < 9; j += 3)
    {
      // Traverse data in block (3x3)
      for (int k = i; k < i + 3; k++)
      {
        for (int w = j; w < j + 3; w++)
        {
          if (board[k][w] == '.')
            continue;

          if (map.count(board[k][w]))
            return false;
          map.insert(board[k][w]);
        }
      }
      map.clear();
    }
  }
  return true;
}

int main()
{
  int a = 1;
  char str = a + '0';
  cout << str << endl;
}
