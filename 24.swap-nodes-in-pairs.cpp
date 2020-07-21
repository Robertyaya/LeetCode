/*
 * @lc app=leetcode id=24 lang=cpp
 *
 * [24] Swap Nodes in Pairs
 *
 * https://leetcode.com/problems/swap-nodes-in-pairs/description/
 *
 * algorithms
 * Medium (50.01%)
 * Likes:    2307
 * Dislikes: 171
 * Total Accepted:    473.2K
 * Total Submissions: 944.3K
 * Testcase Example:  '[1,2,3,4]'
 *
 * Given a linked list, swap every two adjacent nodes and return its head.
 * 
 * You may not modify the values in the list's nodes, only nodes itself may be
 * changed.
 * 
 * 
 * 
 * Example:
 * 
 * 
 * Given 1->2->3->4, you should return the list as 2->1->4->3.
 * 
 * 
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
    /**
     * Time: O(N), Space: O(1)
     * 解題流程: 
     * A代表previous, B代表current, C代表future, 因為linkedlist只能從前一個來找到現在的node, 因此前面
     * 要加一個dummy node
     * ex: -1->1->2->3->4->x
     *      A  B  C
     * 1. 先用一個temp去紀錄B
     * 2. A連到C, A->C
     * 3. B連到C, B->C
     * 4. 最後則將C連到剛剛紀錄的temp, C->temp(原本B的node)
     * 因此會變成
     * -1->2->1, 然後因為pointer會指向原本的node
     *  A  C  B 會變成如此
     * 
     * 因此要將C and B指向的node交換, 這樣才可以繼續做update
     * -1->2->1
     *  A  B  C
     */
public:
    ListNode *swapPairs(ListNode *head)
    {
        if (!head || !head->next)
            return head;

        ListNode *res = new ListNode(-1);
        res->next = head;

        ListNode *previous = res;
        ListNode *current = head;
        ListNode *future = head->next;

        while (current && current->next)
        {
            ListNode *current_record = current;
            previous->next = future;
            current->next = future->next;
            future->next = current_record;

            // Swap two pointer
            future = current;
            current = previous->next;

            // Update three pointer
            previous = future;
            current = future->next;
            if (current)
                future = future->next->next;
        }

        return res->next;
    }
};
// @lc code=end
