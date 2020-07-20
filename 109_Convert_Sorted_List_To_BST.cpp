#include <bits/stdc++.h>
using namespace std;
/**
 * Time: O(N), Space: O(H)
 * 解題流程: 此題為作法概念跟problem108相同, 差別只在於此題為linkedlist, 因此沒辦法直接從index取值
 * 利用快慢指針找出mid node
 * 這邊要注意得是end_node, end_node要取的是結尾的下一個, 因為在while迴圈判斷時, 當fast == end時會跳出, 所以fast==end時這個數值不會計算到, 因此end要取的是要計算的下一個node
 * ex:
 * 1     ->  2  ->  3
 * start               end
 * end不能指向3, 這樣3就不會被計算到
 
 */
TreeNode *BuildBST(ListNode *start, ListNode *end)
{
  // Base case, 此時的node會在TreeNode *res = new TreeNode(slow->val);這邊就建立了
  if (start == end)
    return nullptr;

  ListNode *slow = start;
  ListNode *fast = start;

  // 利用快慢指針找出mid node
  while (fast != end && fast->next != end)
  {
    fast = fast->next->next;
    slow = slow->next;
  }

  TreeNode *res = new TreeNode(slow->val);
  res->left = BuildBST(start, slow);
  res->right = BuildBST(slow->next, end);
  return res;
}
TreeNode *sortedListToBST(ListNode *head)
{
  ListNode *start = head;
  ListNode *end = nullptr;
  return BuildBST(start, nullptr);
}
