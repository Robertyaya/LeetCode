#include <bits/stdc++.h>
using namespace std;
/**
 * Time: O(N), Space: O(N)
 * 解題流程: 此題為單向linkedlist, 因此需要先traverse過後知道length
 * 將length-n就可以知道start pointer需要移動多少步
 * 有一個edge case是如果此時要刪掉的node是start_node, 需要特別處理, 直接將head = head->next後直接return
 */
ListNode *removeNthFromEnd(ListNode *head, int n)
{
  if (!head)
    return nullptr;

  ListNode *start = head;
  ListNode *runner = head;
  int total_length = 0;
  // Arrive the end first and calculate the length of linkedlist
  // O(N)
  while (runner)
  {
    total_length++;
    runner = runner->next;
  }

  int move = total_length - n;

  // 代表要刪掉head, 因此要特別處理
  if (move == 0)
  {
    head = head->next;
    return head;
  }

  // O(N)
  while (move > 1)
  {
    start = start->next;
    move--;
  }
  start->next = start->next->next;

  return head;
}
