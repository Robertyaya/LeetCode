#include <bits/stdc++.h>
using namespace std;
/**
 * Time: O(N), Space: O(H)
 * 解題流程: 
 * 1. Constructor: 先到minimum tree node, 也就是最左邊的tree node, 並將每一層的tree node存到stack中
 * 這樣才可以back track回來
 * 2.Find next: 
 * 在Binary search tree中最小的是最左邊的node, 下一個最小的node就是current node先往right node一格, 再持續往left node下去
 */
class BSTIterator
{
public:
  BSTIterator(TreeNode *root)
  {
    while (root)
    {
      stack.push(root);
      root = root->left;
    }
  }

  /** @return the next smallest number */
  int next()
  {
    TreeNode *todo = stack.top();
    int value = todo->val;
    stack.pop();

    // Right node存在的話
    if (todo->right)
    {
      todo = todo->right;
      while (todo)
      {
        stack.push(todo);
        todo = todo->left;
      }
    }
    return value;
  }

  /** @return whether we have a next smallest number */
  bool hasNext()
  {
    return !stack.empty();
  }

  stack<int> stack;
};
