/*
 * @lc app=leetcode id=61 lang=cpp
 *
 * [61] Rotate List
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
     * N is the size of linkedlist
     * Time: O(N), Space: O(1)
     * 解題流程: 因為為rotate
     * ex: 1->2->3->4->5
     * k=2跟k=7的答案會相同, 因為length=5, 因此每5次又會變成相同的linkedlist, 因此先將k取mod, 看餘數為多少代表要rotate幾次
     * left為指向最左邊的node
     * right為指向最右邊的node
     * right_previous為指向right前一個node
     */
public:
    ListNode *rotateRight(ListNode *head, int k)
    {
        if (!head)
            return head;

        ListNode *left = head;
        ListNode *right = head;
        int length = 1;
        while (right->next)
        {
            right = right->next;
            length++;
        }
        // 算出餘數, 代表要rotate幾次
        k = k % length;

        // Represent only one node
        if (left == right)
            return head;

        while (k > 0)
        {
            ListNode *right_previous = left;

            // 找到right的前一個node
            while (right_previous->next != right)
            {
                right_previous = right_previous->next;
            }

            // Rotate
            right->next = left;
            right_previous->next = nullptr;
            left = right;
            right = right_previous;

            k--;
        }
        return left;
    }
};
// @lc code=end
