/*
 * @lc app=leetcode id=438 lang=cpp
 *
 * [438] Find All Anagrams in a String
 */

// @lc code=start
class Solution
{
    /**
 * Time: O(N), Space: O(1)
 * 解題流程: 此題利用sliding window, 目的是因為這樣就不用重複計算中間已經算過的數值, 只需要扣掉最前面的以及加上最後面的不斷去update, 不用每次都重新計算
 * 建立兩個map一個是p 也就是target map
 * 另外一個則是tranverse s string過程中不斷去update s_map
 * 確認是否和p_map相同， 由於是利用map因此不會管char的順序只管是否存在此char
 * 在建立map的過程中， 之所以要-'a'的原因是直接取s[i]的話會將此char的ASCII放進去, -'a'則是因為我們已確認都是小寫且總共26個字母, 因此扣掉a的ascii 就可將所有char的ascii壓到0~25之間, 這樣我們建立的map就不用建到128, 而是26就好可以省空間
 * 比較s_map == p_map由於size為constant 26, 因此可視為O(1)
 * 
 */
public:
    vector<int> findAnagrams(string s, string p)
    {
        if (p.size() > s.size())
            return {};
        vector<int> s_map(26, 0);
        vector<int> p_map(26, 0);
        for (int i = 0; i < p.size(); i++)
            p_map[p[i] - 'a']++;

        vector<int> res;
        for (int i = 0; i < s.size(); i++)
        {
            s_map[s[i] - 'a']++;
            if (i >= p.size())
                s_map[s[i - p.size()] - 'a']--; // Remove掉sliding window的第一個char

            if (s_map == p_map)
                res.push_back(i - p.size() + 1);
        }
        return res;
    }
};
// @lc code=end
