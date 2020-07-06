#include <bits/stdc++.h>
using namespace std;
/**
 * Iterative version
 * We assume the while loop executes k times, and d denotes to the counts of digits of n
 * Time: O(kd), Space: O(k) (maintain the unordered_set)
 * 解題流程: 要找出happy number, 每個位數取平方相加判斷是否等於1
 * 持續while loop下去只有兩種可能, 無限迴圈or等於1
 * 如果等於1則跳出迴圈return true
 * 在過程中將sum加入set中, 在迴圈中如果遇到相同的數字, 代表此時已經進入無窮迴圈, 則代表n不是happy number
 */
bool isHappy(int n)
{
  unordered_set<int> set;
  while (n != 1)
  {
    int sum = 0;
    while (n != 0)
    {
      sum += pow(n % 10, 2);
      n /= 10;
    }

    if (set.count(sum))
      return false;
    else
      set.insert(sum);
    n = sum;
  }
  return true;
}
/**
 * Recursive version
 */
bool isHappyRecursive(int n, unordered_set<int> &set)
{
  if (n == 1)
    return true;

  // 計算各位數相加
  int sum = 0;
  while (n >= 0)
  {
    sum += pow(n % 10, 2);
    n = n / 10;
  }

  if (sum == 1)
    return true;

  // Already in the set
  if (set.count(sum))
    return false;
  else
    set.insert(sum);

  if (isHappyRecursive(sum, set))
    return true;
  else
    return false;
}
bool isHappy(int n)
{
  if (n == 0)
    return false;
  unordered_set<int> set;
  return isHappyRecursive(n, set);
}
