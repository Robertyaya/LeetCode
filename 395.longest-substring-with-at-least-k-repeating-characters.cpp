/*
 * @lc app=leetcode id=395 lang=cpp
 *
 * [395] Longest Substring with At Least K Repeating Characters
 */

// @lc code=start
class Solution
{
    /**
     * Divide and Conquer
     */
public:
    int longestSubstring(string s, int k)
    {
        if (s.length() < k)
            return 0;

        // 統計各別char出現的次數
        unordered_map<char, int> map;
        for (int i = 0; i < s.length(); i++)
            map[s[i]]++;

        int length = 0;
        int max_length = 0;
        // 為了記錄此時的string是否有出現不滿足k的情況, 有的話則false, 無則代表整段都是滿足的, 因此最大subsring就是自己本身

        bool flag = true;
        // 如果char出現的次數小於k則substring一定不能包含此char, 因此可以把此char當成分割線, 在此分割線以外的"可能"滿足都>=k也有可能不滿足, 但可以提取出substring再重新丟回function判斷
        for (int i = 0; i < s.length(); i++)
        {
            // 計算substring的長度
            if (map[s[i]] >= k)
                length++;
            else // 遇到分割符
            {
                // substring重新recursive下去, update max_length
                max_length = max(longestSubstring(s.substr(i - length, length), k), max_length);
                length = 0;
                flag = false;
            }
        }

        // flag為true, 代表此時整段都滿足的, 因此max_legnth則為自己本身, 反之則需再做一次recursive判斷
        return flag ? s.length() : max(max_length, longestSubstring(s.substr(s.length() - length, length), k));
    }
};
// @lc code=end
