#include <bits/stdc++.h>
using namespace std;

/**
 * Time: O(N^3), Space: O(1)
 * 解題流程: 完全和3Sum problem 相同
 * 先sorting 目標: 把問題轉化為two sum input is sorted
 * 固定兩個值後set "left pointer" and "right pointer" 轉換為two sum
 * 迴圈中先檢查當前面(target-前面較小兩個數字和)因為後面兩個數字一定較大, 因此當two_sum_target比較小兩個數字和還小, 則直接continue, 因為已經sorting過所以後面相加一定較大
 * 當left pointer + right pointer > two_sum 則update left pointer, 反之則update right pointer
 * 關鍵在於找到4 sum = target, need to consider duplicate and remove it
 * 先update 第四個數字(nums[r]), 持續update直到和現在數字不相同
 * 再update 第三個數字(nums[l]), 持續update直到和現在數字不相同
 * 再update第二個數字外圍固定的數字(nums[j]) 同樣概念 要找到不同的數字
 * 最後update第一個外圍固定的數字(nums[i])
 */
vector<vector<int>> fourSum(vector<int> &nums, int target)
{
  if (nums.size() < 4)
    return {};

  vector<vector<int>> answer;

  // Soring O(NlogN)
  sort(nums.begin(), nums.end());
  for (int i = 0; i < nums.size() - 1; i++)
  {
    for (int j = i + 1; j < nums.size(); j++)
    {
      int two_sum_target = target - (nums[i] + nums[j]);
      if (two_sum_target < (nums[i] + nums[j]))
        continue;

      int l = j + 1;
      int r = nums.size() - 1;
      while (r > l)
      {
        if (nums[l] + nums[r] > two_sum_target)
          r--;
        else if (nums[l] + nums[r] < two_sum_target)
          l++;
        else // when (nums[l] + nums[r] == two_sum_target)
        {
          vector<int> temp{nums[i], nums[j], nums[l], nums[r]};
          answer.push_back(temp);

          // Remove duplicates
          while (r > l && nums[l] == temp[2])
            l++;
          while (r > l && nums[r] == temp[3])
            r--;
        }
      }
      while (j + 1 < nums.size() && nums[j] == nums[j + 1])
        j++;
    }
    while (i + 1 < nums.size() && nums[i] == nums[i + 1])
      i++;
  }
  return answer;
}
int main()
{
  vector<int> vec{1, 0, -1, 0, -2, 2};
  vector<vector<int>> answer = fourSum(vec, 0);
  for (int i = 0; i < answer.size(); i++)
  {
    for (int j = 0; j < 4; j++)
    {
      std::cout << answer[i][j] << " ";
    }
    std::cout << std::endl;
  }
}
