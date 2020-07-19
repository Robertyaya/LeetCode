#include <bits/stdc++.h>
using namespace std;
/**
 * Time: O(N), Sapce: O(N)
 * 解題流程: 利用recursive, 每次update max_node and min_node, 分成left-subtree and right-subtree
 * Max_node == nullptr or min_node == nullptr可想成無窮大和無窮小
 * 
 */
bool isValidBST(TreeNode *node, TreeNode *max_node, TreeNode *min_node)
{
  // Base case
  if (node == nullptr)
    return true;

  // Max node and min node要存在且current >=max node or current<=min node則代表not a valid tree
  if ((max_node != nullptr && node->val >= max_node->val) ||
      (min_node != nullptr && node->val <= min_node->val))
    return false;

  // left child tree 和 right child tree要同時滿足才代表is valid tree
  return isValidBST(node->left, node, min_node) && isValidBST(node->right, max_node, node);
}
bool isValidBST(TreeNode *root)
{
  return isValidBST(root, nullptr, nullptr);
}
/**
 * Time: O(N), Space: O(N)
 * 解題流程: 利用Inorder traverse來遍歷all tree, 因為inorder tranverse所有的tree node會從小到大排列
 * 因此利用此特性, 如果current tree node比previous還小那就代表this is not the BST return false
 * 在這邊利用prev指向inorder tranverse的previous node, 用來和current tree node做比較
 * 
 */
bool isValidBST_DFS(TreeNode *node, TreeNode *&prev)
{
  // Base case
  if (node == nullptr)
    return true;

  if (!isValidBST_DFS(node->left, node, prev))
    return false;

  // Previous node initialize
  if (prev == nullptr)
    prev = node;
  else
  {
    // Not a valid BST
    if (prev->val >= node->val)
      return false;

    // Update prev tree node
    prev = node;
  }

  if (!isValidBST_DFS(node->right, node, prv))
    return false;

  return true;
}
bool isValidBST(TreeNode *root)
{
  // Prev point to the previous tree node during inorder traverse
  TreeNode *prev = nullptr;
  return isValidBST_DFS(root, prev);
}
