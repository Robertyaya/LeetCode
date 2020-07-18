/*
 * @lc app=leetcode id=201 lang=cpp
 *
 * [201] Bitwise AND of Numbers Range
 */

// @lc code=start
class Solution
{
    /**
 * Time: O(1), Space: O(1)
 * 解題流程: 此題要求m~n之間所有數字取AND, 當然可以按照定義直接做, sum = sum&current, 但這樣會超時
 * 因此觀察規律
 * ex: [5,6,7]
 * 101
 * 110
 * 111 &
 * ------
 * 100
 * 
 * ex: [26,30]
 * 11010
 * 11011
 * 11100
 * 11101
 * 11110 &
 * -------
 * 11000
 * 可發現重點在於只要找出左邊相同的數字就可以
 * 11010
 * 11110 
 * **
 * 其他右邊3個不重要, 因為在這個range中， 一定會出現0導致AND變為0
 * 因此目標要找出左邊相同的數字
 * 不斷往右移確認兩者是否相同了, 移動3格之後
 * 00011
 * 00011 ->此時為相同, i=3
 * 此時再移回去變成11000即為答案
 * 
 */
public:
    int rangeBitwiseAnd(int m, int n)
    {
        int i = 0;
        while (m != n)
        {
            m >>= 1;
            n >>= 1;
            i++;
        }
        return m << i;
    }
};
// @lc code=end
