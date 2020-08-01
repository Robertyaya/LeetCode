/*
 * @lc app=leetcode id=143 lang=cpp
 *
 * [143] Reorder List
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
     * 1. 利用快慢指針找到mid node
     * 2. 斷開分成左邊跟右邊
     * 3. Reverse 右邊的linkedlist
     * 4. merge一個一個插入
     * 
     * Merge的流程:
     * Left: 1->2->3, right: 4->5
     * 利用一個next指向2
     * Connect right
     * 
     * 1->4->5, 2->3
     *          * (next)
     * 將right從4移到5
     * 1->4->5         2->3
     *       *(right)
     * 4指向next變成
     * 1->4->2->3   5
     *              (right)
     * update left從1到2    
     * 
     * 
     */
public:
    void reorderList(ListNode *head)
    {
        if (!head || !head->next || !head->next->next)
            return;

        // 利用快慢指針找到mid node, O(N)
        ListNode *mid = head;
        ListNode *fast = head;
        // Find the mid node
        while (fast->next && fast->next->next)
        {
            mid = mid->next;
            fast = fast->next->next;
        }

        // 斷開兩邊
        ListNode *left_list = head;
        ListNode *right_list = mid->next;
        mid->next = nullptr;

        // Reverse the right_list, O(N)
        ListNode *prev = nullptr;
        ListNode *cur = right_list;
        ListNode *next;
        while (cur)
        {
            next = cur->next;
            if (!next)
                right_list = cur;
            cur->next = prev;
            prev = cur;
            cur = next;
        }

        // 一個一個插入, O(N)
        while (left_list->next)
        {
            ListNode *next = left_list->next;
            left_list->next = right_list;

            right_list = right_list->next;
            left_list->next->next = next;
            left_list = next;
        }
        if (right_list)
            left_list->next = right_list;
    }
    /**
 * Time: O(N^2), Space: O(1)
 */
    void reorderList(ListNode *head)
    {
        if (!head || !head->next)
            return;

        // 計算linkedlist長度, O(N)
        int length = 0;
        ListNode *temp = head;
        while (temp)
        {
            temp = temp->next;
            length++;
        }
        if (length <= 2)
            return;

        // 每次都根據length, 往後面找到node後再連到前面來
        ListNode *left = head;
        while (left)
        {
            ListNode *next = left->next;
            ListNode *right = left;
            int temp_l = length;
            // 往後面找到要連過來的node
            while (temp_l > 2)
            {
                right = right->next;
                temp_l--;
            }
            ListNode *right_next = right->next;
            right->next = nullptr;

            // Connect
            left->next = right_next;
            right_next->next = next;

            // Update
            left = left->next->next;
            length -= 2;
            if (length <= 2)
                break;
        }
    }
};
// @lc code=end
