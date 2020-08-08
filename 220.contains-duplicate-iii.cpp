/*
 * @lc app=leetcode id=220 lang=cpp
 *
 * [220] Contains Duplicate III
 */

// @lc code=start
class Solution
{
    /**
     * Time: O(NlogN), Space: O(N)
     * 解題流程: 利用multiset維護一個sliding window, size為k+1(因為這此範圍內才需要考慮數值相差是否小於t)
     * 因為數值中會有重複, 因此利用multiset
     * 當set滿了, 則需要erase掉nums中sliding window最前面的數字
     * 如果要insert進去, 因為set中為排序過的數字
     * 因此insert進去只需要檢查兩邊的數字是否有滿足小於t的這個條件, 如果有則直接return true
     * 
     */
public:
    bool containsNearbyAlmostDuplicate(vector<int> &nums, int k, int t)
    {
        // Maintain the sliding window
        multiset<long long> set;
        // O(N)
        for (int i = 0; i < nums.size(); i++)
        {
            // 當set滿了, 則需要erase掉原先最前面的那個數字
            if (set.size() == k + 1)
                set.erase(set.find(nums[i - k - 1])); // O(logN)

            auto iter = set.insert(nums[i]); // O(logN)

            // prev(iter)為insert進去的前一個數字
            if (iter != set.begin() && abs(*iter - *prev(iter)) <= t)
                return true;

            // next(iter)為insert進去的下一個數字, 因為set.end是指向"最後一個數字"的"下一個"
            // 因此我們這邊要判斷iter是否為最後一個數字不能直接=set.end需要next(iter)是否為end
            if (next(iter) != set.end() && abs(*iter - *next(iter)) <= t)
                return true;
        }
        return false;
    }
};
// @lc code=end
