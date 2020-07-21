/*
 * @lc app=leetcode id=38 lang=cpp
 *
 * [38] Count and Say
 */

// @lc code=start
class Solution
{
    /**
     * Time: O(N), Space: O(N)
     */
public:
    string countAndSay(int n)
    {
        if (n == 1)
            return "1";

        int f;
        char ch;
        int k = 2; // 從n=2開始
        string previous = "1";
        string output;
        while (k <= n)
        {
            string current = "";

            // char and frequency initialize
            ch = previous[0];
            f = 1;

            for (int i = 1; i < previous.size(); i++)
            {
                if (previous[i] == previous[i - 1])
                    f++;
                else
                {
                    current += to_string(f);
                    current.push_back(ch);

                    // 更新char and frequency
                    ch = previous[i];
                    f = 1;
                }
            }
            // Handle最後一個
            current += to_string(f);
            current.push_back(ch);

            k++;
            previous = current;
            output = current;
        }
        return output;
    }
};
// @lc code=end
