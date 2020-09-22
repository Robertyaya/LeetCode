/*
 * @lc app=leetcode id=529 lang=cpp
 *
 * [529] Minesweeper
 */

// @lc code=start
class Solution
{
    /**
     * Time: O(N), Space: O(1)
     */
public:
    vector<vector<char>> updateBoard(vector<vector<char>> &board, vector<int> &click)
    {
        int row = click[0];
        int col = click[1];
        int n = board.size();
        int m = board[0].size();

        // 直接踩到雷
        if (board[row][col] == 'M')
        {
            board[row][col] = 'X';
            return board;
        }

        // 確認周圍有沒有mine
        int count = 0;
        for (int i = -1; i < 2; i++)
        {
            for (int j = -1; j < 2; j++)
            {
                int x = row + i;
                int y = col + j;
                if (x < 0 || x >= n || y < 0 || y >= m)
                    continue;
                // 紀錄周圍有幾個mine
                if (board[x][y] == 'M')
                    count++;
            }
        }
        // 代表周圍有mine
        if (count > 0)
            board[row][col] = count + '0';
        else
        {
            board[row][col] = 'B';
            // Next step
            for (int i = -1; i < 2; i++)
            {
                for (int j = -1; j < 2; j++)
                {
                    int x = row + i;
                    int y = col + j;
                    if (x < 0 || x >= n || y < 0 || y >= m)
                        continue;
                    if (board[x][y] == 'E')
                    {
                        vector<int> vec = {x, y};
                        updateBoard(board, vec);
                    }
                }
            }
        }
        return board;
    }
};
// @lc code=end
