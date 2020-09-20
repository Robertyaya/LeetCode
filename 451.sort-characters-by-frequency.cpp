/*
 * @lc app=leetcode id=451 lang=cpp
 *
 * [451] Sort Characters By Frequency
 */

// @lc code=start
class Solution
{
    /**
     * Time: O(NlogN), Space: O(N)
     */
public:
    string frequencySort(string s)
    {
        // 紀錄char出現次數, O(N)
        unordered_map<char, int> map;
        for (int i = 0; i < s.size(); i++)
            map[s[i]]++;

        // Max heap, 利用heap使次數最大的char會先出來, O(NlogN)
        auto cmp = [](auto a, auto b) {
            return a.second < b.second;
        };
        priority_queue<pair<char, int>, vector<pair<char, int>>, decltype(cmp)> que(cmp);
        for (auto v : map)
            que.push({v.first, v.second});

        string res;
        // O(NlogN)
        while (!que.empty())
        {
            auto v = que.top();
            que.pop(); // O(logN)
            for (int i = 0; i < v.second; i++)
                res += v.first;
        }
        return res;
    }
};
// @lc code=end
