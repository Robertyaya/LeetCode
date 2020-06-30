#include <bits/stdc++.h>
using namespace std;
/** 
 * DP version
 * Time: O(N^2), Space: O(N)
 * 解題流程: 概念和Recursive相同, 差別只在於recursive是從大到小後再一步一步return回去, DP則是直接從小問題做到大問題
 * 但是DP不用像recursive需要呼叫stack所以空間上較省
 * 假設今天只有一個tree node也就是dp[1]的話就是只有一種valid BST, dp[0]也設為1這樣才可以update
 * dp[2]問題就是2個tree node時, 有幾種valid BST
 * 概念跟recursive 一樣, 輪流當root
 * [1,2]
 * ->root:[1], left:[], right:[2] 此時為dp[0]*dp[1]種可能
 * ->root:[2], left:[1], right:[] 此時為dp[1]*dp[0]種可能
 * 因此所有種可能就是全部相加, 因此dp[2] = dp[0]*dp[1]+dp[1]*dp[0]
 * 再舉一個例子
 * [1,2,3]
 * ->root:[1], left:[], right:[2,3] 此時為dp[]*dp[2]
 * ->root:[2], left:[1], right:[3] 此時為dp[1]*dp[1]
 * ->root:[3], left:[1,2], right:[] 此時為dp[2]*dp[]
 * 因此dp[3] = dp[]*dp[2]+dp[1]*dp[1]+dp[2]*dp[]
 * 利用此規律即可推得dp[n]為多少 
 * 
 */
int numTrees(int n)
{
  vector<int> dp;
  dp.resize(n + 1);
  dp[0] = 1;
  dp[1] = 1;

  for (int i = 2; i <= n; i++)
  {
    for (int j = 0; j <= i - 1; j++)
    {
      dp[i] = dp[j] * dp[(i - 1) - j];
    }
  }

  return dp[n];
}

/**
 * Recursive version
 * 解題流程: 如何求得有多少個valid的BST
 * [1,2,3,4,5]->輪流當root
 * ex: 以3為root的話
 * Left tree: [1,2], Right tree: [4,5]
 * 而[1,2]又可以輪流當root組合成兩種bst, [4,5]也可以輪流當root組合成兩種bst
 * 因此退回到上一層, 如果以3為root的話, 總共有2*2總可能的valid bst, 左邊兩種*右邊兩種
 * 利用此概念, nums代表的就是目前input進來的tree node num
 * 根據tree node的數量, traverse每一個輪流當root
 * 左子樹的數量會是i-1, 右子樹的數量會是num-i再繼續recursive下去, 把大問題持續拆成小問題去解
 * 在過程中將每一種數量所對應到的valid BST 存到hash map裡面, 這樣下次再遇到的時候就可以直接return答案
 */
int FindBST(int nums, unordered_map<int, int> &map)
{
  // Already in the map, directly return the value
  if (map.count(nums))
    return map[nums];

  // Base case
  if (nums == 0)
    return 1;

  int value = 0;
  for (int i = 1; i <= nums; i++)
  {
    int leftTreeNum = FindBST(i - 1);
    int rightTreeNum = FindBST(nums - i);
    value += (leftTreeNum * rightTreeNum);
  }

  // Insert into map
  map[nums] = value;
  return value;
}

int numTrees(int n)
{
  if (n == 0)
    return 0;

  unordered_map<int, int> map;
  return FindBST(n, map);
}

/**
 * 解題流程: 做法和邏輯同recursive version, 但是沒有memorization因此會time limit exceeded
 * 但邏輯比較好理解
 * start代表數列起始點, end代表數列終點
 * 一樣概念是輪流當root
 * [1,2,3,4,5] 假設3當root
 * 那左邊就會從start=1, end=2 [1,2], 右邊就會從start=4, end=5 [4,5]繼續recursive
 * 直到碰到base case, 也就是只有一個tree node的情況, ex:[1], 此時return 1
 */

int FindBST(int start, int end)
{
  // Base case
  if (start >= end)
    return 1;

  int value = 0;
  for (int i = start; i <= end; i++)
  {
    int leftTreeNum = FindBST(start, i - 1);
    int rightTreeNum = FindBST(i + 1, end);
    value += (leftTreeNum * rightTreeNum);
  }
  return value;
}
int numTrees(int n)
{
  if (n == 0)
    return 0;

  return FindBST(1, n);
}
