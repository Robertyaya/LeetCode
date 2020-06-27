#include <bits/stdc++.h>
using namespace std;
/**
 * Time: O(N), Space: O(1)
 * 解題流程: 從後面判斷回來, 計算最後一個word的長度
 * 此題關鍵在於handle boundary case
 * for迴圈的flag目的在於handle當一開始持續都是空白的時候, 此時不能break
 * 因為搞不好下一個會有char出現, ex: "a   " 此時長度為1, 也就是a的長度
 * 當遇到第一個字母後, 後面如果再遇到空白則才能break, 如果還沒遇到字母則繼續tranverse下去
 */
int lengthOfLastWord(string s)
{
  if (s.size() == 0)
    return 0;

  int count = 0;
  bool flag = false;
  for (int i = s.size() - 1; i >= 0; i--)
  {
    if (s[i] != ' ')
    {
      count++;
      flag = true;
    }
    else if (flag)
      break;
  }
  return count;
}
