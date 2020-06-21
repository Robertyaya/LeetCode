#include <bits/stdc++.h>
using namespace std;
/**
 * Time: O(N), Space: O(1)
 * 解題流程: 此方法關鍵在於, "遠的地方可以到達則近的一定可以到達", 因為nums[i]的數值代表最遠能夠jump的距離
 * 因此我們在此題只要不斷去update最遠能夠到達的位置, 去確認此位置是否有>=nums.size()-1就可以知道到底可不可以到達the last index
 * max_reach代表就是最遠可以到達的index
 * nums[i]+i: 代表在此位置上最遠可以到達的位子, 也就是current position+jump distance
 * 接著去update max_reach, 如果此位置為0, 那max_reach就會和上一時刻的max_reach相同
 * 如果在iterate過程中發現最遠可到達距離已經超過nums size, 那則直接return true
 * 記得在for迴圈中 i不能超過nums.size, 也不能超過max_reach, 因為max_reach就是目前最遠可到達的距離
 */
bool canJump(vector<int> &nums)
{
  int max_reach = 0;
  for (int i = 0; i < nums.size() && i <= max_reach; i++)
  {
    // i: current position, nums[i]: max jump distance,
    // i+nums[i]: max arrive position
    max_reach = max(max_reach, nums[i] + i);
    if (max_reach >= nums.size() - 1)
      return true;
  }
  return false;
}
/**
 * Time: O(N^2), Space: O(1)
 * 解題流程: 此方法利用DP來解, dp[index]=true代表此index位置為可到達位置, 一步一步計算最後回傳dp[nums.size()-1]
 * tranverse 0~nums.size()-1, 每一次迭代都去找前一個可到達位置的地方最確認是否從上一個可到達位置的地方可以到current位置, 如果可以則把dp[current_index] set to true, 相反則false
 *  檢查方式則是去計算current_index - previous_reachable_index大小是否比nums[previous_reachable_index], 比較小則代表可以從上一個位置跳過來, 反之則不行
 */

bool canJump(vector<int> &nums)
{
  // dp[index] = true, represent the index is reachable
  vector<bool> dp;
  // Record the index which is reachable
  vector<int> reachable_index_vec;

  reachable_index_vec.reserve(nums.size());
  dp.resize(nums.size());

  // Initialize
  dp[0] = true;
  reachable_index_vec.push_back(0);

  for (int i = 1; i < nums.size(); i++)
  {
    // Need to back tracking to check whether we can reach the current_index
    for (int reachable_index = reachable_index_vec.size() - 1; reachable_index >= 0; reachable_index--)
    {
      int distance = i - reachable_index;
      if (distance <= nums[reachable_index]) // this index can reach
      {
        dp[i] = true;
        reachable_index_vec.push_back(i);
        break;
      }
    }
  }
  return dp[nums.size() - 1];
}
