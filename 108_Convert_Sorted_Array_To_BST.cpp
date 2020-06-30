#include <bits/stdc++.h>
using namespace std;
/**
 * Recursive version
 * Time: O(N), Space: O(H)
 * 解題流程: 每次recursive都取中間來當作root, 左右兩端分別為left subtree, right subtree
 * 將大問題持續變成小問題來解決, 直到base case
 */
TreeNode *BuildBST(vector<int> &nums, int start, int end)
{
  // Base case
  if (start > end)
    return nullptr;

  int mid = start + (end - start) / 2;
  TreeNode *root = new TreeNode(nums[mid]);
  root->left = BuildBST(nums, start, mid - 1);
  root->right = BuildBST(nums, mid + 1, end);
  return root;
}
TreeNode *sortedArrayToBST(vector<int> &nums)
{
  return BuildBST(nums, 0, nums.size() - 1);
}
