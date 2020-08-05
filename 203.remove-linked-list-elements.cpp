/*
 * @lc app=leetcode id=203 lang=cpp
 *
 * [203] Remove Linked List Elements
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
     * Two pointer
     */
public:
    ListNode *removeElements(ListNode *head, int val)
    {
        if (!head)
            return nullptr;

        ListNode *dummy = new ListNode(-1);
        dummy->next = head;
        ListNode *prev = dummy;
        while (head)
        {
            if (head->val == val)
            {
                prev->next = head->next;
                head = head->next;
                continue;
            }

            head = head->next;
            prev = prev->next;
        }
        return dummy->next;
    }
};
// @lc code=end
