/*
 * @lc app=leetcode id=661 lang=cpp
 *
 * [661] Image Smoother
 */

// @lc code=start
class Solution
{
    /**
     * Time: O(N^2), Space: O(N^2)
     */
public:
    vector<vector<int>> imageSmoother(vector<vector<int>> &M)
    {
        if (M.empty() || M[0].empty())
            return {};
        // 周圍8個點
        vector<vector<int>> mask = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};
        vector<vector<int>> res = M;
        for (int i = 0; i < M.size(); i++)
        {
            for (int j = 0; j < M[0].size(); j++)
            {
                int value = M[i][j];
                int count = 1;
                for (int k = 0; k < mask.size(); k++)
                {
                    int x = i + mask[k][0];
                    int y = j + mask[k][1];
                    // 確認是否超出邊界
                    if (x < 0 || y < 0 || x > res.size() - 1 || y > res[0].size() - 1)
                        continue;

                    count++;          // 計算周圍有幾個在範圍內的點
                    value += M[x][y]; // 計算total數值
                }
                res[i][j] = value / count;
            }
        }
        return res;
    }
};
// @lc code=end
