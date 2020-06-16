#include <bits/stdc++.h>
/**
 * Time: O(N), Space: O(1)
 * 解題流程: 利用count去紀錄target remove value出現的次數, 不用真的直接去remove掉
 * 當遇到不等於targe remove value時則可以基於count的數值來move the value
 */
int removeElement(vector<int> &nums, int val)
{
  // Record the count of remove value
  int count = 0;
  for (int i = 0; i < nums.size(); i++)
  {
    if (nums[i] == val)
      count++;
    else
      nums[i - count] = nums[i];
  }
  return nums.size() - count;
}
