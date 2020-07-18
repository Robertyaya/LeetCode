/*
 * @lc app=leetcode id=137 lang=cpp
 *
 * [137] Single Number II
 */

// @lc code=start
class Solution
{
public:
    /**
 * Time: O(N), Space: O(1)
 * 解題流程: 
 * ex: [2,2,3,2]
 * 2: 0 1 0
 * 2: 0 1 0
 * 3: 0 1 1
 * 2: 0 1 0
 * 如果每個數字都3個一組的話, 應該每一位加起來都是3的倍數, 然而不是就是因為有一個是落單的
 * 看第一位: 0+0+1+0 = 1, 1%3 = 1
 * 看第二位: 1+1+1+1 = 1, 4%3 = 1
 * 看第三位: 0+0+0+0 = 0, 0%3 = 0
 * 因此多出來的落單數就是 011->3
 * 因此此題流程就是取出"各位"數字全部相加後mod3, 因為只會有一個落單, 因此數字不是1就是0, 
 * 再將各位返回到正確的位置上
 * ex: 第一位取出後相加取mode, 得出的值就要填到第一位
 * 第二位取出後相加取mode, 得出的值就要填到第二位
 * 依此類推... 
 * 
 * 1. 第一個問題是如何取出"各位"的數值
 * ex: 10010
 * 假設要取出第二位數值, 先右移1位
 * 10010 >> 1 =01001
 * 再和1取AND "&"
 *    01001
 *  & 00001 
 *    ------
 *    00001
 * 就可以得到第二位的數值, 依此類推..
 * 2. 第二個問題是假設我們計算出第二位的數值為1, 那要怎麼"返還"到res上
 * ex: 00001 -> 但此數值代表是第二位, 因此要填到res的第二位上
 * 根據前面右移多少這邊左移回去
 * 00001 << 1 -> 00010
 * 接著假設原本res的數值為 00101
 * 那麼要填到第二位就是和res取OR "|"
 *    00010
 *  | 00101
 * ---------
 *    00111
 */
    int singleNumber(vector<int> &nums)
    {
        if (nums.size() == 1)
            return nums[0];

        int res = 0;

        // 因為int為4bytes, 總共8*4=32bit, 因此數值可能會到32bit, 因此每一位都需要考慮到
        for (int i = 0; i < 32; i++)
        {
            int sum = 0;
            for (auto v : nums)
            {
                sum += (v >> i) & 1;
                sum %= 3;
            }
            res = res | (sum << i);
        }
        return res;
    }
    /**
 * Time: O(N), Space: O(N)
 */
    int singleNumber(vector<int> &nums)
    {
        unordered_map<int, int> map;
        for (auto v : nums)
        {
            if (!map.count(v))
                map[v] = 1;
            else
            {
                map[v]++;
                if (map[v] == 3)
                    map.erase(v);
            }
        }
        int output;
        for (auto v : map)
            output = v.first;
        return output;
    }
};
// @lc code=end
