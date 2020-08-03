/*
 * @lc app=leetcode id=166 lang=cpp
 *
 * [166] Fraction to Recurring Decimal
 */

// @lc code=start
class Solution
{
public:
    string fractionToDecimal(int numerator, int denominator)
    {
        unordered_map<long long, int> map; // 紀錄那個numerator在string的位置, 用來加入()
        string str;
        bool flag = true; // 切換是否要加.
        int sign = 1;     // 紀錄是否要變號

        // 全部要轉成long long且正, sign會紀錄是否會變號
        long long num = abs((long long)numerator);
        long long den = abs((long long)denominator);
        if ((numerator < 0 && denominator > 0) || (numerator > 0 && denominator < 0))
            sign = -1;

        // 一開始要加0. numerator=0的話則不用, 直接跳到下面return 0
        if (num < den && numerator != 0)
        {
            str.append("0.");
            num *= 10;
            flag = false;
        }
        while (num % den != 0)
        {
            // 如果此numerator曾經出現過, 代表已經循環了, 藉由map找出上次出現的位置加入'('
            if (auto v = map.find(num) != map.end())
            {
                str.insert(map[num], "(");
                str.push_back(')');
                if (sign < 0)
                    str.insert(0, "-");
                return str;
            }

            map[num] = str.size();
            // 補0後x10
            if (num < den)
            {
                str.push_back('0');
                num *= 10;
            }

            long long temp = num / den;
            str.append(to_string(temp));
            num -= (temp * den);

            if (flag)
            {
                str.push_back('.');
                flag = false;
            }
            num *= 10;
        }

        str.append(to_string(num / den));
        if (sign < 0)
            str.insert(0, "-");
        return str;
    }
};
// @lc code=end
