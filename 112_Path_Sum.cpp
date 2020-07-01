#include <bits/stdc++.h>
using namespace std;
/**
 * Time: O(N), Space: O(H)
 * 解題流程: Recursive下去
 * 關鍵在於要剛好sum==0且要剛好arrive leaf才可以叫做一條valid path
 * 因此不是過程中有sum==0就可以
 */
bool DFS(TreeNode *node, int sum)
{
  if (node == nullptr)
    return false;

  // 扣掉current node->val
  sum -= node->val;

  // 為了要判斷是否sum==0且同時有到達leaf, 如果都滿足代表有一條path
  if (node->left == nullptr && node->right == nullptr && sum == 0)
    return true;

  if (DFS(node->left, sum))
    return true;
  if (DFS(node->right, sum))
    return true;

  return false;
}
bool hasPathSum(TreeNode *root, int sum)
{
  if (root == nullptr)
    return false;

  return DFS(root, sum);
}
