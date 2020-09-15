/*
 * @lc app=leetcode id=141 lang=cpp
 *
 * [141] Linked List Cycle
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
    /**
     * Time: O(N), Space: O(1)
     * 解題流程: 利用快慢指針
     * 如果有cycle, 快指針"一定"會和慢指針相遇
     * 
     */
public:
    bool hasCycle(ListNode *head)
    {
        if (!head || !head->next)
            return false;

        ListNode *slow = head;
        ListNode *fast = head;
        while (slow && fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast)
                return true;
        }
        return false;
    }
    /**
     * Time: O(N), Space: O(N)
     */
    bool hasCycle(ListNode *head)
    {
        if (!head || !head->next)
            return false;

        unordered_set<ListNode *> set;
        ListNode *node = head;
        while (node)
        {
            if (set.count(node))
                return true;
            set.insert(node);
            node = node->next;
        }
        return false;
    }
};
// @lc code=end
