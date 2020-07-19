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
        ListNode *res = nullptr;
        ListNode *runner = res;

        // 紀錄是否要進位
        int step = 0;
        while (l1 || l2)
        {
            int value;
            if (!l1)
                value = l2->val + step;
            else if (!l2)
                value = l1->val + step;
            else
                value = l1->val + l2->val + step;

            step = 0;
            if (value >= 10)
            {
                step = 1;
                value -= 10;
            }

            // Update l1 and l2, 如果l1 or l2現在為nullptr, 則不需要update
            if (l1)
                l1 = l1->next;
            if (l2)
                l2 = l2->next;

            // Initialize res linkedlist
            if (!res)
            {
                res = new ListNode(value);
                runner = res;
            }
            else
            {
                runner->next = new ListNode(value);
                runner = runner->next;
            }
        }

        // 代表還有最後一個還沒進位
        // ex: l1:[5] l2:[5]
        // 第一位相加之後, l1 and l2update到下一位之後就會跳出while迴圈, 此時其實還有step還沒1尚未處理
        if (step)
            runner->next = new ListNode(step);

        return res;
    }
};
// @lc code=end
