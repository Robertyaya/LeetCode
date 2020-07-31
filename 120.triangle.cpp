/*
 * @lc app=leetcode id=120 lang=cpp
 *
 * [120] Triangle
 *
 * https://leetcode.com/problems/triangle/description/
 *
 * algorithms
 * Medium (43.80%)
 * Likes:    2053
 * Dislikes: 244
 * Total Accepted:    251.2K
 * Total Submissions: 570.4K
 * Testcase Example:  '[[2],[3,4],[6,5,7],[4,1,8,3]]'
 *
 * Given a triangle, find the minimum path sum from top to bottom. Each step
 * you may move to adjacent numbers on the row below.
 * 
 * For example, given the following triangle
 * 
 * 
 * [
 * ⁠    [2],
 * ⁠   [3,4],
 * ⁠  [6,5,7],
 * ⁠ [4,1,8,3]
 * ]
 * 
 * 
 * The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).
 * 
 * Note:
 * 
 * Bonus point if you are able to do this using only O(n) extra space, where n
 * is the total number of rows in the triangle.
 * 
 */

// @lc code=start
class Solution
{
public:
    int DFS(vector<vector<int>> &triangle, int path, int index, int level)
    {
        if (index > triangle[level].size() - 1)
            return INT_MAX;

        if (level == triangle.size() - 1)
        {
            path += triangle[level][index];
            return path;
        }

        return min(DFS(triangle, path + triangle[level][index], index, level + 1),
                   DFS(triangle, path + triangle[level][index], index + 1, level + 1));
    }
    int minimumTotal(vector<vector<int>> &triangle)
    {
        if (triangle.empty() || triangle[0].empty())
            return 0;
        if (triangle.size() == 1)
            return triangle[0][0];

        int path = 0;
        return DFS(triangle, path, 0, 0);
    }
};
// @lc code=end
