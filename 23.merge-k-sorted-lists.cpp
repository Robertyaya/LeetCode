/*
 * @lc app=leetcode id=23 lang=cpp
 *
 * [23] Merge k Sorted Lists
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
     * Total node is the size of N
     * Time: O(NlogN), Space: O(N)
     * 解題流程: 此題利用priority queue, 始終讓小的node會先出來, 當出來之後再將下一個放到priority queue中
     * priority_queue在維護一個heap, max_heap or min_heap
     * top: O(1)
     * push: O(logN)
     * pop: O(logN)
     */
public:
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        if (lists.empty())
            return nullptr;

        // same as greater, 小的會先從priority queue中出來, min_heap
        auto cmp = [](auto a, auto b) {
            return a->val > b->val;
        };
        // priority_queue< TYPE, Container, Compare function>
        priority_queue<ListNode *, vector<ListNode *>, decltype(cmp)> q(cmp);

        // O(logN), 先將每一列的第一個node放入queue中
        for (int i = 0; i < lists.size(); i++)
        {
            // 這邊是要handle有些ListNode* 為nullptr, [[], [1,2]]這種情況
            if (lists[i])
                q.push(lists[i]); // O(logN)
        }

        ListNode *res = new ListNode(-1);
        ListNode *runner = res;

        // O(NlogN)
        while (!q.empty())
        {
            // O(1) in priority queue
            auto n = q.top(); // 取出最小的那個node->val
            q.pop();          // O(logN)
            runner->next = new ListNode(n->val);
            runner = runner->next;

            // 將下一個node放入priority_queue中
            if (n->next)
                q.push(n->next);
        }
        return res->next;
    }
};
// @lc code=end
