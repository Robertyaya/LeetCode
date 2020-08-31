/*
 * @lc app=leetcode id=328 lang=cpp
 *
 * [328] Odd Even Linked List
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
     * Odd串接奇數的node, even串接偶數的node
     * seconde用來記錄even的head node
     * 最後再將odd的tail node和second串接起來
     */
public:
    ListNode *oddEvenList(ListNode *head)
    {
        if (!head || !head->next)
            return head;

        ListNode *second = head->next;

        ListNode *odd = head;
        ListNode *even = head->next;
        while (odd && even)
        {
            odd->next = even->next;

            // 偶數個node的情況, 串接even linkedlist
            if (!odd->next)
            {
                odd->next = second;
                break;
            }

            odd = odd->next;
            even->next = odd->next;
            even = even->next;
        }
        // 奇數個node的情況, 串接odd linkedlist
        if (!odd->next)
            odd->next = second;
        return head;
    }
};
// @lc code=end
