#include <bits/stdc++.h>
using namespace std;
/**
 * Binary search version
 * Time: O(NlogN), Space: O(N)
 * 解題流程: 此題目要找出O(NlogN)的algorithm, 因此想到利用binary search, 但不能排列此數組, 因為排列後就不知道周圍的是哪些數字, 因此binary search在此的運用是"找長度"
 * 先找長度為一半vector的數組, traverse all vector根據目標length去找出此長度是否有滿足target value的
 * 如果找得到, 代表我們可以繼續找更短長度的, 因此update longest->length-1
 * 如果找不到, 則代表此長度以下的都不可能滿足target value, 因此update shortest->length+1
 */
bool FindLength(int s, vector<int> &nums, int length)
{
  // 根據input的length找出所有此長度大於等於target value, 有的話代表此長度ok, 沒有則return false
  int sum = 0;
  int l = 0;
  int j = 0;

  // Sliding window O(N)
  for (int i = 0; i < nums.size(); i++)
  {
    sum += nums[i]; // 加上最前面的
    l++;
    if (l == length)
    {
      // 代表此長度有滿足條件的
      if (sum >= s)
        return true;
      sum -= nums[j]; // 扣掉前面的
      j++;            // update j
      l--;
    }
  }
  return false;
}
int minSubArrayLen(int s, vector<int> &nums)
{
  if (nums.empty())
    return 0;

  int shortest = 1;          // 最短可能的長度
  int longest = nums.size(); // 最長可能的長度
  int length;
  int min_length = INT_MAX;
  while (shortest <= longest)
  {
    length = (shortest + longest) / 2;

    // 此長度有的話, 則去找更短的
    if (FindLength(s, nums, length))
    {
      longest = length - 1;
      min_length = length;
    } // 此長度沒有, 因此去找更長的
    else
      shortest = length + 1;
  }
  return min_length == INT_MAX ? 0 : min_length;
}
/**
 * Two pointer version
 * Time: O(N), Space: O(1)
 * 解題流程: 利用兩個pointer, i and j 
 * i持續update, 當sum超過target時, 則update j直到sum小於target再重新開始updatei
 * 維持一個"Sliding window"
 * 利用這方法和下面brute force的差別在於, brute每次update i之後j需要全部重新計算, 然後那些數值早就已經計算過, 我們只需要移動j時, 將原本數值扣掉j原本所在數值並確認此時是否大於target
 */
int minSubArrayLen(int s, vector<int> &nums)
{
  if (nums.empty())
    return 0;
  int min_size = INT_MAX;
  int i = 0, j = 0;
  int sum = 0;
  int size = 0;
  while (i < nums.size())
  {
    sum += nums[i];
    size++;
    while (sum >= s)
    {
      min_size = min(size, min_size);
      sum -= nums[j];
      size--;
      j++;
    }
    i++;
  }
  return min_size == INT_MAX ? 0 : min_size;
}
/**
 * Brute force version
 * Time: O(N^2), Space: O(1)
 */
int minSubArrayLen(int s, vector<int> &nums)
{
  if (nums.empty())
    return 0;
  int min_size = INT_MAX;
  int target = s;

  // O(N^2)
  for (int i = 0; i < nums.size(); i++)
  {
    int j = i;
    int size = 0;
    while (target > 0 && j < nums.size())
    {
      target -= nums[j];
      size++;
      j++;
    }
    if (size < min_size && target <= 0)
      min_size = size;
    target = s;
  }

  if (min_size == INT_MAX)
    return 0;
  else
    return min_size;
}
