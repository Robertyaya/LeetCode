/*
 * @lc app=leetcode id=125 lang=cpp
 *
 * [125] Valid Palindrome
 */

// @lc code=start
class Solution
{
    /**
     * Time: O(N), Space: O(1)
     * 解題流程: 此題只比較英文字母或數字, 空格跟符號都要跳過
     * 利用two pointer, 一個在頭一個在尾
     * 如果不是英文字母或數字, 則update到下一個位置
     * 如果是則拿來比較, 大寫字母要換成小寫
     */
public:
    // 判斷是否為英文字母或數字, 都不是的話則要到下一個位置
    bool isLetterOrNum(char ch)
    {
        if (ch - '0' >= 0 && ch - '0' <= 9)
            return true;
        if (ch < 'A' || (ch > 'Z' && ch < 'a') || ch > 'z')
            return false;
        else
            return true;
    }
    bool isPalindrome(string s)
    {
        int left = 0;
        int right = s.length() - 1;
        while (left < right)
        {
            if (!isLetterOrNum(s[left]))
                left++;

            if (!isLetterOrNum(s[right]))
                right--;

            if (isLetterOrNum(s[left]) && isLetterOrNum(s[right]))
            {
                char ch_left = s[left];
                char ch_right = s[right];

                // 大寫換小寫
                if (s[left] >= 'A' && s[left] <= 'Z')
                    ch_left += 32;
                if (s[right] >= 'A' && s[right] <= 'Z')
                    ch_right += 32;

                if (ch_left != ch_right)
                    return false;

                left++;
                right--;
            }
        }
        return true;
    }
};
// @lc code=end
