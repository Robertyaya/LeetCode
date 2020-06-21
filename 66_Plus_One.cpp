#include <bits/stdc++.h>
using namespace std;
/**
 * Time: O(N), Space: O(1)
 * 解題流程: Tranverse all digits
 * 關鍵在於當下那個位數是否等於9
 * 1. 當下位數等於9: 代表要進位, 當下位數->0, 繼續tranverse到下一個位數
 * 2. 當下位數不等於9: 代表此位數加1就直接return
 * 最後還有一種可能是進位到超過原本vector的位數
 * 因此最前面會多一個位數, 則直接修改index 0的數值為1, 並且push_back一個0
 * 最後面一定是0因為如果不是進位, 則前面就會直接return掉了
 */
vector<int> plusOne(vector<int> &digits)
{
  for (int i = digits.size() - 1; i >= 0; i++)
  {
    if (digits[i] != 9)
    {
      digits[i]++;
      return digits;
    }
    else //digits[i]==9
    {
      digits[i] = 0;
    }
  }
  digits[0] = 1;
  digits.push_back(0);
}

int main()
{
}
