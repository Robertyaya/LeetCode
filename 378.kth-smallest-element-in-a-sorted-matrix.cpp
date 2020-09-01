/*
 * @lc app=leetcode id=378 lang=cpp
 *
 * [378] Kth Smallest Element in a Sorted Matrix
 */

// @lc code=start
class Solution
{
public:
    /**
 * Time: O(N^2*logN), Space: O(N)
 * 解題流程: 利用max heap, traverse所有數字, 若此時heap的size大於k則pop出來最大的那個數字, 最後第k大的數字就會在heap的top
 */
    int kthSmallest(vector<vector<int>> &matrix, int k)
    {
        priority_queue<int> que;
        // O(N^2*logN)
        for (int i = 0; i < matrix.size(); i++)
        {
            for (int j = 0; j < matrix[0].size(); j++)
            {
                // O(logN)
                que.push(matrix[i][j]);
                if (que.size() > k)
                    que.pop();
            }
        }
        return que.top();
    }
};
// @lc code=end
