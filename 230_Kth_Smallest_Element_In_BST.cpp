#include <bits/stdc++.h>
using namespace std;
/**
 * Recursive version
 * Time: O(N), Space: O(H)
 * 解題流程: Recursive不像iterative可以直接return中斷, 因此我們需要一個bool來做這件事
 * 一樣是做recursive 的 inorder traverse, 當k==0時代表已經到達第k大的tree node
 * 此時已經要直接停止recursive, 因此利用回傳bool, 當return true後
 * 每一層DFS都會直接return true直到回到最上層
 */
bool DFS(TreeNode *root, int &k, int &output)
{
  if (root == nullptr)
    return false;

  if (DFS(root->left, k, output))
    return true;

  k--;
  if (k == 0)
  {
    output = root->val;
    return true;
  }

  if (DFS(root->right, k, output))
    return true;

  return false;
}

int kthSmallest(TreeNode *root, int k)
{
  int output;
  DFS(root, k, output);
  return output;
}

/**
 * Iterative version
 * Time: O(N), Space: O(H)
 * 解題流程: 和Inorder traverse相同
 * 差別只在於根據k要找出第k小的數字, 因此就是在做inorder traverse的過程中, 當traverse到一個tree node 就將
 * k_temp++, 當k_temp == k就代表此時找到第k小的數字則直接return
 */
int kthSmallest(TreeNode *root, int k)
{
  stack<TreeNode *> stack;
  int k_temp = 0;
  while (root || !stack.empty())
  {
    if (root)
    {
      stack.push(root);
      root = root->left;
    }
    else
    {
      TreeNode *node = stack.top();
      stack.pop();

      k_temp++;
      if (k_temp == k)
        return node->val;

      root = node->right;
    }
  }
  return 0;
}
