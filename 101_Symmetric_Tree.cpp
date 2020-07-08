#include <bits/stdc++.h>
using namespace std;
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
