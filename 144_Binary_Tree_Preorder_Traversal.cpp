#include <bits/stdc++.h>
using namespace std;
/**
 * Iterative version
 * Time: O(N), Space: O(N)
 */
vector<int> preorderTraversal(TreeNode *root)
{
  TreeNode *node = root;
  vector<int> output;
  stack<int> stack;
  while (node || !stack.empty())
  {
    if (node)
    {
      output.push_back(node->val);
      stack.push(node);
      node = node->left;
    }
    else
    {
      TreeNode *todo = stack.top();
      stack.pop();
      node = todo->right;
    }
  }
  return output;
}
/**
 * Recursive version
 * Time: O(N), Space: O(N) 
 */
void DFS(TreeNode *node, vector<int> &output)
{
  if (node == nullptr)
    return;

  output.push_back(node->val);
  DFS(node->left, output);
  DFS(node->right, output);
}
vector<int> preorderTraversal(TreeNode *root)
{
  vector<int> output;
  DFS(root, output);
  return output;
}
