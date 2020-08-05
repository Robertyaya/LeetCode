/*
 * @lc app=leetcode id=205 lang=cpp
 *
 * [205] Isomorphic Strings
 */

// @lc code=start
class Solution
{
public:
    /**
 * Time: O(N), Space: O(N)
 * 解題流程: 利用map將各自出現過的char和其index記錄下來, 確認每一char是否出現過以及出現的index是否符合, 其中index故意多+1, 因為hashmap的初始值為0, 因此會和index 0搞相同, 因此故意讓全部char的index都往前一格, 這樣就不會和初始值的0衝突
 */
    bool isIsomorphic(string s, string t)
    {
        unordered_map<char, int> map_s;
        unordered_map<char, int> map_t;
        for (int k = 0; k < s.length(); k++)
        {
            // 確認current char是否出現過
            if (map_s[s[k]] != map_t[t[k]])
                return false;
            map_s[s[k]] = k + 1;
            map_t[t[k]] = k + 1;
        }
        return true;
    }
};
// @lc code=end
