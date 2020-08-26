/*
 * @lc app=leetcode id=300 lang=cpp
 *
 * [300] Longest Increasing Subsequence
 */

// @lc code=start
class Solution
{
    /**
     * Time: O(NlogN), Space: O(N)
     * 解題流程: lower_bound返回大於等於nums[i]的位置
     * 如果無則會返回end()
     * res所存的數字不一定會和真實的LIS相同, 只是size會相同
     * 類似於dp
     * [1,2,7,8,3,4,5,9,0]
        1 -> [1]
        2 -> [1,2]
        7 -> [1,2,7]
        8 -> [1,2,7,8]
        3 -> [1,2,3,8]  // we replaced 7 with 3, since for the longest sequence we need only the last number and 1,2,3 is our new shorter sequence
        4 -> [1,2,3,4] // we replaced 8 with 4, since the max len is the same but 4 has more chances for longer sequence
        5 -> [1,2,3,4,5]
        9 -> [1,2,3,4,5,9]
        0 -> [0,2,3,4,5,9] // we replaced 1 with 0, so that it can become a new sequence
     */
public:
    int lengthOfLIS(vector<int> &nums)
    {
        vector<int> res;
        for (int i = 0; i < nums.size(); i++)
        {
            // More easy method, use the STL lower_bound
            // auto it = lower_bound(res.begin(), res.end(), nums[i]);
            // if (it == res.end())
            //     res.push_back(nums[i]);
            // else
            //     *it = nums[i];

            // Use Binary search to find the lower bound
            int l = 0;
            int r = res.size();
            while (l < r)
            {
                int mid = l + (r - l) / 2;
                if (res[mid] < nums[i])
                    l = mid + 1;
                else
                    r = mid;
            }

            if (l == res.size())
                res.push_back(nums[i]);
            else
                res[l] = nums[i];
        }
        return res.size();
    }

    /**
     * Time: O(N^2), Space: O(N)
     * 解題流程: dp[i]紀錄的是到此長度最長的substring
     * 每次都要從頭搜一次, 如果nums[i] > nums[j]代表可以納入此substring中， 選一個最大的放入dp[i]
     * res用來記錄從頭到尾最長的substring 
     */
    // int lengthOfLIS(vector<int> &nums)
    // {
    //     if (nums.empty())
    //         return 0;

    //     vector<int> dp(nums.size(), 0);
    //     dp[0] = 1;
    //     int res = 1; // 紀錄從頭到尾最長的substring
    //     for (int i = 1; i < nums.size(); i++)
    //     {
    //         int max_dp = 0;
    //         for (int j = 0; j < i; j++)
    //         {
    //             if (nums[i] > nums[j])
    //                 max_dp = max(max_dp, dp[j]);
    //         }
    //         dp[i] = max_dp + 1;
    //         res = max(res, dp[i]);
    //     }
    //     return res;
    // }
};
// @lc code=end
