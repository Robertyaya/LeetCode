#include <bits/stdc++.h>
using namespace std;
/**
 * Time: O(N), Space: O(1)
 * 解題流程: 為two pointer的題型, left指向start, right指向end
 * 關鍵在怎麼update left_pointer and right_pointer
 * 以及如何計算水量
 * 判斷依據在於如果left_pointer指向的height比較高, 那則update right_pointer
 * 並在過程中去將一開始right_pointer指向的hegiht- update過程中的hegiht就是可儲水的量
 * 並如果過程中遇到比原本right_pointer指向的height還高的話, 則停下來並update原本的right_pointer到此位置並重新判斷left 和right哪個較高再繼續update下去
 * 為何要update hegith矮的那個可以這樣想， 矮的那個是決定儲水量的那個, 不是高的決定
 * 但高的那個可以決定這個範圍內可以儲水
 * ex: [3,2,1] 像這種情況就是沒辦法儲水, [3,2,1,5] 這種情況就是可以儲水, 固定5去update 3的那個
 * 因此每次去update 矮的那個計算出最小一定可以save多少水下來
 */
int trap(vector<int> &height)
{
  int left = 0;
  int right = height.size() - 1;
  int sum = 0;
  while (left <= right)
  {
    int min_height = min(height[left], height[right]);
    // Left pointer is smaller
    if (min_height == height[left])
    {
      int move_pointer = left;
      while (height[move_pointer] <= height[left])
      {
        sum += (height[left] - height[move_pointer]);
        move_pointer++;

        if (move_pointer >= right)
          return sum;
      }
      // when height[move_pointer] > hegith[left], update the left pointer to here
      left = move_pointer;
    }
    // Right pointer is smaller
    else
    {
      int move_pointer = right;
      while (height[move_pointer] <= height[right])
      {
        sum += (height[right] - height[move_pointer]);
        move_pointer--;

        if (move_pointer <= left)
          return sum;
      }
      right = move_pointer;
    }
  }

  return sum;
}
