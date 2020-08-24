/*
 * @lc app=leetcode id=768 lang=cpp
 *
 * [768] Max Chunks To Make Sorted II
 */

// @lc code=start
class Solution
{
    /**
     * Time: O(NlogN), Space: O(N)
     * 解題流程: 另開一個array為sorting好的, 利用每一chunk"總數會相同"來判斷此時是否為一個chunk了
     */
public:
    int maxChunksToSorted(vector<int> &arr)
    {
        vector<int> arr2(arr);
        sort(arr.begin(), arr.end());

        int chunk;
        long arr_count = 0;
        long arr2_count = 0;
        for (int i = 0; i < arr.size(); i++)
        {
            arr_count += (long)arr[i];
            arr2_count += (long)arr2[i];
            // 此時代表為一個chunk
            if (arr_count == arr2_count)
            {
                chunk++;
                arr_count = 0;
                arr2_count = 0;
            }
        }
        return chunk;
    }
};
// @lc code=end
