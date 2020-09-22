/*
 * @lc app=leetcode id=532 lang=cpp
 *
 * [532] K-diff Pairs in an Array
 */

// @lc code=start
class Solution
{
public:
    /**
 * Time: O(NlogN), Space: O(N)
 */
    int findPairs(vector<int> &nums, int k)
    {
        if (k < 0)
            return 0;
        // 紀錄個別數字出現次數, 為了handle k=0的情況
        unordered_map<int, int> map;
        for (auto v : nums)
            map[v]++;

        // 先sorting, O(NlogN)
        sort(nums.begin(), nums.end());

        int res = 0;
        // Traverse map
        for (auto v : map)
        {
            if (k == 0 && map[v.first] >= 2)
                res++;
            if (k != 0 && map.count(v.first + k))
                res++;
        }

        return res;
    }
    /**
 * Time: O(N), Space: O(N)
 */
    // int findPairs(vector<int> &nums, int k)
    // {
    //     // 距離不為負
    //     if (k < 0)
    //         return 0;

    //     // 用來記錄各別數字出現個數
    //     unordered_map<int, int> map;
    //     // 用來記錄已使用過數字
    //     unordered_set<int> set;
    //     for (auto v : nums)
    //     {
    //         set.insert(v);
    //         map[v]++;
    //     }

    //     int res = 0;
    //     for (auto v : nums)
    //     {
    //         if (set.count(v) && map.count(v - k))
    //         {
    //             // 當k==0時, 自己的個數要大於等於2
    //             if (k == 0 && map[v] < 2)
    //                 continue;

    //             // 刪掉已使用過的數字
    //             set.erase(v);
    //             res++;
    //         }
    //     }
    //     return res;
    // }
};
// @lc code=end
