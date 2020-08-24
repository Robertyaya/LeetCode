/*
 * @lc app=leetcode id=283 lang=cpp
 *
 * [283] Move Zeroes
 */

// @lc code=start
class Solution
{
    /**
     * Time: O(N), Space: O(1)
     */
public:
    void moveZeroes(vector<int> &nums)
    {
        int j = 0;
        int n = nums.size();
        int count = 0;
        for (int i = 0; i < n; i++)
        {
            // 紀錄有多少0
            if (nums[i] == 0)
                count++;
            else // 不是0的話直接從前面填數字過來
            {
                nums[j] = nums[i];
                j++;
            }
        }

        // 上面有紀錄多少0, 直接從後面填過來都為0
        int i = nums.size() - 1;
        while (count != 0)
        {
            nums[i] = 0;
            count--;
            i--;
        }
    }
};
// @lc code=end
