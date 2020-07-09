#include <bits/stdc++.h>
using namespace std;
/**
 * Recursive version
 * Time: O(N), Space: O(H) (Tree height)
 * 解題流程: 判斷symmetric的方式在於如果去比較兩個node數值相等
 * current_left_node的左邊child 要和 current_right_node的右邊child相比
 * ex: 數字代表index
 *       1
 *    1     2    level2
 *  1   2 3   4  level3
 * 1 2 3 45 6 7 8  level4
 * 
 * 在level3中, 1 and 4 compare, 2 and 3 compare
 * 在level4中, [1,8], [2,7], [3,6], [4,5] compare   
 */
bool isSymmetricRecursive(TreeNode *left, TreeNode *right)
{
  // 兩者皆為nullptr
  if (!left && !right)
    return true;

  // 兩者node不相等, 可能為各一個為nullptr或是value不相等, 這樣都是not symmetric
  if (!left && right || left && !right || left->val != right->val)
    return false;

  // left左邊的node要跟right右邊的node相比, 而left右邊的node要跟right左邊的node相比
  return isSymmetricRecursive(left->left, right->right) && isSymmetricRecursive(left->right, right->left);
}
bool isSymmetric(TreeNode *root)
{
  if (!root)
    return true;
  return isSymmetricRecursive(root->left, root->right);
}
/**
 * Iterative version
 * Time: O(N), Space: O(N)
 * 解題流程: 分成兩個sub-tree去做level-order traversal
 * 關鍵在push進去queue時, left_subtree要先push左邊的node, right_subtree要先push右邊的node
 * 這樣在比較數值的時候才會是對稱的判斷
 */
bool isSymmetric(TreeNode *root)
{
  if (root == nullptr)
    return true;

  queue<TreeNode *> que_left;
  queue<TreeNode *> que_right;
  que_left.push(root->left);
  que_right.push(root->right);
  while (!que_left.empty() && !que_right.empty())
  {
    TreeNode *left_node = que_left.front();
    TreeNode *right_node = que_right.front();
    que_left.pop();
    que_right.pop();

    // 先檢查所有可能為nullptr的情況
    if (left_node == nullptr && right_node == nullptr)
      continue;
    if (left_node == nullptr && right_node != nullptr)
      return false;
    if (left_node != nullptr && right_node == nullptr)
      return false;

    // 再比較數值, 不相等則return false
    if (left_node->val != right_node->val)
      return false;

    que_left.push(left_node->left);
    que_left.push(left_node->right);
    que_right.push(right_node->right);
    que_right.push(right_node->left);
  }
  return true;
}
