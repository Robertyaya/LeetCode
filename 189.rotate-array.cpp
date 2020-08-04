/*
 * @lc app=leetcode id=189 lang=cpp
 *
 * [189] Rotate Array
 */

// @lc code=start
class Solution
{
    /**
     * Time: O(N), Space: O(1)
     * 解題流程: 
     * ex:
     * 1 2 3 4 5 6 7  k=3
     * [4 3 2 1] [7 6 5] 各別reverse
     * 再全部一起reverse
     * 5 6 7 1 2 3 4 就是答案 
     */
public:
    void rotate(vector<int> &nums, int k)
    {
        k = k % nums.size();
        reverse(nums.begin(), nums.begin() + nums.size() - k);
        reverse(nums.begin() + nums.size() - k, nums.end());
        reverse(nums.begin(), nums.end());
    }
    /**
     * Time: O(N), Space: O(N)
     */
    void rotate(vector<int> &nums, int k)
    {
        k = k % nums.size();

        int l = 0;
        int r = nums.size() - k;
        vector<int> temp;

        // 先將前面數字記錄下來 O(N)
        for (int i = 0; i < r; i++)
            temp.push_back(nums[i]);

        // 覆寫前面數字 O(N)
        while (r < nums.size())
        {
            nums[l] = nums[r];
            l++;
            r++;
        }

        // 把前面記錄下來的填回去 O(N)
        int i = 0;
        for (auto v : temp)
            nums[k++] = v;
    }
    /**
 * Time: O(N^2), Space: O(1)
 */
    void rotate(vector<int> &nums, int k)
    {
        k = k % nums.size();
        int i = 0;
        // O(N)
        while (i < nums.size() - k)
        {
            nums.push_back(nums[0]);
            // O(N)
            nums.erase(nums.begin());
            i++;
        }
    }
};
// @lc code=end
