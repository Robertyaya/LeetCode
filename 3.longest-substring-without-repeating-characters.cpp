/*
 * @lc app=leetcode id=3 lang=cpp
 *
 * [3] Longest Substring Without Repeating Characters
 */

// @lc code=start
class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        unordered_map<char, int> map;
        int start_index = 0;
        int cur_length = 0;
        int max_length = 0;
        for (int i = 0; i < s.length(); i++)
        {
            if (map.count(s[i]))
            {
                int index = map[s[i]];
                // 維護一個sliding window, 代表的是最長的max_length
                for (int i = start_index; i <= index; i++)
                {
                    map.erase(s[i]);
                    cur_length--;
                }
                start_index = index + 1;
            }
            map[s[i]] = i;
            cur_length++;
            max_length = max(max_length, cur_length);
        }
        return max_length;
    }
};
// @lc code=end
