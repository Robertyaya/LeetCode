/*
 * @lc app=leetcode id=118 lang=cpp
 *
 * [118] Pascal's Triangle
 *
 * https://leetcode.com/problems/pascals-triangle/description/
 *
 * algorithms
 * Easy (52.01%)
 * Likes:    1522
 * Dislikes: 111
 * Total Accepted:    387K
 * Total Submissions: 740.1K
 * Testcase Example:  '5'
 *
 * Given a non-negative integer numRows, generate the first numRows of Pascal's
 * triangle.
 * 
 * 
 * In Pascal's triangle, each number is the sum of the two numbers directly
 * above it.
 * 
 * Example:
 * 
 * 
 * Input: 5
 * Output:
 * [
 * ⁠    [1],
 * ⁠   [1,1],
 * ⁠  [1,2,1],
 * ⁠ [1,3,3,1],
 * ⁠[1,4,6,4,1]
 * ]
 * 
 * 
 */

// @lc code=start
class Solution
{
    /**
     * Time: O(N^2), Space: O(N^2)
     */
public:
    vector<vector<int>> generate(int numRows)
    {
        if (numRows == 0)
            return {};

        vector<vector<int>> res;
        for (int i = 1; i <= numRows; i++)
        {
            // 先全部填1
            vector<int> vec(i, 1);
            if (i <= 2)
            {
                res.push_back(vec);
                continue;
            }

            int index = 0;
            vector<int> pre_vec = res.back();
            // 基於上一層的數字相加得到這一層
            for (int j = 2; j <= i - 1 && index < pre_vec.size(); j++)
            {
                vec[j - 1] = pre_vec[index] + pre_vec[index + 1];
                index++;
            }
            res.push_back(vec);
        }
        return res;
    }
};
// @lc code=end
