#include <bits/stdc++.h>
using namespace std;
/**
 * Time: O(N), Space: O(H)
 * 解題流程: 此題為作法概念跟problem108相同, 差別只在於此題為linkedlist, 因此沒辦法直接從index取值
 * head指向linked list的頭, tail指向linked list的尾, length則是那個區段linked list的長度
 * 1. 先找到linkedlist的tail後開始進入recursive
 * 2. 關鍵在於因為要把整個linked list的Mid還有left subtree and right subtree區段找出來
 * 我們利用lenght的數值可以求得mid的數值, 接著update到mid數值的mid_node, 過程中也同時update left_num, 這樣即可知道left sub_tree的長度
 * 找到mid_node之後, 其實right subtree的區段就可以決定了
 * right subtree區段就是mid_node->next ~ tail這個區段
 * 而left subtree尚未知道, 因為我們沒辦法直接get mid_node previous node, 因此需要設一個previous_mid_node
 * 在update mid_node的過程中持續update, 保持此node指向mid_node的前一個node
 * 有了previous_mid_node之後我們就可以知道left_sub_tree的區段就是start~previou_mid_node
 * 因此這樣就可以繼續下去recursive將大問題變成小問題直到到達base case
 */

TreeNode *BuildBST(ListNode *head, ListNode *tail, int length)
{
<<<<<<< HEAD
=======
  // Base case []
  if (length == 0)
    return nullptr;
  // Head and tail point to same node
  if (length == 1)
  {
    TreeNode *temp = new TreeNode(head->val);
    return temp;
  }

  int mid = length / 2;
  TreeNode *previous_mid_node = head; // 指向mid_node左邊的node
  TreeNode *mid_node = head;          // 指向mid_node
  int left_length = 1;                // Update left_length
  while (mid > 0)
  {
    // Point to the current mid_node
    previous_mid_node = mid_node;
    // Update mid_node to next
    mid_node = mid_node->next;
    left_length++;
    mid--;
  }
  TreeNode *node = new TreeNode(mid_node->val);
  node->left = BuildBST(head, previous_mid_node, left_length - 1);
  node->right = BuildBST(mid_node->next, tail, length - left_length);
  return node;
>>>>>>> a74a151bbc83d03c76f11e89e8d712ca8a3fa9f3
}

TreeNode *sortedListToBST(ListNode *head)
{
<<<<<<< HEAD
=======
  // Edge case
  if (head == nullptr)
    return nullptr;

  // Find tail in linkedlist
  int length = 1;
  ListNode *tail = head;
  while (tail->next)
  {
    tail = tail->next;
    length++;
  }

  return BuildBST(head, tail, length);
>>>>>>> a74a151bbc83d03c76f11e89e8d712ca8a3fa9f3
}
