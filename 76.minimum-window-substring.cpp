/*
 * @lc app=leetcode id=76 lang=cpp
 *
 * [76] Minimum Window Substring
 */
// ex: S=ADBANC, T=ABC
// @lc code=start
class Solution
{
    /**
     * N is the size of stirng s and M is the size of string t
     * Time: O(N+M), Space: O(M)
     * 解題流程: 
     * 1. 先建立stirng t的map, value代表字元的出現次數
     * 2. traverse string s, 過程中如果遇到的字元有出現在map裡面, 則將其次數--
     * 如果>=0 代表string 的char為出現在string t中的字元, 因此將count++
     * 當count==t.size時, 代表此時t所有char都有出現在目前的window裡面
     * 則進入while迴圈update min_length
     * 並縮減左邊邊界
     * 如果縮減左邊邊界有扣到string t的char, 則代表此時還沒matching, count--
     * 從新繼續往右擴展
     * 
     * 整體思路就是先往右擴展, 找到match的之後開始往左縮小, 縮小當扣到target char時則繼續往右擴展, 呈現一個sliding window
     */
public:
    string minWindow(string s, string t)
    {
        // Build the target map<char, 出現的次數>
        unordered_map<char, int> map;
        for (int i = 0; i < t.size(); i++)
            map[t[i]]++;

        int count = 0;
        int min_length = INT_MAX;
        int left = 0;
        string res;
        for (int i = 0; i < s.size(); i++)
        {
            // The char in the target map
            if (map.count(s[i]))
            {
                map[s[i]]--;
                // >=0代表此時出現的字母都有出現在target string裡面
                if (map[s[i]] >= 0)
                    count++;
            }

            // 已經找到滿足target的substring, count == t.size()
            while (count == t.size())
            {
                // Update min_length
                if (min_length > i - left + 1)
                {
                    min_length = i - left + 1;
                    res = s.substr(left, min_length);
                }
                // 縮減左邊的邊界
                if (map.count(s[left])) // 為target char
                {
                    map[s[left]]++;
                    if (map[s[left]] > 0)
                        count--;
                }
                // 縮短左邊邊界, 如果扣掉的不是target char, 則繼續縮小, 反之如果扣掉的是target char, 則停止縮小, 開始往右繼續找
                left++;
            }
        }
        return res;
    }
};
// @lc code=end
