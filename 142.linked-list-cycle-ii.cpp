/*
 * @lc app=leetcode id=142 lang=cpp
 *
 * [142] Linked List Cycle II
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
     * 解題流程: 這邊要利用到快慢指針在linkedlist一個性質
     * 如果今天linkedlist為完整一個圓, 也就是相交點在head的位置
     * 那利用快慢指針跑的時候, 兩個指針相遇點一定就是圓的相交處
     * 那如果今天要走兩個node才到圓的相交點
     * 那快慢指針的相遇位置就會是距離相交點前兩個node
     * 因此當fast==slow後, 開始迭代原本的head的位置和slow位置直到兩個相遇, 相遇後那點就是圓的相焦點
     */
public:
    ListNode *detectCycle(ListNode *head)
    {
        if (!head || !head->next)
            return nullptr;

        ListNode *slow = head;
        ListNode *fast = head;
        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;

            // 兩個相遇後, 開始找相交點
            if (fast == slow)
            {
                while (head != slow)
                {
                    head = head->next;
                    slow = slow->next;
                }
                return head;
            }
        }

        return nullptr;
    }
    /**
     * Time: O(N), Space: O(N)
     */
    // ListNode *detectCycle(ListNode *head)
    // {
    //     if (!head || !head->next)
    //         return nullptr;

    //     unordered_set<ListNode *> set;
    //     ListNode *node = head;
    //     while (node)
    //     {
    //         if (set.count(node))
    //         {
    //             return node;
    //         }
    //         set.insert(node);
    //         node = node->next;
    //     }
    //     return nullptr;
    // }
};
// @lc code=end
