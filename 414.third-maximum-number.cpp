/*
 * @lc app=leetcode id=414 lang=cpp
 *
 * [414] Third Maximum Number
 */

// @lc code=start
class Solution
{
    /**
     * Time: O(NlogN), Space: O(N)
     */
public:
    int thirdMax(vector<int> &nums)
    {
        set<int> set;
        for (auto v : nums)
        {
            // 先放進去再刪除, 這樣可以確保永遠刪除的數字都是第四大的
            // set中不允許重複數字，因此剛好只會變成一個
            set.insert(v);
            if (set.size() > 3)
                set.erase(set.begin());
        }

        if (set.size() < 3)
            return *set.rbegin();
        return *set.begin();
    }
    /**
 * Time: O(N), Space: O(1)
 */
    int thirdMax(vector<int> &nums)
    {
        long first = LONG_MIN;
        long second = LONG_MIN;
        long third = LONG_MIN;
        for (auto v : nums)
        {
            // 代表所有數字往上移一格
            if (v > first)
            {
                third = second;
                second = first;
                first = v;
            }
            else if (v > second && v < first)
            {
                third = second;
                second = v;
            }
            else if (v > third && v < second)
                third = v;
        }

        if (third == LONG_MIN)
            return first;
        return third;
    }
};
// @lc code=end
