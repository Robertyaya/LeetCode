#include <bits/stdc++.h>
using namespace std;
/**
 * Time: O(N*M) (N is the size of num1, M is the size of num2), Space: O(N+M) (Need to record the answer)
 * 解題流程: 此題目的是將各別char轉成int後相乘再相加, 不是直接把input string整個轉成int後相乘, 那這樣目的就是可以去解決兩個很大的數去相乘產生的越界問題
 * 首先是boundary case, 總共2種
 * 1. num1為空, 直接return num2, num2 為空, 直接return num1
 * 2. 其中一個string為"0"則不管另一個數字為多少, 都直接return 0
 * num2定義為做乘法時下面那個數字, num1定義為做乘法時上面那個數字
 *   1 2 3 ->num1
 * x 4 5 6 ->num2
 * -------
 *     1 8
 *   1 2
 *   6
 * 假設是上面一個乘法, num2固定為6分別乘上1,2,3, 依此做計算
 * 相乘之後分離出十位數和個位數, 依據階梯式的個別相加(從上圖可看到)
 * 有一個關鍵就是step代表的是那個位數在做階梯式相加的起始位置
 * ex: 當num2=6時分別和3,2,1相乘， step分別為1,2,3
 * 當num2=6時step起始位置變為2,3,4
 * 因此一開始step = (m - 1) - i就是在update step的起始位置
 */

string multiply(string num1, string num2)
{
    // Boundary case
    if (num1.empty())
        return num2;
    else if (num2.empty())
        return num1;
    else if (num1 == "0" || num2 == "0")
        return "0";

    int n = num1.size();
    int m = num2.size();
    int step = 0;
    vector<int> answer;
    answer.resize(n + m);
    // Tranverse from back to front (從個位數開始)
    for (int i = m - 1; i >= 0; i--) // num2: down value
    {
        step = (m - 1) - i;
        for (int j = n - 1; j >= 0; j--) // num1: up value
        {
            // 轉換為int
            int down_value = num2[i] - '0';
            int up_value = num1[j] - '0';
            int multiple = down_value * up_value;
            int first = multiple % 10;            // 個位數
            int second = (multiple - first) / 10; //十位數

            // Update answer vector
            answer[step] += first;
            //cout << (step) << " " << answer[step] << endl;

            // 超過10位數要進位
            if (answer[step] >= 10)
            {
                answer[step] -= 10;
                answer[step + 1]++;
            }
            answer[step + 1] += second;
            if (answer[step + 1] >= 10)
            {
                answer[step + 1] -= 10;
                answer[step + 2]++;
            }
            step++;
        }
    }

    string res = "";
    bool flag = true;
    for (int i = answer.size() - 1; i >= 0; i--)
    {
        if (answer[i] == 0 && flag && answer.size() - 1 != 0)
            continue;
        else
        {
            res += to_string(answer[i]);
            flag = false;
        }
    }
    return res;
}

int main()
{
    cout << multiply("0", "0") << endl;
}
