#include <bits/stdc++.h>
using namespace std;

/**
 * Time: O(N^2), Space: O(1)
 * 解題流程: 此題要找總和最接近target value, 因此除了找相等於target的three sum之外, 另外需要在每個iteration中update the closest value
 * 1. 先sorting O(NlogN)
 * 2. 先固定一個數值轉換成two sum input is sorted的problem
 * 3. 每個iteration中, 計算current sum和目前的closest value中, 哪一個較接近target, 若current sum較接近target, 則update此時的closest value為current sum
 * 4. 除了update closest value之外, 若相等於target則直接return此時的current sum
 * 5. 如果大於target value則update right pointer, 小於target value則update left pointer
 * 6. 最後再return closest value, 代表過程中沒有找到和target value完全相同的current sum
 */
int threeSumClosest(vector<int> &nums, int target)
{
  if (nums.size() < 3)
    return 0;

  // Initialize the closest value
  int closest = nums[0] + nums[1] + nums[2];

  // Sorting first O(NlogN)
  sort(nums.begin(), nums.end());

  // O(N^2)
  for (int i = 0; i < nums.size(); i++)
  {
    int two_sum_target = target - nums[i];
    int l = i + 1;
    int r = nums.size() - 1;
    while (r > l)
    {
      int current_sum = nums[i] + nums[l] + nums[r];

      // Update closest value
      if (abs(current_sum - target) < abs(closest - target))
        closest = current_sum;

      if (nums[r] + nums[l] == two_sum_target)
        return target;
      else if (nums[r] + nums[l] > two_sum_target)
        r--;
      else
        l++;
    }
  }
  return closest;
}
