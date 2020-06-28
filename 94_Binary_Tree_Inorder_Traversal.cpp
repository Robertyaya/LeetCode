#include <bits/stdc++.h>
using namespace std;
/** Iterative method
 * Time: O(N), Space: O(N)
 * Iterative method and recursive method差別在於一個是利用系統呼叫的stack, 一個是將node自己塞入stack中
 */
vector<int> inorderTraversal(TreeNode *root)
{
  vector<int> output;
  TreeNode *node = root;
  stack<TreeNode *> stack;

  while (node || !stack.empty())
  {
    if (node)
    {
      stack.push(node);
      node = node->left;
    }
    else
    {
      TreeNode *todo = stack.top();
      stack.pop();
      output.push_back(todo->val);
      node = todo->right;
    }
  }
  return output;
}
/** Recursive version
 * Time: O(N), Space: O(N) (stack = height, average tree height = logN, worst case O(N))
 */
void inorderTraversalDFS(TreeNode *node, vector<int> &output)
{
  if (node == nullptr)
    return;
  inorderTraversalDFS(node->left, output);
  output.push_back(node->val);
  inorderTraversalDFS(node->right, output);
}
vector<int> inorderTraversal(TreeNode *root)
{
  vector<int> output;
  inorderTraversalDFS(root, output);
  return output;
}
