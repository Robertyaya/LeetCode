/*
 * @lc app=leetcode id=88 lang=cpp
 *
 * [88] Merge Sorted Array
 */

// @lc code=start
class Solution
{
    /**
     * Time: O(N+M), Space: O(1)
     * 解題流程: 從後面過來
     */
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        // 故意在前面塞一個INT_MIN, 這樣在two pointer比較時才不會越界
        nums1.insert(nums1.begin(), INT_MIN);
        nums2.insert(nums2.begin(), INT_MIN);

        int i = m;     // 指向nums1有數字的尾巴
        int j = n;     // 指向nums2尾巴
        int k = m + n; // 指向混合
        while (k >= 0)
        {
            if (nums1[i] > nums2[j])
            {
                nums1[k] = nums1[i];
                i--;
                k--;
            }
            else
            {
                nums1[k] = nums2[j];
                j--;
                k--;
            }
        }
        nums1.erase(nums1.begin());
    }

    /**
     * Time: O(N+M), Space: O(N)
     */
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        // Copy nums1有數字部分, 接在拿copy and nums2比較填回nums1中
        vector<int> copy(nums1.begin(), nums1.begin() + m);
        int i = 0;     // 指向copy
        int j = 0;     // 指向nums2
        int index = 0; // 指向nums1

        // 故意後面塞一個INT_MAX, 這樣在比較的時候才不會越界
        copy.push_back(INT_MAX);
        nums2.push_back(INT_MAX);
        while (index < nums1.size())
        {
            if (copy[i] < nums2[j])
            {
                nums1[index] = copy[i];
                index++;
                i++;
            }
            else
            {
                nums1[index] = nums2[j];
                index++;
                j++;
            }
        }
    }
};
// @lc code=end
