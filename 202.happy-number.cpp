/*
 * @lc app=leetcode id=202 lang=cpp
 *
 * [202] Happy Number
 */

// @lc code=start
class Solution
{
public:
    bool isHappy(int n)
    {
        unordered_set<int> set;
        while (n != 1)
        {
            set.insert(n);
            int value = 0;
            while (n != 0)
            {
                // 提取每一位數的數字
                int v = n % 10;
                n /= 10;
                value += (v * v);
            }
            n = value;
            // 確認是否曾經出現過, 若有則代表出現cycle
            if (set.count(n))
                return false;
        }
        return true;
    }
};
// @lc code=end
