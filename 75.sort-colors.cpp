/*
 * @lc app=leetcode id=75 lang=cpp
 *
 * [75] Sort Colors
 */

// @lc code=start
class Solution
{
public:
    /**
 * One pass algorithm
 * Time: O(N), Space: O(1)
 * 解題流程: 因為要in-place, 且space要為constant, 因此利用swap元素的方式
 * 如果current比previous小, 則交換, 直到後面的大於前面的, 每次這樣做就能確保一定會從小排到大
 */
    void sortColors(vector<int> &nums)
    {
        for (int i = 1; i < nums.size(); i++)
        {
            int cur = i;
            while (nums[cur] < nums[cur - 1])
            {
                swap(nums[cur], nums[cur - 1]);
                cur--;
                if (cur == 0)
                    break;
            }
        }
    }
    /**
* Two pass algorithm
* Time: O(N), Space: O(N)
* 解題流程: 此處要sorting in in-place, 利用count-sorting, 先traverse一遍, 過程中紀錄各別元素出現的個數, 再traverse第二遍, 有了數字以及出現的個數, 直接修改input nums
*/
    void sortColors(vector<int> &nums)
    {
        vector<int> count;
        count.resize(3);
        // O(N)
        for (auto v : nums)
            count[v]++;

        int index = 0;
        int value = 0;
        for (auto v : count)
        {
            int num = v;
            while (num > 0)
            {
                nums[index] = value;
                num--;
                index++;
            }
            value++;
        }
    }
};
// @lc code=end
