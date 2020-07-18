/*
 * @lc app=leetcode id=169 lang=cpp
 *
 * [169] Majority Element
 */

// @lc code=start
class Solution
{
public:
    /**
 * Moore-Voting's Algorithm
 * Time: O(N), Space: O(1)
 * 解題流程: 從數組中找出"過半數"的數字才能使用
 * 假設有一個數過半數,那同時拿掉一個為過半數的數字, 一個為隨便一個數字, 這樣依然過半數的數字還是會原本那個
 * ex: AAABC
 * A為過半數, 如果同時拿掉A和B
 * AAC
 * A一樣為過半數在這個數組裡面
 * 因此Moore-Voting演算法的精髓就是先假設candidate再過去做驗證
 * count+1代表candidate這時有多一個可以扣掉, count-1代表遇到不同的因此兩個抵銷掉
 * 因此當count=0時代表candidate和不是candidate的數字出現一樣
 * AAABBB這樣的情況
 * 因此這時candidate變得不一定是candidate, 會需要換人當
 * 因此當count == 0, 更換candidate為現在的數字繼續update
 * 最後過半數組一定會是剩下的res
 * 
 */
    int majorityElement(vector<int> &nums)
    {
        int res = nums[0];
        int count = 1;
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] == res)
                count++;
            else
                count--;

            if (count == 0)
            {
                res = nums[i];
                count++;
            }
        }
        return res;
    }
    /**
 * Time: O(N), Space: O(N)
//  */
    int majorityElement(vector<int> &nums)
    {
        if (nums.size() == 1)
            return nums[0];

        unordered_map<int, int> map;
        int major_size = nums.size() / 2;
        for (auto v : nums)
        {
            if (!map.count(v))
                map[v] = 1;
            else
            {
                map[v]++;
                if (map[v] > major_size)
                    return v;
            }
        }
        return -1;
    }
};
// @lc code=end
