/*
 * @lc app=leetcode id=6 lang=cpp
 *
 * [6] ZigZag Conversion
 */

// @lc code=start
/** 
 * 
 * Time: O(N), Space: O(N)
 * 解題流程: 直接根據numRows去建一個2D array (這邊用string pointer 比vector快)
 * 根本不用管他Z字型, 只需要管每一個要塞到哪一個row vector裡面
 * 第二個解法處理Z字型花很多功夫, 這解法只需要到底之後就step變號, 到頂之後再變號
 * 這樣就可以輪流塞到不同的row vector裡面
 * 
 */
class Solution
{
public:
    string convert(string s, int numRows)
    {
        if (numRows == 1 || s.empty())
            return s;
        vector<vector<char>> matrix;
        matrix.resize(numRows);
        int row = 0;
        int step = 1;
        for (int i = 0; i < s.length(); i++)
        {
            if (row == 0)
                step = 1;
            else if (row == numRows - 1)
                step = -1;

            matrix[row].push_back(s[i]);
            row += step;
        }

        string res = "";
        for (int i = 0; i < numRows; i++)
        {
            for (int j = 0; j < matrix[i].size(); j++)
                res += matrix[i][j];
        }
        return res;
    }
};
// @lc code=end
