/*
 * @lc app=leetcode id=165 lang=cpp
 *
 * [165] Compare Version Numbers
 */

// @lc code=start
class Solution
{
    /**
     * Time: O(N), Space: O(1)
     * 解題流程: 利用"atoi"可以有效解決這題
     * atoi(0001) = 1, atoi(001) = 1, atoi("")=0
     * 每次都取一段version1 and version2的塞到string中, 經由atoi轉換轉成int
     * 如果i1 or i2越界了也不會怎樣
     * 因為就等於str1 or str2為空的, atoi("")=0
     */
public:
    int compareVersion(string version1, string version2)
    {
        int i1 = 0;
        int i2 = 0;
        string str1, str2;
        while (i1 < version1.size() || i2 < version2.size())
        {
            // version1
            while (i1 < version1.size() && version1[i1] != '.')
            {
                str1.push_back(version1[i1]);
                i1++;
            }
            // version2
            while (i2 < version2.size() && version2[i2] != '.')
            {
                str2.push_back(version2[i2]);
                i2++;
            }
            int value1 = atoi(str1.c_str());
            int value2 = atoi(str2.c_str());

            if (value1 > value2)
                return 1;
            else if (value2 > value1)
                return -1;

            str1.clear();
            str2.clear();
            i1++;
            i2++;
        }
        return 0;
    }
};
// @lc code=end
