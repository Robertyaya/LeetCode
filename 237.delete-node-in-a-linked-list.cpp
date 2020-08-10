/*
 * @lc app=leetcode id=237 lang=cpp
 *
 * [237] Delete Node in a Linked List
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
     * Time: O(1), Space: O(1)
     * 解題流程：此題只給出要remove掉的node
     * 將下一個node的數值assign到remove掉的node
     * 然後remove下一個node
     */
public:
    void deleteNode(ListNode *node)
    {
        node->val = node->next->val;
        node->next = node->next->next;
    }
};
// @lc code=end
