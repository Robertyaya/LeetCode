/*
 * @lc app=leetcode id=223 lang=cpp
 *
 * [223] Rectangle Area
 */

// @lc code=start
class Solution
{
    /**
     * Time: O(1), Space: O(1)
     * 解題流程: 兩個rectangle分別算出來扣掉相交部分
     * 相交部分就是取各長寬的min and max來計算
     * 就是取rectangle"裡面"的長寬來當作重疊的長寬
     */
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H)
    {
        long long areaA = abs(C - A) * abs(D - B);
        long long areaB = abs(G - E) * abs(H - F);

        if (E >= C || G <= A || F >= D || H <= B)
            return areaA + areaB;

        // Calculate width
        long long width = abs(max(E, A) - min(G, C));
        long long height = abs(max(B, F) - min(H, D));
        return areaA + areaB - height * width;
    }
};
// @lc code=end
