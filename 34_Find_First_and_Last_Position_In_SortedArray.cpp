#include <bits/stdc++.h>
using namespace std;

/**
 * Time: O(logN), Space: O(1)
 * 解題流程: 分成兩個Binary search去做, 分別找left bound and right bound 
 */

// O(logN)
vector<int> searchRange(vector<int> &nums, int target)
{
  vector<int> res(2, -1);
  int left = 0;
  int right = nums.size();

  // Find lower bound
  while (right > left)
  {
    int mid = left + (right - left) / 2;
    if (nums[mid] < target)
      left = mid + 1;
    else
      right = mid;
  }
  if (right == nums.size() || nums[right] != target)
    return {-1, -1};

  res[0] = right;

  // Find upper bound
  left = 0;
  right = nums.size();
  while (right > left)
  {
    int mid = left + (right - left) / 2;
    if (nums[mid] <= target)
      left = mid + 1;
    else
      right = mid;
  }
  res[1] = right - 1;
  return res;
}

//O(NlogN)(in worst case)
vector<int> searchRange(vector<int> &nums, int target)
{
  int left_bound, right_bound;
  // Binary search
  int left = 0;
  int right = nums.size() - 1;
  while (right >= left)
  {
    int mid = (left + right) / 2;
    if (nums[mid] == target)
    {
      // Find right bound
      right_bound = mid;
      while (right_bound <= nums.size() - 1 && nums[right_bound] == target)
        right_bound++;
      right_bound--;

      // Find left bound
      left_bound = mid;
      while (left_bound >= 0 && nums[left_bound] == target)
        left_bound--;
      left_bound++;

      return {left_bound, right_bound};
    }
    else if (nums[mid] > target)
      right = mid - 1;
    else
      left = mid + 1;
  }
  return {-1, -1};
}
int main()
{
  vector<int> vec{2, 2};
  vector<int> answer = searchRange(vec, 1);
  for (int i = 0; i < answer.size(); i++)
    cout << answer[i] << " ";
  cout << endl;
}
