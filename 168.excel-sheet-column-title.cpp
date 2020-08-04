/*
 * @lc app=leetcode id=168 lang=cpp
 *
 * [168] Excel Sheet Column Title
 */

// @lc code=start
class Solution
{
    /**
     * Time: O(logn), Space: O(1)
     * 解題流程: 想成26進位, 每經過26就要進
     * 位
     * ex: 27/26 = 1...1
     *             A   A
     * 
     * 701/26 = 26...25
     *           Z   Y
     * 
     * 52/26=2..0->1...26
     *             A   Z
     */
public:
    string convertToTitle(int n)
    {
        string str;
        while (n)
        {
            if (n % 26 == 0)
            {
                char ch = 'Z';
                string temp = "";
                temp += ch;
                str.insert(0, temp);
                n -= 26;
            }
            else
            {
                // char to string
                char ch = (n % 26 + 'A' - 1);
                string temp = "";
                temp += ch;
                str.insert(0, temp);
            }
            n /= 26;
        }
        return str;
    }
};
// @lc code=end
