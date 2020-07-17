#include <bits/stdc++.h>
using namespace std;
/**
 * Time: O(logN), Space: O(1), 此題有個關鍵, 其every value is unique!!
 * 解題流程: input為rotated過的"sorted array", 由於為sorted array一定可以用binary search
 * 1. 先找出rotated point, 也就是minimum point
 * 2. 利用已經sorted過的性質, 如果right value < mid point, 代表rotated point 一定在右邊, 反之則代表右邊為排序好, rotated point在左邊
 * 3. 當找出rotated point之後, 就可以利用一般的binary search方式來做, 差別只在於可以當成有一個bias為rotated point
 * 4. ex: 4,5,6,7,0,1,2 可以想成為一環狀, 4,5,6,7,0,1,2,4,5,6,7. 
 * 5. 初始化左邊pointer為0+rotated_point->指向0, 右邊pointer為 (nums.size + rotated_point)％nums.size, 即可指向array裡的7, 而nums.size() + rotated_point代表指向最末端的7. %n則是代表環狀的概念
 * 6. mid代表是rotated回來的index, real_mid則代表在array裡面真實的index
 * 7. 因此這題找出rotated point後其實就是一般的binary search, 在於取array數值時要將index%nums.size轉換成array的index來做
 * 6. 記得while迴圈要考慮當left=right的情況, 因此要加等號
 */
int search(vector<int> &nums, int target) // More fast
{
  int left = 0;
  int right = nums.size() - 1;

  // Find the rotatied point (minimum point) first
  // O(logN)
  while (right > left)
  {
    int mid = (left + right) / 2;
    if (nums[mid] > nums[right])
      left = mid + 1;
    else // nums[mid] <= nums[right]
      right = mid;
  }

  int rotated_index = right;
  // After we find the rotated point, we can apply the real Binary search
  left = 0 + rotated_index;
  right = (nums.size() - 1) + rotated_index;
  // O(logN)
  while (right >= left)
  {
    int mid = (left + right) / 2;
    int real_mid = mid % nums.size();
    if (nums[real_mid] == target)
      return real_mid;
    else if (nums[real_mid] > target)
      right = mid - 1;
    else
      left = mid + 1;
  }
  return -1;
}

// Same as problem 81
int search(vector<int> &nums, int target)
{
  int left = 0;
  int right = nums.size() - 1;
  while (right >= left)
  {
    int mid = (left + right) / 2;
    if (nums[mid] == target)
      return mid;
    if (nums[mid] > nums[right]) // half of left is sorted
    {
      if (nums[mid] > target && nums[left] <= target)
        right = mid - 1;
      else
        left = mid + 1;
    }
    else // nums[mid] < nums[right] // half of right is sorted
    {
      if (nums[mid] < target && nums[right] >= target)
        left = mid + 1;
      else
        right = mid - 1;
    }
  }
  return -1;
}
