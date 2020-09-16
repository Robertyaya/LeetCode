/*
 * @lc app=leetcode id=206 lang=cpp
 *
 * [206] Reverse Linked List
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
     * Time: O(N), Space: O(N)
 * Recursive version
 * 1->2->3->4->5->null
 *           newhead
 * 會先走到底, 此時newhead = 5, head = 4
 * head->next->next概念就是5的next要指向4
 * 因此原本4->5會變成4<-5
 * head->next = nullptr
 * nullptr <- 4 <- 5
 * 回到上一層
 * newhead還是5, head = 3
 * head->next->next為 3<-4<-5
 * head->next為 nullptr<-3<-4<-5
 * 
 */
    ListNode *reverseList(ListNode *head)
    {
        // Edge case
        if (!head)
            return nullptr;

        if (!head->next)
            return head;
        ListNode *newHead = reverseList(head->next);
        head->next->next = head;
        head->next = nullptr;
        return newHead;
    }
    /**
     * Time: O(N), Space: O(1)
 * Iterative version
 */
    ListNode *reverseList(ListNode *head)
    {
        ListNode *prev = nullptr;
        ListNode *cur = head;
        ListNode *next = nullptr;
        while (cur)
        {
            next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        return prev;
    }
};
// @lc code=end
