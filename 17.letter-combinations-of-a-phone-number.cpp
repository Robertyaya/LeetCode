/*
 * @lc app=leetcode id=17 lang=cpp
 *
 * [17] Letter Combinations of a Phone Number
 */

// @lc code=start
/**
 * 
 * Time: O(3^N) (N is the size of input string), Space: O(N) (Recursive stack, 每次只會有跟input string相同大小的stack)
 * 解題流程: 要找出所有種可能, 基本上這種題型都是用Recursive去找
 * 首先需建立一個字典dic, 用來查找number所對應到的string
 * string out: 其中一個return 字串
 * vector<string> res: 所有return 字串
 * level: 用來記錄現在進入第幾個號碼了, 當level等於號碼的siZE時, 代表所有號碼都已經打完, 因此將現有的out加到res中
 * 根據號碼找出相對應的string
 * 接著tranverse那個string, 類似於tree的概念, 往下搜, 每個node會有自己的children
 * 並將所有可能塞到res中
 * 
 */
class Solution
{
public:
    void DFS(vector<string> &dic, int index, string &digits, vector<string> &res, string str)
    {
        if (index == digits.length())
        {
            res.push_back(str);
            return;
        }

        // Convert to dic index
        int j = digits[index] - '0' - 1;
        for (int i = 0; i < dic[j].length(); i++)
        {
            DFS(dic, index + 1, digits, res, str + dic[j][i]);
        }
        return;
    }
    vector<string> letterCombinations(string digits)
    {
        if (digits.empty())
            return {};
        vector<string> dic = {"", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<string> res;
        DFS(dic, 0, digits, res, "");
        return res;
    }
};
// @lc code=end
