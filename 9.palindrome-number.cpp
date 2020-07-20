/*
 * @lc app=leetcode id=9 lang=cpp
 *
 * [9] Palindrome Number
 *
 * https://leetcode.com/problems/palindrome-number/description/
 *
 * algorithms
 * Easy (48.08%)
 * Likes:    2339
 * Dislikes: 1558
 * Total Accepted:    948.8K
 * Total Submissions: 2M
 * Testcase Example:  '121'
 *
 * Determine whether an integer is a palindrome. An integer is a palindrome
 * when it reads the same backward as forward.
 * 
 * Example 1:
 * 
 * 
 * Input: 121
 * Output: true
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: -121
 * Output: false
 * Explanation: From left to right, it reads -121. From right to left, it
 * becomes 121-. Therefore it is not a palindrome.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: 10
 * Output: false
 * Explanation: Reads 01 from right to left. Therefore it is not a
 * palindrome.
 * 
 * 
 * Follow up:
 * 
 * Coud you solve it without converting the integer to a string?
 * 
 */

// @lc code=start
class Solution
{
public:
    /**
 * Time: O(N), Space: O(N)
 * 
 * 
 */
    bool isPalindrome(int x)
    {
        if (x < 0)
            return false;
        vector<int> temp;
        // 取出各位數值之後塞到vector裡面
        while (x > 0)
        {
            int value = x % 10;
            temp.push_back(value);
            x /= 10;
        }

        int left = 0;
        int right = temp.size() - 1;
        while (right >= left)
        {
            if (temp[left] != temp[right])
                return false;
            left++;
            right--;
        }
        return true;
    }
    /**
     * The stirng size of x is N
     * Time: O(N), Space: O(1)
     * 解題流程: Convert int to string
     */
    // bool isPalindrome(int x)
    // {
    //     string str = to_string(x);

    //     int left = 0;
    //     int right = str.size() - 1;
    //     while (right >= left)
    //     {
    //         if (str[left] != str[right])
    //             return false;
    //         left++;
    //         right--;
    //     }
    //     return true;
    // }
};
// @lc code=end
