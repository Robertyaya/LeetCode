/*
 * @lc app=leetcode id=49 lang=cpp
 *
 * [49] Group Anagrams
 */

// @lc code=start
class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        // key: str, value: index in strs
        unordered_map<string, int> map;
        vector<vector<string>> res;
        for (int i = 0; i < strs.size(); i++)
        {
            string str = strs[i];
            sort(str.begin(), str.end());
            if (map.count(str))
                res[map[str]].push_back(strs[i]);
            else
            {
                vector<string> temp;
                temp.push_back(strs[i]);
                res.push_back(temp);
                map[str] = res.size() - 1;
            }
        }
        return res;
    }
};
// @lc code=end
