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
        // Build the target map
        unordered_map<char, int> map;
        for (int i = 0; i < t.size(); i++)
            map[t[i]]++;

        int min_length = INT_MAX; // 紀錄min_length
        int min_index = -1;       // 紀錄min_length的起始點
        int count = 0;
        int left = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (map.count(s[i]))
            {
                map[s[i]]--;
                if (map[s[i]] >= 0) // 代表此字元為滿足target char
                    count++;
            }

            while (count == t.size()) // 目前substring都滿足target string, 做sliding window
            {
                // Update min_length
                if (min_length > i - left + 1)
                {
                    min_length = i - left + 1;
                    min_index = left;
                }
                if (map.count(s[left]))
                {
                    map[s[left]]++;
                    if (map[s[left]] > 0) // 代表此時左邊扣掉的是滿足target string的, 因此要重新開始找
                        count--;
                }
                left++;
            }
        }

        if (min_index < 0)
            return "";
        return s.substr(min_index, min_length);
    }
};
// @lc code=end
