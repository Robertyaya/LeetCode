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
    /**
     * Time: O(N), Space: O(1)
     * 解題流程: 利用unordered_set將經過的ListNode記錄下來
     * 接著再traverse另外一個ListNode
     */
public:
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
    /**
 * Time: O(N^2), Space: O(1)
 */
    // ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    // {
    //     ListNode *A;
    //     ListNode *B;
    //     while (headA && headB)
    //     {
    //         A = headA;
    //         B = headB;
    //         while (B)
    //         {
    //             if (A == B)
    //                 return A;
    //             B = B->next;
    //         }
    //         headA = headA->next;
    //     }
    //     return nullptr;
    // }
};
// @lc code=end
