#include <bits/stdc++.h>
using namespace std;
/**
 * Time: O(N), Space: O(H)
 * 解題流程: 此題要找出所有可能的path, 根據problem112的做法相同, Recursive下去
 * 過程中將current node's value塞到vector中直到到了leaf(right == nullptr && left == nullptr)做判斷
 * 如果sum==0代表此path可以將其加到output中, 反之則不用加入
 * 另外有一個關鍵在於, 每次回到上一層的時候都要pop_back current的數值
 * 
 */
void DFS(TreeNode *node, int sum, vector<vector<int>> &output, vector<int> &res)
{
  if (node == nullptr)
    return;

  res.push_back(node->val);
  sum -= node->val;

  // When arrive the leaf, need to check
  if (node->left == nullptr && node->right == nullptr)
  {
    // This path is valid
    if (sum == 0)
      output.push_back(res);
    // 回到上一層需要將這層push_back進去的pop出來
    res.pop_back();
    return;
  }

  DFS(node->left, sum, output, res);
  DFS(node->right, sum, output, res);
  // 回到上一層需要將這層push_back進去的pop出來
  res.pop_back();
}
vector<vector<int>> pathSum(TreeNode *root, int sum)
{
  vector<vector<int>> output;
  vector<int> res;
  DFS(root, sum, output, res);
  return output;
}
