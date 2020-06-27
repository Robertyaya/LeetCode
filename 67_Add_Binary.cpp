#include <bits/stdc++.h>
using namespace std;
/**
 * Time: O(N) (N is the bigger size of string), Space: O(1)
 * 解題流程: 和problem 43相似作法, 只是此題為二進位相加
 * 1. 先將短的string前面補0, 確保兩個string長度相同
 * 2. tranverse string將char轉成int做二進位相加超過1要進位
 * 進位分兩種， =2的current position=0, 進位1, =3的current position=1, 進位1
 * 進位: 1 1 1  
 *      1 1 1 1
 *     +1 0 1 1
 *      --------
 *    1 1 0 1 1
 * 將相加的數值push back到vector裡面
 * 最後再tranverse vector將每個數值轉乘char 連接起來
 *  
 * 
 */
string addBinary(string a, string b)
{
  vector<int> answer;

  // Which is longer, 將較短的前面補0
  if (a.size() > b.size())
  {
    int diff = a.size() - b.size();
    for (int i = 0; i < diff; i++)
      b.insert(0, "0");

    answer.reserve(a.size() + 1);
  }
  else
  {
    int diff = b.size() - a.size();
    for (int i = 0; i < diff; i++)
      a.insert(0, "0");

    answer.reserve(b.size() + 1);
  }

  // 記錄進位
  int step = 0;
  for (int i = a.size() - 1; i >= 0; i--)
  {
    // char to int
    int up = a[i] - '0';
    int down = b[i] - '0';
    int total = up + down + step;

    // 需要進位
    if (total > 1)
    {
      if (total == 2)
        total = 0;
      if (total == 3) // Total = 3
        total = 1;
      step = 1;
    }
    else // 不需要進位
      step = 0;

    answer.push_back(total);
  }
  // 代表最後面還需多進一位
  if (step == 1)
    answer.push_back(1);

  string str_answer = "";
  for (int i = answer.size() - 1; i >= 0; i--)
  {
    str_answer += answer[i] + '0';
  }
  return str_answer;
}
