/*
 * @lc app=leetcode id=443 lang=cpp
 *
 * [443] String Compression
 */

// @lc code=start
class Solution
{
    /**
     * Time: O(N), Space: O(1)
     */
public:
    int compress(vector<char> &chars)
    {
        int res = 0; // 用來記錄目前compress後為多長
        int count = 1;
        chars.push_back('%'); // 故意放一個在後面, 用來比較
        int index = 0;        // 紀錄modify char的位置
        for (int i = 1; i < chars.size(); i++)
        {
            if (chars[i] == chars[i - 1])
                count++;
            else
            {
                // Modify vector
                chars[index] = chars[i - 1];
                index++;
                if (count == 1)
                    res++;
                else
                {
                    // 將各位數字放入stack中
                    stack<int> sta;
                    // 計算位數
                    while (count != 0)
                    {
                        sta.push(count % 10);
                        count /= 10;
                        res++;
                    }
                    res++; // 加上本身的數字 'a'12

                    // Modify the vector
                    while (!sta.empty())
                    {
                        int t = sta.top();
                        sta.pop();
                        chars[index] = t + '0'; // 數字轉char
                        index++;
                    }
                }
                count = 1;
            }
        }
        return res;
    }
};
// @lc code=end
