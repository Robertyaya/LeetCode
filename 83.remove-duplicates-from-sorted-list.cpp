/*
 * @lc app=leetcode id=83 lang=cpp
 *
 * [83] Remove Duplicates from Sorted List
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
     * Two pointer, same as problem 82
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
                while (cur->next && cur->next->val == prev->next->val)
                {
                    cur = cur->next;
                }

                // 相同數字要保留一個, 多往前一格
                prev->next->next = cur->next;
                cur = cur->next;
                prev = prev->next;
            }
        }
        return dummy->next;
    }
};
// @lc code=end
