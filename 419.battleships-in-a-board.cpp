/*
 * @lc app=leetcode id=419 lang=cpp
 *
 * [419] Battleships in a Board
 */

// @lc code=start
class Solution
{
    /**
     * Time: O(N^2), Space: O(N^2)
     */
public:
    void DFS(vector<vector<char>> &board, int i, int j, int &o_i, int &o_j, bool &flag)
    {
        // 超出board範圍或是不是X則return
        if (i < 0 || j < 0 || i > board.size() - 1 || j > board[0].size() - 1 || board[i][j] != 'X')
            return;

        // 代表重疊了或是和原本的i,j不一樣了, 代表此時這個不是一個ship, ship要水平或垂直的
        if (i != o_i && j != o_j)
            flag = false;

        board[i][j] = '$';
        DFS(board, i - 1, j, o_i, o_j, flag);
        DFS(board, i + 1, j, o_i, o_j, flag);
        DFS(board, i, j - 1, o_i, o_j, flag);
        DFS(board, i, j + 1, o_i, o_j, flag);
    }
    int countBattleships(vector<vector<char>> &board)
    {
        int res = 0;
        bool flag = true; // 用來確認是否有交疊情況發生
        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[0].size(); j++)
            {
                if (board[i][j] == 'X')
                {
                    DFS(board, i, j, i, j, flag);
                    if (flag)
                        res++;
                    flag = true;
                }
            }
        }
        return res;
    }
};
// @lc code=end
