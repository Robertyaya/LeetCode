/*
 * @lc app=leetcode id=162 lang=cpp
 *
 * [162] Find Peak Element
 */

// @lc code=start
class Solution
{
    /**
     * Time: O(logN), Space: O(1)
     * 解題流程: 題目要求O(logN), 利用Binary search
     * 如果nums[mid] < 右邊那個數字, 那就update left pointer mid+1
     * 如果nums[mid] < 左邊那個數字, 那就update right pointer mid-1
     * 當比兩邊都大的時候， 代表此數字為peak, 則直接return 
     * 
     * 有個Boundary case就是當mid為0的時候, 也就是left=0, right=1的情況
     * 因為上面已經檢查過left=0為peak的情況, 因此此處直接update left為mid+1
     * 因為index0不可能為peak
     */
public:
    int findPeakElement(vector<int> &nums)
    {
        if (nums.size() == 1)
            return 0;
        int l = 0;
        int r = nums.size() - 1;
        if (nums[l] > nums[l + 1])
            return l;
        if (nums[r] > nums[r - 1])
            return r;

        while (r > l)
        {
            int mid = l + (r - l) / 2;
            if (mid == 0)
            {
                l = mid + 1;
                continue;
            }
            // Find the peak
            if (nums[mid] > nums[mid - 1] && nums[mid] > nums[mid + 1])
                return mid;
            else if (nums[mid] < nums[mid - 1])
                r = mid - 1;
            else
                l = mid + 1;
        }
        return r;
    }

    /**
 * Time: O(NlogN), Space: O(N)
 * 記錄下每一個value的index後. 接著sorting
 * 最後return最後面也就是最大的數字就一定是peak
 */
    int findPeakElement(vector<int> &nums)
    {
        vector<pair<int, int>> vec;
        // O(N)
        for (int i = 0; i < nums.size(); i++)
        {
            vec.push_back({nums[i], i});
        }
        // O(NlogN)
        sort(vec.begin(), vec.end(), [](auto &a, auto &b) { return a.first < b.first; });
        return vec[vec.size() - 1].second;
    }
};
// @lc code=end
