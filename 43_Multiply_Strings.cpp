#include <bits/stdc++.h>
using namespace std;
string multiply(string num1, string num2)
{
    int n = num1.size();
    int m = num2.size();
    int step = 0;
    vector<int> answer;
    answer.resize(n + m);
    for (int i = m - 1; i >= 0; i--) // num2
    {
        for (int j = n - 1; j >= 0; j--) // num1
        {
            int down_value = num2[i] - '0';
            int up_value = num1[j] - '0';
            int multiple = down_value * up_value;
            int first = multiple % 10;
            int second = (multiple - first) / 10;

            // Update answer vector
            answer[step] += first;
            //cout << (step) << " " << answer[step] << endl;

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
        step--;
    }

    string res = "";
    for (int i = answer.size() - 1; i >= 0; i--)
    {
        res += (answer[i] + '0');
    }
    return res;
}

int main()
{
    cout << multiply("89", "76") << endl;
}