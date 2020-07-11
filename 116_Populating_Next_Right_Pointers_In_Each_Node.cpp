#include <bits/stdc++.h>
using namespace std;
/**
 * Level-order traverse (recursive version)
 * Time: O(N), Space: O(H)
 * 解題流程: 因為為perfact binary tree, 因此如果current node的left node存在, 那麼left node一定是連到current-node的right node去
 *     a
 *   b   c
 *  d e f g
 * d->e 然後如果要e連到f的判斷就是
 * b->next = c也就是 c->left
 * 如果此時走到c, 其next為null, 因此c的right一定也是null, 反之則是連到next的left node
 * 
 */

void ConnectRecursive(Node *node)
{
  if (!node)
    return;
  // 因為為perfact binary tree, left node存在right node一定存在
  if (node->left)
    node->left->next = node->right;
  if (node->right)
    node->right->next = node->next ? node->next->left : NULL;
  ConnectRecursive(node->left);
  ConnectRecursive(node->right);
}
Node *connect(Node *root)
{
  if (!root)
    return nullptr;

  Node *runner = root;
  ConnectRecursive(runner);
  return root;
}
/**
 * Level-order traverse (iterative version)
 * Time: O(N), Space: O(1)
 */
Node *connect(Node *root)
{
  if (!root)
    return {};
  Node *runner = root;
  queue<Node *> que;
  que.push(runner);
  while (!que.empty())
  {
    for (int i = que.size(); i >= 1; i--)
    {
      Node *node = que.front();
      que.pop();

      // 最後一個指向NULL
      if (i == 1)
        node->next = NULL;
      else // 不是最後一個則指向下一個要pop出來的node
        node->next = que.front();

      if (node->left)
        que.push(node->left);
      if (node->right)
        que.push(node->right);
    }
  }
  return root;
}
