/*
 * @lc app=leetcode id=15 lang=cpp
 *
 * [15] 3Sum
 */

// @lc code=start
/**
 * Time: O(N^2), Space: O(1)
 * 解題流程: 
 * 1. Soring first (O（NlogN)）
 * 2. 先固定一個value, 計算出target value將three sum 問題降為two sum (the input is sorted problem)
 * 3. left pointer 指向起始點, right pointer 指向結束點 開始update (因為已經sorting 過)
 * 4. 當小於target則update left pointer, 當大於target則update right pointer
 * 5. 關鍵一步在於要如何skip掉相同的數組 ex: (-1, 0, 1), (0, -1, 1) 沒處理的話這兩個都會被放入answer裡面
 * 6. 分別迭代left and right pointer直到指向的數字和push_back進answer的數字不同, 才代表維新的一組數組
 * 7. 因為在此步i為固定, 因此若left or right指向的數字和前一步相同, 則所對應的數組"一定"為相同
 * 8. 最後再迭代i 如果此處也不能和上一步一樣, 因為和上一步一樣則又會找到相同的right and left 因此最後要迭代i直到不相同的數字
 */

class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        if (nums.size() < 3)
            return {};
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] > 0)
                return res;
            int target = -nums[i];
            // left pointer and right pointer
            int l = i + 1;
            int r = nums.size() - 1;
            while (l < r)
            {
                // 當小於target時, update left pointer
                if (nums[l] + nums[r] < target)
                    l++;
                // 當大於target時, update right pointer
                else if (nums[l] + nums[r] > target)
                    r--;
                else // 等於target時, 將其放入res中
                {
                    vector<int> temp = {nums[i], nums[l], nums[r]};
                    res.push_back(temp);

                    // 越過相同數字
                    while (l < r && nums[l] == temp[1])
                        l++;
                    while (l < r && nums[r] == temp[2])
                        r--;
                }
            }
            // i也要越過相同數字
            while (i + 1 < nums.size() && nums[i] == nums[i + 1])
                i++;
        }
        return res;
    }
};
// @lc code=end
