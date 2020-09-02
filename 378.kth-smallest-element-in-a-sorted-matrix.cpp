/*
 * @lc app=leetcode id=378 lang=cpp
 *
 * [378] Kth Smallest Element in a Sorted Matrix
 */

// @lc code=start
class Solution
{
    /**
     * Time: O((logN)^2), Space: O(1)
     * 解題流程: mid代表就是target value
     * ex: 
     * [1,2,3]
     * [3,5,6]
     * [5,6,7]
     * k=4
     * 一開始mid = 4
     * 在第一row裡面, 比所有都大, 因此count=3
     * 在第二row裡面, count=1
     * 第三row裡面, count=0
     * count其實代表含意就是第幾大數字的意思
     */
public:
    int kthSmallest(vector<vector<int>> &matrix, int k)
    {
        int n = matrix.size() - 1;
        int m = matrix[0].size() - 1;
        int l = matrix[0][0];
        int r = matrix[n][m];
        // O(logN * logN)
        while (l < r)
        {
            int mid = l + (r - l) / 2;
            int count = 0;
            for (int i = 0; i < matrix.size(); i++)
            {
                // 去計算此時的數字是在matrix中為第幾大
                count += upper_bound(matrix[i].begin(), matrix[i].end(), mid) - matrix[i].begin();
            }
            // 代表數字不夠大
            if (count < k)
                l = mid + 1;
            else
                r = mid;
        }
        return l;
    }

    /**
 * Time: O(N^2*logN), Space: O(N)
 * 解題流程: 利用max heap, traverse所有數字, 若此時heap的size大於k則pop出來最大的那個數字, 最後第k大的數字就會在heap的top
 */
    // int kthSmallest(vector<vector<int>> &matrix, int k)
    // {
    //     priority_queue<int> que;
    //     // O(N^2*logN)
    //     for (int i = 0; i < matrix.size(); i++)
    //     {
    //         for (int j = 0; j < matrix[0].size(); j++)
    //         {
    //             // O(logN)
    //             que.push(matrix[i][j]);
    //             if (que.size() > k)
    //                 que.pop();
    //         }
    //     }
    //     return que.top();
    // }
};
// @lc code=end
