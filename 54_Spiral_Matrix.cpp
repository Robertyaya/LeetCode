#include <bits/stdc++.h>

using namespace std;
/**
 * Time: O(M*N), Space: O(M*N) (M is width of matrix, N is height of matrix)
 * 解題流程: 此題概念跟Problem48: Roatae_Imag相同, 差別只在於這題需要考慮matrix不是N*N的情況
 * 一樣是分層下去tranverse, 先tranverse第一層又分成top, right, bottom and left
 * 1. 記住會有重複的數字需要continue, ex: right第一個數字其實就是top的最後一個數字, 因此需要skip
 * 2. 因為matrix不是方陣, 因此在進入到最底層時會有問題
 * ex:
 * [1, 2, 3, 4]
 * [5, 6, 7, 8]
 * [9,10,11,12]
 * 可以注意到此matrix當第一層走完時, 進入到第二層只有兩個數字[6,7]
 * 此時的width_index為:1~2, height_index為: 1
 * top push_back 6,7沒問題
 * right continue 7  沒問題
 * 然而到bottom就有問題 bottom continue 7 and push_back 6  因此6會重複塞到
 * 然後此問題在於這種長條的不管是width方向或是height的其實在top and right就會被放入, bottom and left就不用在push_back進去
 * 因此在bottom and left需要多加一個判斷式如果start and end相同, 則不用做bottom or left
 * 因為在上面就已經放到answer vector裡面去了
 */
vector<int> spiralOrder(vector<vector<int>> &matrix)
{
  if (matrix.size() == 0)
    return {};

  // Initialize variable
  int start_index = 0;
  int width_end_index = matrix[0].size() - 1;
  int height_end_index = matrix.size() - 1;
  int offset = 0;

  vector<int> answer;

  while (width_end_index >= start_index && height_end_index >= start_index)
  {
    // Top
    for (int i = start_index; i <= width_end_index; i++)
    {
      answer.push_back(matrix[start_index][i]);
    }

    // Right
    for (int i = start_index; i <= height_end_index; i++)
    {
      if (i == start_index)
        continue;
      answer.push_back(matrix[i][width_end_index]);
    }

    // Bottom, start_index == height_end_index代表為左到右長條, 在top做過
    if (start_index != height_end_index)
    {
      for (int i = start_index; i <= width_end_index; i++)
      {
        if (i == start_index)
          continue;
        answer.push_back(matrix[height_end_index][width_end_index - i + offset]);
      }
    }

    // Left, start_index == width_end_index代表為上到下長條, 在right做過
    if (start_index != width_end_index)
    {
      for (int i = start_index; i <= height_end_index; i++)
      {
        if (i == start_index || i == height_end_index)
          continue;
        answer.push_back(matrix[height_end_index - i + offset][start_index]);
      }
    }

    start_index++;
    height_end_index--;
    width_end_index--;
    offset++;
  }
  return answer;
}

int main()
{
}
