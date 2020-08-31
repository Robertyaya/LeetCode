/*
 * @lc app=leetcode id=28 lang=cpp
 *
 * [28] Implement strStr()
 */

// @lc code=start
class Solution
{
    /**
     * Naive method
     * Time: O(M*N), Space: O(1)
     */
public:
    int strStr(string haystack, string needle)
    {
        unordered_set<string> set;
        set.insert(needle);
        int a = haystack.size();
        int b = needle.size();
        for (int i = 0; i <= a - b; i++)
        {
            string str = haystack.substr(i, needle.size());
            if (set.count(str))
                return i;
        }
        return haystack == needle ? 0 : -1;
    }

    /**
     * Rabin-Karp Algorithm
     * Time: O(N), Space: O(1)
     * 解題流程: 
     * [a b c d] e f g ->text
     * [a b c d] ->pattern
     * 先計算pattern的hash value以及text的第一組hash value
     * Pattern的hash value就是target value
     * 
     * ex: 
     * [a,b,c,d]
     * ax^3 + bx^2 + c^x + d
     * 
     * 接著開始做rooling hash
     * [a,b,c,d] e f g -> a [b c d e] f g -> a b [c d e f] g .....
     * 每次update要扣掉頭加上尾
     */
    int strStr(string haystack, string needle)
    {
        long long x = 11;
        long long mod = 1000000007;

        int m = haystack.size();
        int n = needle.size();
        long long haystack_hash = 0;
        long long needle_hash = 0;
        long long h = 1;

        // 後面在做rolling hash時, 將頭刪掉時要扣除, 因此這邊先算好
        // ex: ax2+bx+c, 移動到下一個要扣掉ax2, 這邊就是先將x2算好
        for (int i = 0; i < n - 1; i++)
        {
            h = (h * x) % mod;
        }

        for (int i = 0; i < n; i++)
        {
            haystack_hash = (haystack_hash * x + haystack[i]) % mod;
            needle_hash = (needle_hash * x + needle[i]) % mod;
        }

        for (int i = 0; i <= m - n; i++)
        {
            if (haystack_hash == needle_hash)
            {
                // 一個一個比對， 因為有可能conflict
                bool success = true;
                for (int j = 0; j < n; j++)
                {
                    if (haystack[i + j] != needle[j])
                    {
                        success = false;
                        break;
                    }
                }
                if (success)
                    return i;
            }

            // Update haystack_hash
            if (i < m - n)
            {
                haystack_hash = ((haystack_hash - haystack[i] * h) * x + haystack[i + n]) % mod;

                // 上面因為有相減, 因此hash value可能會小於0, 這邊讓hash value一定會大於0
                if (haystack_hash < 0)
                    haystack_hash += mod;
            }
        }
        return -1;
    }
};
// @lc code=end
