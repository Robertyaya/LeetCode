/*
 * @lc app=leetcode id=92 lang=cpp
 *
 * [92] Reverse Linked List II
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
     * Time: O(N), Size: O(1)
     * 解題流程: 
     * ex: 
     * -1->1->2->3->4->5->NULL  m=2, n=4
     *  p  c  n
     *     p  c  n
     * -1->1  2<-3<-4 5->NULL
     *     *  *
     * 要記錄住這兩個*號, 剩下則是一般的reverse linkedlist
     * 當cur到達n=4的位置時, 則進入連接模式
     * -1->1接到4, 2接到5
     * -1->1-> 4->3->2 ->5
     *    
     */
public:
    ListNode *reverseBetween(ListNode *head, int m, int n)
    {
        if (!head || !head->next || m == n)
            return head;

        ListNode *dummy = new ListNode(-1);
        dummy->next = head;
        ListNode *prev = dummy;
        ListNode *cur = dummy->next;
        ListNode *fut = nullptr;

        // 紀錄n的前一個位置
        ListNode *prev_ = nullptr;
        // 紀錄n的位置
        ListNode *cur_ = nullptr;

        bool reverse = false;
        int index = 1; // 紀錄目前到達第幾個node
        while (cur)
        {
            // Record the next pointer
            fut = cur->next;

            // Start to reverse
            if (reverse)
            {
                cur->next = prev;
                // 代表到此node, 結束reverse
                if (index == n)
                {
                    prev_->next = cur;
                    cur_->next = fut;
                    break;
                }
            }

            // 代表從此node開始reverse
            if (index == m)
            {
                prev_ = prev;
                cur_ = cur;
                reverse = true;
            }

            // Update pointer
            prev = cur;
            cur = fut;
            index++;
        }
        return dummy->next;
    }
};
// @lc code=end
