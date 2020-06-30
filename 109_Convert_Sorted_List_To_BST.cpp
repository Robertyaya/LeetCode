#include <bits/stdc++.h>
using namespace std;

TreeNode *BuildBST(ListNode *head, ListNode *tail)
{
  TreeNode *head_runner = head;
  TreeNode *tail_runner = tail;
  TreeNode *mid = nullptr;
  // Find mid
  while (head->val < tail->val)
  {
    if (head_runner->next == tail_runner->next)
    {
      mid = head_runner->next;
      break;
    }
    head_runner = head_runner->next;
    tail_runner = tail_runner->next;
  }

  TreeNode *root = new TreeNode(mid->val);
}

TreeNode *sortedListToBST(ListNode *head)
{
  if (head == nullptr)
    return nullptr;
  // Find tail
  ListNode *tail = head;
  while (tail->next)
  {
    tail = tail->next;
  }
  return BuildBST(ListNode * head, ListNode * tail);
}
