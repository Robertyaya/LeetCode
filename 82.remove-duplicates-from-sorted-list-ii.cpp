/*
 * @lc app=leetcode id=82 lang=cpp
 *
 * [82] Remove Duplicates from Sorted List II
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
     * The lengtht of linkedlist is N
     * Time: O(N), Space: O(1)
     * 解題流程: Two pointer
     * 當遇到相同的則持續update cur pointer, 直到其next和prev->next->val不同
     * 則將prev->next連到cur->next
     */
public:
    ListNode *deleteDuplicates(ListNode *head)
    {
        if (!head || !head->next)
            return head;

        ListNode *dummy = new ListNode(-1);
        dummy->next = head;
        ListNode *prev = dummy;
        ListNode *cur = head;

        while (cur && cur->next)
        {
            if (prev->next->val != cur->next->val)
            {
                prev = prev->next;
                cur = cur->next;
            }
            else
            {
                // update cur pointer,直到找到不同的val
                while (cur->next && cur->next->val == prev->next->val)
                {
                    cur = cur->next;
                }
                // 找到後將prev->next連到cur->next, 這樣相當於中間的都被remove掉
                prev->next = cur->next;
                cur = cur->next;
            }
        }

        return dummy->next;
    }
};
// @lc code=end
