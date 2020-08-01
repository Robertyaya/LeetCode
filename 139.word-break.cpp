/*
 * @lc app=leetcode id=139 lang=cpp
 *
 * [139] Word Break
 */

// @lc code=start
class Solution
{
    /**
     * DFS + memorization
     * 因為總共執行的時間就是會走過所有"連續"的substring
     * ex: a,b,c 
     * a,b,c,ab,bc,abc (3+2+1)
     * Time: O(N^2), Space: O(N)
     * 解題流程: 此題利用DFS找出所有可能, 並在過程中將計算過的數值記錄下來
     * memo[i]代表的就是i~n(n is the size of s) 是否滿足題目條件
     * 0: 還沒計算
     * 1: 可以
     * -1: 不行
     * 可以跟不行都要紀錄, 這樣遇到相同的才可以直接return 
     * 在for迴圈中會將string分成兩部分
     * ex: leetcode
     * 1. l
     * 2. eetcode 進入下一層DFS, 
     * 如果此為有在word bank裡面且DFS(eetcode) return 回來也為true
     * 那leetcode就一定在wordbank裡面
     * 下一步
     * 1. le
     * 2. etcode 進入下一層DFS
     * ...
     */
public:
    bool DFS(string &s, unordered_set<string> &set, int start, vector<int> &memo)
    {
        if (start >= s.length())
            return true;
        // 代表substring start~end, 已經計算過, 直接return是否滿足題目條件
        if (memo[start] != -1)
            return memo[start];

        // Traverse所有長度
        for (int i = start + 1; i <= s.length(); i++)
        {
            if (set.count(s.substr(start, i - start)) && DFS(s, set, i, memo))
            {
                memo[start] = 1;
                return true;
            }
        }

        memo[start] = 0;
        return false;
    }
    bool wordBreak(string s, vector<string> &wordDict)
    {
        unordered_set<string> set(wordDict.begin(), wordDict.end());
        vector<int> memo(s.size(), -1);
        return DFS(s, set, 0, memo);
    }

    /**
 * dp version
 * Time: O(N^2), Space: O(N)
 * 解題流程: dp[i] 儲存的是從代表從頭到這個位置的substring是否有滿足題目條件
 * ex: 
 * leetcode    word[leet, code]
 * 00010001
 * 此dp的轉移方程為
 * string  = substring1 + substring2
 * 如果substring1為true and substring is true, 那string即可標記成true
 * substring1代表的就是需要traverse之前所有可能true的substring, 並利用set來判斷剩下的substring是否在字典中
 * ex: 
 * aaaaaaa   [aaaa][aaa]
 * 0011*
 * 我們在填下一個dp數值 * 時, 從之前的dp值traverse到為true的地方
 * 第一個為在index2的位置, aaaaa = aaa + aa
 * 其中aaa為之前算過為true, 因此只要判斷aa是否在word bank中
 * 第二為為index3的位置, aaaaa = aaaa + a
 * 其中aaaa為true, 因此要判斷a是否在word bank中
 * 只要其中一個滿足, 那此位置就為true
 * 
 * 此題做了一個優化, 不每次都traverse所有的dp值, 我們只存為true的dp值, 這樣每次只需要traverse true的位置就好 
 * 
 */
    bool wordBreak(string s, vector<string> &wordDict)
    {
        unordered_set<string> set;
        for (auto v : wordDict)
            set.insert(v);

        // 只紀錄true的index
        vector<int> dp_index;
        dp_index.push_back(0);

        // Traverse all string
        for (int i = 0; i < s.length(); i++)
        {
            // Traverse previous true substring
            for (auto v : dp_index)
            {
                if (v - 1 > i)
                    break;
                string sub = s.substr(v, i - v + 1);
                if (set.count(sub))
                {
                    dp_index.push_back(i + 1);
                    break;
                }
            }
        }
        return (dp_index.back() == s.length());
    }
};
// @lc code=end
