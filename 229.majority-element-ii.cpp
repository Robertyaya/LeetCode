/*
 * @lc app=leetcode id=229 lang=cpp
 *
 * [229] Majority Element II
 */

// @lc code=start
class Solution
{
    /**
     * Time: O(N), Space: O(1)
     * 解題流程: 此題要求linear time且space為O(1), 因此不能用hash map， 只能用Moore-Voting's Algorithm (problem 169)
     * 題目為找出大於n/3的數字, 最多就是兩個, 如果有3個數字大於n/3, 那就會超過nums的size, 產生矛盾, 因此不會超過2個答案
     * 第一個for迴圈先利用Moore-voting找出兩個candidate a and b, 
     * 第二個for迴圈則是根據這兩個candidate去統計真實出現次數是否有滿足題目要求的majority element
     */
public:
    vector<int> majorityElement(vector<int> &nums)
    {
        int a;
        int b;
        int count_a = 0;
        int count_b = 0;
        vector<int> res;
        // O(N)
        for (auto v : nums)
        {
            if (v == a)
                count_a++;
            else if (v == b)
                count_b++;
            else if (count_a == 0) // 更換candidate
            {
                a = v;
                count_a++;
            }
            else if (count_b == 0)
            {
                b = v;
                count_b++;
            }
            else
            {
                count_a--;
                count_b--;
            }
        }

        count_a = 0;
        count_b = 0;
        // O(N)
        for (auto v : nums)
        {
            if (v == a)
                count_a++;
            if (v == b)
                count_b++;
        }

        if (count_a > nums.size() / 3)
            res.push_back(a);
        if (count_b > nums.size() / 3 && a != b)
            res.push_back(b);
        return res;
    }
};
// @lc code=end
