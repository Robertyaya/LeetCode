/*
 * @lc app=leetcode id=835 lang=cpp
 *
 * [835] Image Overlap
 */

// @lc code=start
class Solution
{
    /**
     * Time: O(N^2), Space: O(N^2)
     * 此法為下面方法的優化, 下面要利用string來紀錄座標
     * 一般會使用[i,j]->i*n+j表示二維座標
     * 但因為下面要做座標相減, 可以會有相同的數值出現, n要取得夠大才可以在相減時有唯一值出現
     * ex: if n = 30
     * 409 = 13*30+19 = 14*30-11
     * 409 can be taken as sliding "14 rows and -11 cols" or "13 rows and 19 cols" at the same time
     */
public:
    int largestOverlap(vector<vector<int>> &img1, vector<vector<int>> &img2)
    {
        vector<int> listA, listB;
        unordered_map<int, int> map;
        int n = img1.size();
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (img1[i][j] == 1)
                    listA.push_back(i * 100 + j);
                if (img2[i][j] == 1)
                    listB.push_back(i * 100 + j);
            }
        }

        for (int i = 0; i < listA.size(); i++)
        {
            for (int j = 0; j < listB.size(); j++)
            {
                map[listA[i] - listB[j]]++;
            }
        }

        int res = 0;
        for (auto v : map)
            res = max(res, v.second);
        return res;
    }
    /**
     * Time: O(N^2), Space: O(N^2)
     */
    int largestOverlap(vector<vector<int>> &img1, vector<vector<int>> &img2)
    {
        vector<pair<int, int>> listA, listB;
        // key代表的是移動量, value代表此移動量的次數->對應的就是當下這個移動量有多少1重疊
        unordered_map<string, int> diffCnt;
        int res = 0;
        int n = img1.size();

        // O(N^2), 將等於1的座標放入listA and listB
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (img1[i][j] == 1)
                    listA.push_back({i, j});
                if (img2[i][j] == 1)
                    listB.push_back({i, j});
            }
        }

        for (int i = 0; i < listA.size(); i++)
        {
            auto a = listA[i];
            for (int j = 0; j < listB.size(); j++)
            {
                auto b = listB[j];
                // 計算移動重疊, 利用string表示, 因為要放到map中
                string diff_str = to_string(a.first - b.first) + "-" + to_string(a.second - b.second);
                // 紀錄哪樣的移動量重合1最多
                diffCnt[diff_str]++;
            }
        }

        for (auto v : diffCnt)
            res = max(res, v.second);

        return res;
    }
};
// @lc code=end
