#include <bits/stdc++.h>
using namespace std;
/**
 * Time: O(N), Space: O(N)
 * 解題流程: 利用遞迴去search, return true 代表可以到value 0, 反之則不行
 * 當超過左右兩邊的size時, 則代表此條路不行直接return false
 * 關鍵在於, 經過的數字不會重複, 因為重複代表其實是同一條路
 * ex: [2,0,2,2,1] start: index:2
 * index2->index0->index2 此時就可直接return false, 因為又走回同一條路了
 * 因此我們需要一個boolean vector去紀錄目前哪些數字已經走過
 * bool vector=true代表此數字有走過了, 反之則沒有
 *
 */
bool canReach_recursive(vector<int> &arr, vector<bool> &bool_vec, int start)
{
  // Out of array range and arrive the same value, return false
  if (start < 0 || start > arr.size() - 1 || bool_vec[start])
    return false;

  if (arr[start] == 0)
    return true;

  bool_vec[start] = true;
  return canReach_recursive(arr, bool_vec, start + arr[start]) || canReach_recursive(arr, bool_vec, start - arr[start]);
}

bool canReach(vector<int> &arr, int start)
{
  // To record whether visited yet
  vector<bool> bool_vec;
  bool_vec.resize(arr.size());

  return canReach_recursive(arr, bool_vec, start);
}
