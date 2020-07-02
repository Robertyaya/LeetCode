#include <bits/stdc++.h>
using namespace std;
/**
 * Time: O(N), Space: O(1) (因為沒有使用hash map)
 * 解題流程: 這題關鍵是在original linkedlist中insert進去相同的node之後再各別斷開成兩個linkedlist
 * 因此沒有使用到hash map
 * ex: ()代表random pointer
 * 1(2)->2(3)->3(4)->null
 * 
 * 1. Insert node (the first while loop)
 * 1(2) -> 1(null) -> 2(3) -> 2(null) -> 3(4) -> 3(null) -> null
 * 
 * 2. 放入random pointer
 * runner->next->random 代表的就是copy的那個的random pointer
 * runner->random->next (其中runner->random代表的就是current node的random pointer, 但此random pointer是指向original linkedlist 並不是copy的那個, 因此要->next才是指向copy的那個node)
 * 
 * 3. 最後則是要斷開original linkedlist and copy linkedlist
 * 1(2) = copy's 1(2)->next
 * 連好original node後再連copy node
 * copy's 1(2)->next = 1(2)->next->next (代表的就是1(2)->next這個node的copy)
 * 最後在尾巴的部分要注意會有null的出現
 * 
 */
Node *copyRandomList(Node *head)
{
  if (head == nullptr)
    return nullptr;

  Node *runner = head;
  // 在中間插一個相同的node, 但random此時insert的為nullptr
  while (runner)
  {
    Node *insert = new Node(runner->val);
    insert->next = runner->next;
    runner->next = insert;

    // Update runner
    runner = insert->next;
  }

  runner = head;
  // 填入random
  while (runner)
  {
    if (runner->random != nullptr)
      runner->next->random = runner->random->next;
    runner = runner->next->next;
  }

  // 斷開連接
  runner = head;
  Node *output = runner->next;
  Node *output_runner = output;
  while (runner)
  {
    runner->next = output_runner->next;
    // 在最後面時, runner->next更新完後指向null, 此時代表已經到達last node, 因此output_runner也指向null
    if (runner->next == nullptr)
      output_runner->next = nullptr;
    else
      output_runner->next = runner->next->next;

    // Update runner
    runner = runner->next;
    output_runner = output_runner->next;
  }
  return output;
}
/**
 * Time: O(N), Space: O(N)
 * 解題流程: 此題關鍵在處理random pointer, 其實random pointer的含義就是
 * ex: node1的random pointer指向node3, "!那其實就是random pointer就是node3的意思!"
 * 意思就是ex: node1->random->val == node3->val
 * 
 * 因此我們利用hashmap. key代表的是original linkedlist的node, value代表的是deep copy的linkedlist的node
 * 有了這層關係之後, 在連接random pointer時 
 * ex: 當我到達node1此時random pointer指向node3, 那經由map我們的key直接放random pointer代表的意義就是放node3
 * 那我們就可以知道deep copy的那個linkedlist的node3的位置
 */
Node *copyRandomList(Node *head)
{
  if (head == nullptr)
    return nullptr;

  // 用來traverse original linkedlist
  Node *head_runner = head;
  // 用來point to the root of deep copy's linkedlist
  Node *answer = new Node(head->val);
  // 用來traverse deep copy's linkedlist
  Node *answer_runner = answer;
  // Key is the original node, value is the new node which deep copy
  unordered_map<Node *, Node *> map;
  map[head] = answer;

  // Fill the val first and insert into map
  while (head_runner)
  {
    head_runner = head_runner->next;
    if (head_runner == nullptr)
    {
      answer_runner->next = nullptr;
      break;
    }
    answer_runner->next = new Node(head_runner->val);
    answer_runner = answer_runner->next;
    // Insert to map
    map[head_runner] = answer_runner;
  }

  // Fill the random
  answer_runner = answer;
  while (answer_runner && head)
  {
    if (head->random == nullptr)
      answer_runner->random == nullptr;
    else
      answer_runner->random = map[head->random];
    answer_runner = answer_runner->next;
    head = head->next;
  }

  return answer;
}
