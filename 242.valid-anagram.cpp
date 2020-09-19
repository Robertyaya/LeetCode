/*
 * @lc app=leetcode id=242 lang=cpp
 *
 * [242] Valid Anagram
 */

// @lc code=start
class Solution
{
    /**
     * Time: O(N), Space: O(N)
     */
public:
    bool isAnagram(string s, string t)
    {
        if (s.size() != t.size())
            return false;

        unordered_map<char, int> map;
        for (int i = 0; i < s.size(); i++)
            map[s[i]]++;
        for (int i = 0; i < t.size(); i++)
        {
            if (!map.count(t[i]) || map[t[i]] == 0)
                return false;
            else
                map[t[i]]--;
        }
        return true;
    }
};
// @lc code=end
