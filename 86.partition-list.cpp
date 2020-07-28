/*
 * @lc app=leetcode id=86 lang=cpp
 *
 * [86] Partition List
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
     * Time: O(N), Space: O(N)
     * 解題流程: 分兩個linkedlist left and right
     * traverse原本的linkedlist, 遇到比較小則接在left, 大於或等於則接在right
     * 最後再將left和right合併起來
     */
public:
    ListNode *partition(ListNode *head, int x)
    {
        if (!head || !head->next)
            return head;

        ListNode *left = new ListNode(-1);
        ListNode *left_run = left;
        ListNode *right = new ListNode(-1);
        ListNode *right_run = right;

        while (head)
        {
            if (head->val < x)
            {
                left_run->next = new ListNode(head->val);
                left_run = left_run->next;
            }
            else
            {
                right_run->next = new ListNode(head->val);
                right_run = right_run->next;
            }
            head = head->next;
        }

        left_run->next = right->next;
        ListNode *res = new ListNode(-1);
        res->next = left->next;
        return res->next;
    }
};
// @lc code=end
