#include <bits/stdc++.h>
using namespace std;
double FindKth(vector<int> &nums1, vector<int> &nums2, k)
{
  int index1 = min(nums1.size(), k / 2);
  int index2 = min(nums2.size(), k / 2);
}
double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
{
  int m = nums1.size();
  int n = nums2.size();

  // 奇數
  if ((m + n) % 2 == 1)
    return FindKth(nums1, nums2, (n + m + 1) / 2);
  else // 偶數
    return FindKth((nums1, nums2, (n + m + 1) / 2) + FindKth(nums1, nums2, (n + m + 2) / 2)) / 2;
}
/**
 * Time: O(M+N), Space: O(M+N)
 * 解題流程: 將兩個merge起來後再找出mid index return
 */
double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
{
  vector<int> merge_vec;
  int total_size = nums1.size() + nums2.size();
  merge_vec.resize(total_size);
  int i = 0, j = 0, k = 0;

  // O(M+N)
  while (k < total_size)
  {
    // 前面要多加一個判斷式, 代表的是nums2到底之後， 直接insert nums1就好, 如果沒加的話會out_of_range, 因為後面有判斷nums1[i]<=nums2[j]
    if (j == nums2.size() || (i < nums1.size() && nums1[i] <= nums2[j]))
    {
      merge_vec[k] = nums1[i];
      i++;
    }
    else if (i == nums1.size() || (j < nums2.size() && nums2[j] < nums1[i]))
    {
      merge_vec[k] = nums2[j];
      j++;
    }
    k++;
  }

  // 判斷偶數或奇數
  int mid_index;
  if (total_size % 2 == 1) // 奇數, 直接return正中間那個
  {
    mid_index = (total_size - 1) / 2;
    return merge_vec[mid_index];
  }
  mid_index = total_size / 2;
  float output = float(merge_vec[mid_index] + merge_vec[mid_index - 1]) / 2;
  return output;
}
