/*
 * @lc app=leetcode id=769 lang=cpp
 *
 * [769] Max Chunks To Make Sorted
 */

// @lc code=start
class Solution
{
    /**
     * Time: O(N), Space: O(1)
     * 解題流程: 
     * ex: [1,0,3,2,4]
     * [1,0]會不斷update max_element
     * 因此(max_element=1) == index1
     */
public:
    int maxChunksToSorted(vector<int> &arr)
    {
        int chunk = 0;
        int max_element = 0;
        for (int i = 0; i < arr.size(); i++)
        {
            max_element = max(max_element, arr[i]);
            if (max_element == i)
                chunk++;
        }
        return chunk;
    }
};
// @lc code=end
