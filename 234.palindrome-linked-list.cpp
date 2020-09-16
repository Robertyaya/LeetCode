/*
 * @lc app=leetcode id=234 lang=cpp
 *
 * [234] Palindrome Linked List
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
     * 解題流程: 題目follow up要求Time: O(N), Space: O(1)
     * 分為3步驟
     * 1. 利用快慢指針找到mid node, 切成兩半
     * 2. Reverse左半邊的linkedlist
     * 3. Compare兩邊linkedlist的數值, 如果不同則retur false
     * 
     * 需要特別處理的是當linkedlist為odd and even
     * ex: 1->2->2->  3  ->2    ->2->1
     *          prev mid right
     * 斷開兩邊
     * left: 1->2->2->nullptr   right: 2->2->1->nullptr
     * Reverse left linkedlist
     * 
     * left: nullptr<-1<-2<-2   right: 2->2->1->nullptr
     *                     head
     * 比較兩邊數字
     */
public:
    // 計算Linkedlist的長度, 確認odd or even
    int CalLength(ListNode *node)
    {
        ListNode *temp = node;
        int l = 0;
        while (temp)
        {
            temp = temp->next;
            l++;
        }
        return l;
    }
    // Reverse the linkedlist
    ListNode *Reverse(ListNode *node)
    {
        ListNode *prev = nullptr;
        ListNode *cur = node;
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
    bool isPalindrome(ListNode *head)
    {
        if (!head || !head->next)
            return true;

        int length = CalLength(head);
        ListNode *slow = head;
        ListNode *fast = head;
        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        // 分成兩邊linkedlist
        ListNode *left = head;
        ListNode *right;
        if (length % 2 != 0)
            right = slow->next;
        else
            right = slow;

        // Reverse linkedlist, 因為為回文, 所以其中一邊的要先reverse才能比較
        ListNode *rever_right = Reverse(right);

        for (int i = 0; i < length / 2; i++)
        {
            if (left->val != rever_right->val)
                return false;

            left = left->next;
            rever_right = rever_right->next;
        }
        return true;
    }
};
// @lc code=end
