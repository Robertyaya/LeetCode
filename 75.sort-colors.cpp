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
            int index = i;
            while (index >= 1 && nums[index] < nums[index - 1])
            {
                swap(nums[index], nums[index - 1]);
                index--;
            }
        }
    }
};
// @lc code=end

/**
* Two pass algorithm
* Time: O(N), Space: O(N)
* 解題流程: 此處要sorting in in-place, 利用count-sorting, 先traverse一遍, 過程中紀錄各別元素出現的個數, 再traverse第二遍, 有了數字以及出現的個數, 直接修改input nums
*/
void sortColors(vector<int> &nums)
{
    vector<int> vec(3, 0);
    for (auto v : nums)
        vec[v]++;

    int index = 0;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < vec[i]; j++)
        {
            nums[index] = i;
            index++;
        }
    }
}
