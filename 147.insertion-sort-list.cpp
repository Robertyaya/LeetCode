/*
 * @lc app=leetcode id=147 lang=cpp
 *
 * [147] Insertion Sort List
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
 * Time: O(N^2), Space: O(1)
 */
    ListNode *insertionSortList(ListNode *head)
    {
        if (!head)
            return nullptr;

        // !!關鍵!!故意放一個0在最前面, 這樣才不用去考慮如果需要插在head的時候情況, 全部都可以統一用一種insert method, 因為不會有任何一個node插在head處
        ListNode *new_list = new ListNode(0); // 新的linkedlist
        ListNode *new_list_runner = new_list; // 用來找出新的linkedlist中, 哪邊insert

        while (head)
        {
            ListNode *node = new ListNode(head->val); // 根據original linkedlist new 出一個新的node

            // 找出要insert的位置
            // current val 要比taget小, next val要比target大, 那那個位置就是insert位置
            while (new_list_runner->next && new_list_runner->next->val <= node->val)
                new_list_runner = new_list_runner->next;

            // Insert 進去
            node->next = new_list_runner->next;
            new_list_runner->next = node;

            // Initial runner
            new_list_runner = new_list;

            // Update original linkedlist to next node
            head = head->next;
        }

        return new_list->next;
    }
};
// @lc code=end
