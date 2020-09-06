/*
 * @lc app=leetcode id=496 lang=cpp
 *
 * [496] Next Greater Element I
 */

// @lc code=start
class Solution
{
    /**
     * Time: O(N), Space: O(N)
     * 解題流程: 利用unordered_map去紀錄nums2每一個元素中， 最大的下一個元素是什麼
     * ex: nums2 = [1,3,4,2]
     * map: 1->3
     *      3->4
     *      4-> -1
     *      2-> -1
     * 因此關鍵在於如何快速建立出這個map
     * 此處利用stack來找出下一個最大的數字是多少
     * ex:
     * sta: [1] 3 ->3>1, 因此map[1] = 3, pop 1, push 3
     *      [3] 4 ->4>3, 因此map[3] = 4, pop 3, push 4
     *      [4] 2 ->4>2, 因此sta.push(2)
     *      [4,2]
     * 
     */
public:
    vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
    {
        unordered_map<int, int> map;
        stack<int> sta;
        for (int i = 0; i < nums2.size(); i++)
        {
            if (sta.empty())
            {
                sta.push(nums2[i]);
                continue;
            }

            int value = sta.top();
            if (nums2[i] < sta.top())
            {
                sta.push(nums2[i]);
            }
            else
            {
                while (!sta.empty() && sta.top() < nums2[i])
                {
                    int value = sta.top();
                    map[value] = nums2[i];
                    sta.pop();
                }
                sta.push(nums2[i]);
            }
        }

        vector<int> res;
        for (int i = 0; i < nums1.size(); i++)
        {
            if (!map.count(nums1[i]))
                res.push_back(-1);
            else
                res.push_back(map[nums1[i]]);
        }
        return res;
    }
};
// @lc code=end
