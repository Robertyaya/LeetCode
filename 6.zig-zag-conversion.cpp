/*
 * @lc app=leetcode id=6 lang=cpp
 *
 * [6] ZigZag Conversion
 */

// @lc code=start
/** 
 * 
 * Time: O(N), Space: O(N)
 * 解法只需要到底之後就step變號, 到頂之後再變號
 * 這樣就可以輪流塞到不同的row vector裡面
 */
class Solution
{
public:
    string convert(string s, int numRows)
    {
        if (numRows <= 1)
            return s;

        vector<vector<char>> vec;
        vec.resize(numRows);
        int step = 1;
        int index = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (index == numRows - 1)
                step = -1;
            else if (index == 0)
                step = 1;

            vec[index].push_back(s[i]);
            index += step;
        }

        string res = "";
        for (int i = 0; i < vec.size(); i++)
        {
            for (int j = 0; j < vec[i].size(); j++)
                res += vec[i][j];
        }
        return res;
    }
};
// @lc code=end
