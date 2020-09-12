/*
 * @lc app=leetcode id=4 lang=cpp
 *
 * [4] Median of Two Sorted Arrays
 */

// @lc code=start
/**
 * M is the size of nums1, N is the size of nums2
 * Time: O(log(M+N)), Space: O(1)
 * 解題流程: 此題要找出中位數, 但因為兩個vector並不能先merge起來(因為這樣一定為O(N)), 代表一定必須要直接從兩個
 * 沒有merge起來的vector做Binary search
 * 找出中位數的問題可以轉化為找出第kth大小的數字在vector中
 * 
 * ex: [2,4,6,9] 偶數
 * 此題中位數為第2個數字(kth=2)和第3(kth=3)個數字相加/2
 * 
 * ex: [2,4,5,6,7,8,9] 奇數
 * 此題中位數為kth=4的數字
 * 
 * 因此將兩個數列相加分為奇數和偶數, 若奇數是找出第(n+m+1)的數字在兩個數列中, 若是偶數是找出中間那兩個後相加
 * 先解釋找出最關鍵的部份在recursive function中
 * ex: [1,2,3], [4,5,6,7]
 *               *
 * 要找出星號數字也就是kth=4的位置
 * 首先因為有兩個數列, 不知道誰大誰小因此先將k/2=2
 * 拿在a數列中第(k/2)th的數字和b數列中第(k/2)th的數字做比較
 * 而如果要找出單一數列第kth的數字很簡單直接就kth-1就是那個數字
 * ex: [1,2,3], [4,5,6,7]
 *        *        *
 * 因為數列2的第(k/2)個數字較大, 因此我們這邊可以得出一個結論, "數列1中k/2以前的絕對都不可能為全局的第kth數字"
 * 此處邏輯為此演算法最重要的部份, 之所以可以得出這樣的結論可以這樣想, 我們想要找出kth=4的數字
 * 先在各別數列中找出第(k/2)的數字, 如果a數列的比較小, 那就代表它一定不可能是全局的kth=4數字
 * 全局的kth=5的數字一定是兩個分節(k/2)的subarray的最右邊也就是最大的數字, 如果有哪一個比較大, 代表比較小的那個數列以前
 * 應該是可能<4th的數字
 * 有了這個結論, 根據上面的例子 5>2
 * 因此全局kth=4的數字一定位於 [1,2,3], [4,5,6]
 *                              *    * *
 * 這幾個位置上, 原本a數列中1,2都不可能
 * 因此修改nums1的數列中3開始, 也就是程式中的new_nums1的意思就是這邊
 * 接著原本要找全局kth=4的數字, 此時因為拿掉1,2 其實代表的含意就是我們已經拿掉(因為我們修改了原本的vector)kth<4的兩個數字, 實際是什麼不重要
 * 所以此時改成要找的是 kth(4-(拿掉的數字個數)) 繼續下去recursive
 * 
 */
class Solution
{
public:
    int FindKth(vector<int> &nums1, vector<int> &nums2, int k)
    {
        if (nums1.empty())
            return nums2[k - 1];
        if (nums2.empty())
            return nums1[k - 1];

        if (k == 1)
            return min(nums1[0], nums2[0]);

        int i = min((int)nums1.size(), (int)k / 2);
        int j = min((int)nums2.size(), (int)k / 2);
        if (nums1[i - 1] < nums2[j - 1])
        {
            vector<int> new_nums1(nums1.begin() + i, nums1.end());
            return FindKth(new_nums1, nums2, k - i);
        }
        else
        {
            vector<int> new_nums2(nums2.begin() + j, nums2.end());
            return FindKth(nums1, new_nums2, k - j);
        }
        return 0;
    }
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        int n = nums1.size();
        int m = nums2.size();
        int k = (n + m + 1) / 2;
        if ((n + m) % 2 == 0)
        {
            return (double)(FindKth(nums1, nums2, k) + FindKth(nums1, nums2, k + 1)) / 2.0;
        }
        return FindKth(nums1, nums2, k);
    }
    // 先merge再找median
    // O(M+N)
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        vector<int> vec;
        int i = 0;
        int j = 0;
        nums1.push_back(INT_MAX);
        nums2.push_back(INT_MAX);
        while (vec.size() + 2 < (nums1.size() + nums2.size()))
        {
            if (nums1[i] < nums2[j])
            {
                vec.push_back(nums1[i]);
                i++;
            }
            else
            {
                vec.push_back(nums2[j]);
                j++;
            }
        }

        int index = vec.size() / 2;
        if (vec.size() % 2 == 0)
        {
            return (double)(vec[index - 1] + vec[index]) / 2.0;
        }
        return vec[index];
    }
};
// @lc code=end
