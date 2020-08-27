/*
 * @lc app=leetcode id=324 lang=cpp
 *
 * [324] Wiggle Sort II
 */

// @lc code=start
class Solution
{
    /**
     * Time: O(NlogN), Space: O(N)
     * 解題流程: 先sorting完後切兩半, 
     * 關鍵在於切兩邊時
     * [1,2,3,4,5]
     *    <-l <-r  關鍵在於l跟r起始一定要從大到小, 從小到大可以會重複數字
     */
public:
    void wiggleSort(vector<int> &nums)
    {
        vector<int> copy = nums;
        sort(copy.begin(), copy.end());

        // 這邊有個+1, 為了讓奇數時最後一個數字是l
        int l = (nums.size() + 1) / 2 - 1;
        int r = nums.size() - 1;
        for (int i = 0; i < nums.size(); i++)
        {
            if (i % 2 == 1)
                nums[i] = copy[r--];
            else
                nums[i] = copy[l--];
        }
    }
};
// @lc code=end
