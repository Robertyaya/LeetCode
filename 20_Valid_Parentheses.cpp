#include <bits/stdc++.h>
using namespace std;
/**
 * Time: O(N), Space: O(N)(We need to use stack to record the char)
 * 解題流程: 左括號跟右括號一定要對到, 所以利用stack來record現在的符號, 像消磚塊一樣, 如果
 * 右括號對到左括號, 則pop出來, 反之如果沒對到直接return false
 * 有個小地方在於, 當stack裡面為empty時, 要直接push這個char進來
 * 不然如果是此時是右括號, 但此時stack裡面沒有任何char, 這樣在比較的時候會越界
 */
bool isValid(string s)
{
    stack<char> sta;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '(' || s[i] == '[' || s[i] == '{' || sta.empty())
            sta.push(s[i]);
        else
        {
            if (s[i] == ')')
            {
                if (sta.top() == '(')
                    sta.pop();
                else
                    return false;
            }
            if (s[i] == ']')
            {
                if (sta.top() == '[')
                    sta.pop();
                else
                    return false;
            }
            if (s[i] == '}')
            {
                if (sta.top() == '{')
                    sta.pop();
                else
                    return false;
            }
        }
    }
    if (sta.empty())
        return true;
    else
        return false;
}
