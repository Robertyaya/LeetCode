#include <bits/stdc++.h>
using namespace std;
/**
 * Preorder traverse
 * Time: O(N), Space: O(N)
 * 解題流程: 此法較level-order還快
 * res.size() < level的意思是, 每一層只會有一個push_back進res裡面, 也就是最右邊那個
 * 利用修改過的Preorder, 我們可以確保如果右邊node沒有則用左邊的node,
 * ex:
 *        a
 *     b     c
 *   d   e  
 * Preorder的順序為a->c->b->e->d  
 *               *   *     *
 * b跟d不會加入, 因為c跟e為那一層被push_back進res裡面的node了
 * 
 * 
 */
void Preorder(TreeNode *node, vector<int> &res, int &level)
{
  if (!node)
    return;
  if (res.size() < level)
    res.push_back(node->val);
  Preorder(node->right, res, level + 1);
  Preorder(node->left, res, level + 1);
}
vector<int> rightSideView(TreeNode *root)
{
  vector<int> res;
  Preorder(root, res, 1);
  return res;
}
/**
 * Level-order traverse
 * Time: O(N), Space: O(1) (queue只需要存一層的node)
 * 解題流程: 利用level-order traverse, 一層一層的塞到que裡面, 一次解決一層
 * 當到了這層最後一個代表為這層的最右邊那個, 則push_back到answer裡面去
 */
vector<int> rightSideView(TreeNode *root)
{
  if (!root)
    return {};
  vector<int> res;
  queue<TreeNode *> que;
  que.push(root);
  while (!que.empty())
  {
    // 一層一層的塞到queue裡面去
    for (int i = que.size(); i >= 1; i--)
    {
      TreeNode *node = que.front();
      que.pop();
      if (node->left)
        que.push(que->left);
      if (node->right)
        que.push(que->right);

      // 當到了這層的最後一個則push到答案裡面, 因為代表是這層的最右邊那個node了
      if (i == 1)
        res.push_back(node->val);
    }
  }
  return res;
}
