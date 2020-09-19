/*
 * @lc app=leetcode id=239 lang=cpp
 *
 * [239] Sliding Window Maximum
 */

// @lc code=start
class Solution
{
public:
    /**
 * Time: O(N), Space: O(N)
 * 利用deque保存index
 */
    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {
        vector<int> vec;
        deque<int> q;
        for (int i = 0; i < nums.size(); i++)
        {
            // 當第一個數字為i-k是, 代表此數字已經會超過sliding window會pop出去了
            if (!q.empty() && q.front() == i - k)
                q.pop_front();

            // 把比欲進來數字還小的全部拿掉, 因為不會是max_value
            while (!q.empty() && nums[q.back()] < nums[i])
                q.pop_back();

            q.push_back(i);

            // 當超過k個數字之後, 在deque中第一個數字一定就是最大的value index
            if (i >= k - 1)
                vec.push_back(nums[q.front()]);
        }
        return vec;
    }
    /**
 * Time: O(NlogN), Space: O(N)
 */
    // vector<int> maxSlidingWindow(vector<int> &nums, int k)
    // {
    //     vector<int> res;
    //     multiset<int> set; // 裡面會排序, 最大數字在最後面
    //     // O(NlogN)
    //     for (int i = 0; i < nums.size(); i++)
    //     {
    //         set.insert(nums[i]);
    //         if (set.size() == k)
    //         {
    //             res.push_back(*set.rbegin());
    //             // 如果直接erase數字的話, 會直接將所有重複數字消除
    //             set.erase(set.find(nums[i - k + 1]));
    //         }
    //     }
    //     return res;
    // }
};
// @lc code=end
