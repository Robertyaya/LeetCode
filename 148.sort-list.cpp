/*
 * @lc app=leetcode id=148 lang=cpp
 *
 * [148] Sort List
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
public:
    /**
 * Merge sort
 */
    ListNode *
        ListNode *
        sortList(ListNode *head)
    {
        ListNode *fast = head;
        ListNode *slow = head; // slow will point to the mid node
        while (fast->next->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        return merge(head, slow);
    }
};
// @lc code=end
