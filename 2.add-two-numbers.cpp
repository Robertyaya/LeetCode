/*
 * @lc app=leetcode id=2 lang=cpp
 *
 * [2] Add Two Numbers
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
     * 解題流程: Traverse各別linkedlist各別相加數值, 注意進位問題, 以及可能會有其中一個比較短會提早結束
     */
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode *res = new ListNode(-1);
        ListNode *runner = res;
        int a = 0;
        while (l1 || l2)
        {
            int value = a;
            if (l1)
                value += l1->val;
            if (l2)
                value += l2->val;

            if (value >= 10)
            {
                a = 1;
                value -= 10;
            }
            else
                a = 0;

            runner->next = new ListNode(value);
            runner = runner->next;
            if (l1)
                l1 = l1->next;
            if (l2)
                l2 = l2->next;
        }

        if (a)
            runner->next = new ListNode(a);
        return res->next;
    }
};
// @lc code=end
