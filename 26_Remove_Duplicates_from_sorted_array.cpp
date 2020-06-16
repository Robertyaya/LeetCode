#include <bits/stdc++.h>
using namespace std;
/**
 * Time: O(N), Space: O(1)
 * 解題流程: 不用真的去erase掉duplicates value
 * 我們可以只需要去計算重複的數值
 * 直到當current value != previous value時, 將current value根據前面所計算duplicate num move到前面
 */
int removeDuplicates(vector<int> &nums)
{
  // Use "count" to record the total duplicate num
  int count = 0;
  for (int i = 1; i < nums.size(); i++)
  {
    if (nums[i] == nums[i - 1])
      count++;
    else // Move to the unique value to the front of vector base on "count"
      nums[i - count] = nums[i];
  }
  return nums.size() - count;
}
// Use erase is too slow !
int removeDuplicates_Naive(vector<int> &nums)
{
  vector<int>::iterator iter = nums.begin();
  int previous_value;
  while (iter != nums.end())
  {
    // Initialize
    if (iter == nums.begin())
    {
      previous_value = *iter;
      iter++;
    }
    else
    {
      int temp = previous_value;

      // Update previous_value
      previous_value = *iter;
      if (temp == *iter)
      {
        iter = nums.erase(iter); // It will return next iterator
      }
      else
      {
        iter++;
      }
    }
  }
  return nums.size();
}
