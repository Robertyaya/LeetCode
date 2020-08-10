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
    bool isPalindrome(ListNode *head)
    {
        if (!head || !head->next)
            return true;

        ListNode *prev = head;
        ListNode *slow = head;
        ListNode *fast = head;
        bool even = false;
        // O(N)
        while (fast->next && fast->next->next)
        {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
            // 此情況代表linkedlist為偶數
            if (fast->next != nullptr && fast->next->next == nullptr)
                even = true;
        }

        // 右半邊的linkedlist
        ListNode *right = slow->next;
        // 斷開為左半邊的linkedlist and 右半邊的linkedlist
        if (even)
            slow->next = nullptr;
        else
            prev->next = nullptr; // 如果為odd, 則左半邊的linkedlist則是從中間node的前一個斷開

        // Reverse the left linkedlist O(N)
        prev = nullptr;
        ListNode *next;
        while (head)
        {
            next = head->next;
            head->next = prev;
            prev = head;
            // 為了讓head指向左半邊linkedlist的頭的位置
            if (next == nullptr)
                break;
            head = next;
        }

        // Compare two linkedlist O(N)
        while (head)
        {
            if (head->val != right->val)
                return false;
            head = head->next;
            right = right->next;
        }
        return true;
    }
};
// @lc code=end
