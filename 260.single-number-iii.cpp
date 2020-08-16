/*
 * @lc app=leetcode id=260 lang=cpp
 *
 * [260] Single Number III
 */

// @lc code=start
class Solution
{
    /**
     * Time: O(N), Space: O(1)
     * 解題流程: 想利用Probelm136的方法解
     * ex: 1,2,1,3,2,5
     * Step1. 先全部取XOR, 會得到剩餘兩個數字的XOR
     * 3^5 = 110
     * 
     * Step2. 想要分離出兩個數字
     * 0 1 1
     * 1 0 1
     * -----
     * 1 1 0
     * 找到從右到左第一個不為0的位置當成mask
     * mask = 0 1 0, 可以利用這個mask將兩個數字分開, 
     * 
     * 0 0 1
     * 0 1 0
     * 0 0 1
     * 0 1 0
     * 0 1 1
     * 1 0 1
     * 把和mask取&為0的為一個數字
     * 不為0的為另一邊數字
     * mask會將第二位為0的一起取XOR, 不為0的一起去XOR
     * 這樣那兩個數字一定會被分配到兩邊, 其他不管分到哪邊都一定會被XOR變成0
     */
public:
    vector<int> singleNumber(vector<int> &nums)
    {
        int a = 0;
        // Step1
        for (auto &v : nums)
            a ^= v;

        int mask = 1;
        while ((a & mask) == 0)
            mask = mask << 1;

        vector<int> res(2, 0);
        for (auto &v : nums)
        {
            if ((mask & v) == 0)
                res[0] ^= v;
            else
                res[1] ^= v;
        }
        return res;
    }
};
// @lc code=end
