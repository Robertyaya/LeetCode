/*
 * @lc app=leetcode id=21 lang=cpp
 *
 * [21] Merge Two Sorted Lists
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
     */
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
    {
        ListNode *dummy = new ListNode(-1);
        ListNode *cur = dummy;

        // 當兩個linkedlist都存在時, 才進入while迴圈比大小merge
        while (l1 && l2)
        {
            if (l1->val <= l2->val)
            {
                cur->next = new ListNode(l1->val);
                l1 = l1->next;
            }
            else
            {
                cur->next = new ListNode(l2->val);
                l2 = l2->next;
            }
            cur = cur->next;
        }

        // 跳出while代表可能任一個到達尾巴或是都到達尾巴, 因此只要將next直接接著還剩下的linkedlist就可以
        if (l1) //l1還有剩下的node還沒traverse到, 因為l2已經到達尾巴, 因此不用merge, 直接接起來
            cur->next = l1;
        if (l2)
            cur->next = l2;

        return dummy->next;
    }
};
// @lc code=end
