#include <bits/stdc++.h>
using namespace std;
/** 
 * Iterative version
 * Time: O(N), Space: O(N)
 * 解題流程: problem 94, 144, 145同樣解題方法
 * 此題post order(左右中) 和 preorder(中左右)相同
 * 我們將preorder的做法修改成(中右左)之後, 接著在push_back進去時全部reverse成(左右中)
 * 因此我們利用insert插入vector的begin()
 */
vector<int> postorderTraversal(TreeNode *root)
{
  TreeNode *node = root;
  vector<int> output;
  stack<TreeNode *> stack;
  while (node || !stack.empty())
  {
    if (node)
    {
      stack.push(node);
      output.insert(output.begin(), node->val);
      node = node->right;
    }
    else
    {
      TreeNode *todo = stack.top();
      stack.pop();
      node = node->left;
    }
  }
  return output;
}

/**
 * Recursive version
 * Time: O(N), Space: O(N)
 */
void DFS(TreeNode *root, vector<int> &output)
{
  if (root == nullptr)
    return;

  DFS(root->left, output);
  DFS(root->right, output);
  output.push_back(root->val);
}
vector<int> postorderTraversal(TreeNode *root)
{
  vector<int> output;
  DFS(root, output);
  return output;
}
