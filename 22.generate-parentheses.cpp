/*
 * @lc app=leetcode id=22 lang=cpp
 *
 * [22] Generate Parentheses
 */

// @lc code=start
/**
 * 
 * Time: O(2^N) (每個括弧都兩種可能 "(" or ")" ), Space: O(N) (Recursive 的stack總共就是N層)
 * 解題流程: 遇到這種找出所有可能的題型, 基本上都是Recursive
 * 在此題目中我們一樣利用Recursive找出所有括弧的可能
 * n: 代表左括弧的數量跟右括弧的數量
 * output: 為每一次進入下一層的recursive後會多加一個括弧, 有可能是左括弧或是右括弧
 * 關鍵: 左括弧跟右括弧有個數量限制, 那就是右括弧+到output的數量一定不能超過左括弧+到output的數量
 * 因為這樣就會有落單的情況, 因此在recursive中 if(left > right)就是在handle的情況
 * 在else中有兩個generateParenthesisDFS
 * 這邊可以理解成,在這一層中可以填右括弧or左括弧, 先填左括弧下去繼續recursive等到return回來後
 * 程式就會執行到下一行填右括弧下去recursive
 *
 */
class Solution
{
public:
    void generate(vector<string> &res, string str, int n_l, int n_r)
    {
        if (n_r < n_l || n_r < 0 || n_l < 0)
            return;
        if (n_l == 0 && n_r == 0)
        {
            res.push_back(str);
            return;
        }
        // 每次兩條路可以走, 左邊括號或右邊括號
        generate(res, str + '(', n_l - 1, n_r);
        generate(res, str + ')', n_l, n_r - 1);
    }
    vector<string> generateParenthesis(int n)
    {
        vector<string> res;
        generate(res, "(", n - 1, n);
        return res;
    }
};
// @lc code=end
