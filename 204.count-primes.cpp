/*
 * @lc app=leetcode id=204 lang=cpp
 *
 * [204] Count Primes
 */

// @lc code=start
class Solution
{
    /**
     * Time: O(N), Space: O(N)
     * 解題流程: 利用sieve of Eratosthenes 
     * 先initial size為n的vector
     * 從2開始, 將其倍數全部填為false, 因為不可能為prime nums
     * 接著到3, 同上做法, 將其倍數填為false, 因為不可能為prime numss
     * 過程中如果i為true, 代表其一定為prime num, 因為如果不是prime num, 在前面的數字填其倍數一定會被填為false, 但沒有就代表一定是prime num, 因此res++
     * 
     */
public:
    int countPrimes(int n)
    {
        vector<bool> prime(n, true);
        int res = 0;
        for (int i = 2; i < n; i++)
        {
            if (!prime[i])
                continue;
            // 代表current i為prime num, 不然在前面的數字填倍數時會被填為false
            res++;

            // j代表的是i的倍數, 將i所有的倍數小於n填為false
            for (int j = 2; i * j < n; j++)
                prime[i * j] = false;
        }
        return res;
    }
};
// @lc code=end
