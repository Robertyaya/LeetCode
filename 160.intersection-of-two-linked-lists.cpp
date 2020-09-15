/*
 * @lc app=leetcode id=160 lang=cpp
 *
 * [160] Intersection of Two Linked Lists
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
public:
    /**
     * Time: O(N), Space: O(1)
     */
    int GetLength(ListNode *node)
    {
        int length = 0;
        ListNode *n = node;
        while (n)
        {
            n = n->next;
            length++;
        }
        return length;
    }
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        // 移成同樣長度後開始比較
        int a_l = GetLength(headA);
        int b_l = GetLength(headB);
        if (a_l > b_l)
        {
            for (int i = 0; i < a_l - b_l; i++)
                headA = headA->next;
        }
        if (b_l > a_l)
        {
            for (int i = 0; i < b_l - a_l; i++)
                headB = headB->next;
        }

        while (headA && headB)
        {
            if (headA == headB)
                return headA;
            headA = headA->next;
            headB = headB->next;
        }
        return nullptr;
    }

    /**
     * Time: O(N), Space: O(N)
     * 解題流程: 利用unordered_set將經過的ListNode記錄下來
     * 接著再traverse另外一個ListNode
     */
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        unordered_set<ListNode *> set;
        ListNode *A = headA;
        while (A)
        {
            set.insert(A);
            A = A->next;
        }
        while (headB)
        {
            if (set.count(headB))
                return headB;
            headB = headB->next;
        }
        return nullptr;
    }
};
// @lc code=end
