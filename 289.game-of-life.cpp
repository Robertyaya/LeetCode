/*
 * @lc app=leetcode id=289 lang=cpp
 *
 * [289] Game of Life
 */

// @lc code=start
class Solution
{
    /**
     * Time: O(N), Space: O(1)
     * 解題流程: 
     * 因為要in-place, 關鍵在如何記住變化前為哪一個狀態
     * 利用狀態機的概念
     * 0: 死->死
     * 1: 活->活
     * 2: 活->死
     * 3: 死->活
     * 利用這4種狀態我們就可以知道變化前是什麼
     * 最後再將所有數字%2, ex: 2%2=0, 就是死 3%2=1就是活
     */
public:
    void gameOfLife(vector<vector<int>> &board)
    {
        int n = board.size();
        int m = board[0].size();
        // 先定義方向
        vector<int> dx = {-1, 0, 1, -1, 1, -1, 0, 1};
        vector<int> dy = {-1, -1, -1, 0, 0, 1, 1, 1};
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                // 紀錄周圍有幾個活細胞
                int count = 0;
                for (int k = 0; k < 8; k++)
                {
                    int x = i + dx[k];
                    int y = j + dy[k];
                    // board=1 || board=2代表先前是活的
                    if (x >= 0 && x < n && y >= 0 && y < m && (board[x][y] == 1 || board[x][y] == 2))
                        count++;
                }
                // 先前為死的(3 or 0)&&count==3,則會變成活得(3). 但已經變成3的就不用判斷了
                if (board[i][j] == 0 && count == 3)
                    board[i][j] = 3;
                if (board[i][j] == 1 && (count < 2 || count > 3))
                    board[i][j] = 2;
            }
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                board[i][j] = board[i][j] % 2;
            }
        }
    }
};
// @lc code=end
