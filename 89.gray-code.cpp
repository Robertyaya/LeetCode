/*
 * @lc app=leetcode id=89 lang=cpp
 *
 * [89] Gray Code
 */

// @lc code=start
class Solution
{
    /**
     * Time: O(2^n), Space: O(n)
     * 解題流程:想成走迷宮概念, 因為兩個數字之間只能改變one bit
     * 因此利用DFS
     * ex: 
     * 00
     * 01 10 兩條路
     * 11
     * 流程一定要先00->01->11->10不能00->01->10->11(這樣為BFS)
     * 00利用和1取or來取得不同的路
     * ex:
     * 00^1=01
     * 00^10=10
     * 因此利用1的位移來取得路線
     *    
     */
public:
    void DFS(vector<int> &res, vector<bool> &visited, int value, int n)
    {
        // 這數值走過, 直接return
        if (visited[value])
            return;

        // 將目前數值放入res
        res.push_back(value);
        // 標記成走過
        visited[value] = true;
        // traverse每一位, 利用1的左移來取得不同路線
        for (int i = 0; i < n; i++)
        {
            int next = value ^ (1 << i);
            DFS(res, visited, next, n);
        }
    }
    vector<int> grayCode(int n)
    {
        // 總共會有那麼多答案
        int p = pow(2, n);
        // 紀錄目前的數值是否有走過
        vector<bool> visited(p, false);
        vector<int> res;
        DFS(res, visited, 0, n);
        return res;
    }
};
// @lc code=end
