/*
 * @lc app=leetcode id=60 lang=cpp
 *
 * [60] Permutation Sequence
 */

// @lc code=start
class Solution
{
    /**
     * Time: O(N), Space: O(N)
     * 解題流程: 這題不能用DFS去找出Permutation當找到第k個break出來, 這樣會超時
     * 因此要找規律去直接找出第k個數值
     * ex:
     * n=3
     * 123  
     * 132
     * 213
     * 231
     * 312
     * 321
     * 第一位數字固定時, 後面會有兩位變化2!
     * 第二位數字固定時, 後面指會有一位變化1!
     * ex: 當k=3時
     * k/2! = 1..1
     * 所以就一定是123,132的下一位數字, 代表頭為1的那幾個已經輪完了
     * 因為有餘數1
     * 找出第一位數字後再找第二位數字
     * k update為前一步的餘數
     * 1/1! = 1..0
     * ...
     */
public:
    string getPermutation(int n, int k)
    {
        if (n == 1)
            return "1";

        // 將可用的數字先放到vector裡面, 每次用完一個則erase掉
        // [1,1,2,3] n=3
        vector<int> vec;
        vec.push_back(1);
        for (int i = 1; i <= n; i++)
            vec.push_back(i);

        // 計算1~n-1! save to nums
        vector<int> nums;
        int f = 1;
        nums.push_back(f);
        for (int i = 1; i < n; i++)
        {
            f *= i;
            nums.push_back(f);
        }

        int nums_index = n - 1;
        string output = "";
        while (k >= 1)
        {
            int group_nums = k / nums[nums_index];
            int group_index = k % nums[nums_index];

            if (group_index != 0)
                group_nums++;
            else
                group_index = nums[nums_index];

            output += (to_string(vec[group_nums]));
            vec.erase(vec.begin() + group_nums); // 將用過得數字erase掉, 已經加到output string中了

            // Handle最後一個時的情況
            if (output.size() == n - 1)
            {
                output += (to_string(vec[1]));
                break;
            }

            nums_index--;
            k = group_index;
        }
        return output;
    }
};
// @lc code=end
