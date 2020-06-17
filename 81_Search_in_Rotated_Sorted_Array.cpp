#include <bits/stdc++.h>
using namespace std;
/**
 * Time: O(logN), worst case: O(N), Space: O(1)
 * 解題流程: 
 * 1. 每次迭代過程都去檢查mid是否等於target
 * 2. 此題關鍵在於利用mid和right的比大小來判斷哪半邊sorting好
 * 當num[mid] > num[right], 代表左邊sorting好, 右邊則是rotate過去的 反之則是右邊sorting好, 左邊rotate過去的, 此處可代數組來證明此特性
 * 3. 接著判斷target是否有在sorting好的區間內
 * 4. 最後要多一個case是如果mid == right, 則持續update right value直到到達不同的數值
 */
bool search(vector<int> &nums, int target)
{
  if (nums.empty())
    return false;

  int left = 0;
  int right = nums.size() - 1;
  while (right >= left)
  {
    int mid = (left + right) / 2;
    if (nums[mid] == target)
      return true;

    // Right half is sorted
    if (nums[mid] < nums[right])
    {
      if (nums[mid] < target && target <= nums[right])
        left = mid + 1;
      else
        right = mid - 1;
    }
    else if (nums[mid] > nums[right]) // left half is sorted
    {
      if (nums[mid] > target && target >= nums[left])
        right = mid - 1;
      else
        left = mid + 1;
    }
    else // nums[mid] == nums[right] != target
    {
      right--;
    }
  }
  return false;
}
int main()
{
  vector<int> vec{3, 1};
  cout << search(vec, 1) << endl;
}
