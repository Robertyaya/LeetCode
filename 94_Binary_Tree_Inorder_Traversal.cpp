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

  // 先抵達left child最底層, 每一步都將node塞到stack中
  // 接著一步一步將stack的node pop出來
  while (node || !stack.empty())
  {
    while (node)
    {
      stack.push(node);
      node = node->left;
    }
    TreeNode *todo = stack.top();
    output.push_back(todo->val);
    stack.pop();
    node = todo->right;
  }
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
