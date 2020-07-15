/*
 * @lc app=leetcode id=179 lang=cpp
 *
 * [179] Largest Number
 */

// @lc code=start
class Solution
{
    /**
 * Time: O(NlogN), Space: O(N)
 * 解題流程: 此題關鍵在於如何排序string vector, 排好後只要全部append加起來就是答案
 * ex: 30, 111
 * 並不能只是單純比較兩個數值, 因為此題是要合起來看
 * 因此return為"30111" > "11130"
 * 至於為何要用string來做比較是因為這樣才不會遇到overflow的問題, 而且string裡面有自己自己定義比較符號, 他會根據string裡面每個char的ASCII做比較, 如果相同則比較下一個直到比較出答案
 */
public:
    string largestNumber(vector<int> &nums)
    {
        // 先將數字vector轉成string vector
        vector<string> vec_str;
        for (auto v : nums)
            vec_str.push_back(to_string(v));

        // 排序 (關鍵!!)
        sort(vec_str.begin(), vec_str.end(), [](auto a, auto b) {
            return a + b > b + a;
        });

        if (vec_str[0] == "0")
            return vec_str[0];

        string output = "";
        for (int i = 0; i < nums.size(); i++)
        {
            output += vec_str[i];
        }
        return output;
    }
};
// @lc code=end
