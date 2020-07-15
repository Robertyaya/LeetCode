/*
 * @lc app=leetcode id=148 lang=cpp
 *
 * [148] Sort List
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
public:
    /**
     * 
 * Merge sort
 * Time: O(NlogN), Space: O(logN) (System stack)
 * 解題流程: 類似這種linkedlist排序問題, 因為沒辦法直接取得index, 因此利用merge sort這種交換方式的sorting可以有效解決
 * 1. 首先第一個問題是如何每次都找到那範圍內的mid_node, 這邊利用快慢指針, 慢指針會指向mid_node, 而利用快指針當作截止條件
 * 2. pre目的是每次進入sort_list這個function裡面, 我們都會將當下這個範圍內的linkedlist分成兩段,而第一段的最後一個應該要指向null
 * 因此pre目的就是將第一段linkedlist的最後一個指向null
 * 3. 持續recursive下去直到到達一個node情況則return開始merge
 * 4. 在merge過程中, 將兩段linkedlist接在一起之後return, 整體演算法參考一般merge sort過程
 * 
 *  
 */
    ListNode *merge(ListNode *left, ListNode *right)
    {
        ListNode *dummy = new ListNode(-1);
        ListNode *cur = dummy;
        while (left && right)
        {
            if (left->val <= right->val)
            {
                cur->next = left;
                left = left->next;
            }
            else
            {
                cur->next = right;
                right = right->next;
            }
            cur = cur->next;
        }

        // 上面條件為兩者要同時滿足, 因此若只剩一個滿足的則在下面這邊處理, 代表還有node還沒被merge
        if (left)
            cur->next = left;
        if (right)
            cur->next = right;

        return dummy->next;
    }
    ListNode *sortList(ListNode *head)
    {
        // 直到只剩下一個node, 如果head為nullptr, 則return nullptr
        if (!head || !head->next)
            return head;

        // 利用快慢指針, 目的是要指到mid node
        ListNode *fast = head;
        ListNode *slow = head; // slow will point to the mid node
        ListNode *pre = head;
        while (fast && fast->next)
        {
            pre = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        // 此處將linkedlist分成兩部分linkedlist後再merge起來, 以head為開頭以及以slow為開頭, 因此head為開頭最後面要接到null
        pre->next = NULL;
        return merge(sortList(head), sortList(slow));
    }
};
// @lc code=end
