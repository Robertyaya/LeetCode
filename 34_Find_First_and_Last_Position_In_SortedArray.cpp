#include <bits/stdc++.h>
using namespace std;

/**
 * Time: O(logN), Space: O(1)
 * 解題流程: 分成兩個Binary search去做, 分別找left bound and right bound 
 * 特別要注意一些boundary case, 以及index會越界問題
 * 在找bound時, 和一般的binary search不同地方在於當找到相同數值時, 不是直接return, 而是將right point or left point指向此處, 從此處繼續找
 * 在找left bound時, 在交界處由於計算mid會無條件省略小數, 因此mid會進位到left bound左邊那一位則會進入判斷式if(nums[mid] < nums[right]), left會被更新因此不會有問題, 然而在找right bound時, 由於四捨五入mid會剛好在right bound的數值上, 則無法跳出回圈, 因此我們設一個mid++在right bound裡面處理此問題 
 */

// O(logN)
vector<int> searchRange(vector<int> &nums, int target)
{
  // Boundary case
  if (nums.empty())
    return {-1, -1};

  vector<int> answer;
  int left = 0;
  int right = nums.size() - 1;

  // Only one value, boundary case
  if (left == right)
  {
    if (nums[left] == target)
      return {0, 0};
    else
      return {-1, -1};
  }

  // Binary search (find left bound) O(logN)
  while (right > left)
  {
    int mid = (left + right) / 2;
    if (nums.at(mid) == target)
      right = mid;
    else if (nums.at(mid) > target)
      right = mid - 1;
    else // nums[mid] < target
      left = mid + 1;
  }
  // Filter when right < 0
  if (right < 0)
    right = 0;
  if (nums.at(right) != target)
    answer.push_back(-1);
  else
    answer.push_back(right);

  // Find right bound, same as find left bound, we don't need to update left index here
  right = nums.size() - 1;
  while (right > left)
  {
    int mid = (left + right) / 2;
    if (mid != nums.size() - 1)
      mid++;

    if (nums.at(mid) == target)
      left = mid;
    else if (nums.at(mid) > target)
      right = mid - 1;
    else // nums[mid] < target
      left = mid + 1;
  }
  if (right < 0)
    right = 0;
  if (nums.at(right) != target)
    answer.push_back(-1);
  else
    answer.push_back(right);
  return answer;
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
