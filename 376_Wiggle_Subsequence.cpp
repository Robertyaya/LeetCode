#include <bits/stdc++.h>
using namespace std;
/**
 * Time: O(N), Space: O(1)
 * 解題流程: 分成兩種起頭, 先往上找以及先往下找
 * 當遇到轉折地方則代表此時前後差值變號了, 因此長度++, 並且原本往上找的要變成往下找
 * 最後兩種情況都找完後, return max且最後要加1
 */
int wiggleMaxLength(vector<int> &nums)
{
  if (nums.empty())
    return 0;

  // Up first
  int longest = 0;
  bool up = true;
  for (int i = 1; i < nums.size(); i++)
  {
    if (nums[i] - nums[i - 1] < 0 && up)
    {
      longest++;
      up = false;
    }
    if (nums[i] - nums[i - 1] > 0 && !up)
    {
      longest++;
      up = true;
    }
  }

  // Down first
  int longest_ = 0;
  bool down = true;
  for (int i = 1; i < nums.size(); i++)
  {
    if (nums[i] - nums[i - 1] > 0 && down)
    {
      longest_++;
      down = false;
    }
    if (nums[i] - nums[i - 1] < 0 && !down)
    {
      longest_++;
      down = true;
    }
  }
  return max(longest, longest_);
}
