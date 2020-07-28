/*
 * @lc app=leetcode id=79 lang=cpp
 *
 * [79] Word Search
 *
 * https://leetcode.com/problems/word-search/description/
 *
 * algorithms
 * Medium (34.85%)
 * Likes:    3973
 * Dislikes: 193
 * Total Accepted:    499.8K
 * Total Submissions: 1.4M
 * Testcase Example:  '[["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]]\n"ABCCED"'
 *
 * Given a 2D board and a word, find if the word exists in the grid.
 * 
 * The word can be constructed from letters of sequentially adjacent cell,
 * where "adjacent" cells are those horizontally or vertically neighboring. The
 * same letter cell may not be used more than once.
 * 
 * Example:
 * 
 * 
 * board =
 * [
 * ⁠ ['A','B','C','E'],
 * ⁠ ['S','F','C','S'],
 * ⁠ ['A','D','E','E']
 * ]
 * 
 * Given word = "ABCCED", return true.
 * Given word = "SEE", return true.
 * Given word = "ABCB", return false.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * board and word consists only of lowercase and uppercase English letters.
 * 1 <= board.length <= 200
 * 1 <= board[i].length <= 200
 * 1 <= word.length <= 10^3
 * 
 * 
 */

// @lc code=start
class Solution
{
    /**
     * k is the length of word
     * Time: O(M*N*4^k), Space: O(k)
     * Back tracking, same as 走迷宮
     */
public:
    bool DFS(vector<vector<char>> &board, int i, int j, string &word, int index)
    {
        if (index > word.size() - 1)
            return true;

        if (i < 0 || i > board.size() - 1 || j < 0 || j > board[0].size() - 1)
            return false;

        if (board[i][j] == word[index])
        {
            // 也可以用set來紀錄走過得index, 最下面erase掉, 但直接更改數值成一個#比較快
            char temp = board[i][j];
            board[i][j] = '#';

            if (DFS(board, i - 1, j, word, index + 1)) // Go down
                return true;
            if (DFS(board, i + 1, j, word, index + 1)) // Go up
                return true;
            if (DFS(board, i, j - 1, word, index + 1)) // Go left
                return true;
            if (DFS(board, i, j + 1, word, index + 1)) // Go right
                return true;

            board[i][j] = temp;
        }
        return false;
    }
    bool exist(vector<vector<char>> &board, string word)
    {
        if (board.empty() || board[0].empty())
            return false;

        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[0].size(); j++)
            {
                if (board[i][j] == word[0])
                {
                    if (DFS(board, i, j, word, 0))
                        return true;
                }
            }
        }
        return false;
    }
};
// @lc code=end
