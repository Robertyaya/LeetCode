#include <bits/stdc++.h>
using namespace std;
/**
 * Time: O(N), Space: O(1)
 * 解題流程: 此題用Greedy Algorithm. 
 * max_reach為最遠能跳到的位置, 迭代過程中持續update max_reach找出能跳最遠的那個
 * 因為遠的地方到得了, 近的一定也可以到, 利用這概念目標為找出最遠的那個
 * end: 代表的是當下最遠能夠到達距離的邊界
 * 當到了邊界代表此刻this step能夠到達最遠的距離已經到了, 因此step++, 並且更新end為下一步能夠到達的最遠距離
 * ex:[2,3,1,1,4]
 * First step: end=2
 * 當到達index2的位置時, 代表已經結束First step能夠到達的距離
 * 在這過程中會去update max_reach的數值
 * max_reach的數值會在index=1 (數值為3)的位置update成最大值
 * 因此代表second foot step是在index=1的位置開始走
 */
int jump(vector<int> &nums)
{
  // Boundary case
  if (nums.size() == 1)
    return 0;

  int max_reach = 0;
  int steps = 0;
  int end = 0;
  for (int i = 0; i < nums.size() - 1; i++)
  {
    max_reach = max(max_reach, nums[i] + i);

    // 當i==end, 代表現在已經走到目前步數最遠的距離, 因此要重新update end並要重新update下一步
    if (i == end)
    {
      end = max_reach;
      steps++;
    }
  }
  return steps;
}
