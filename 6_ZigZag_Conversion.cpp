#include <bits/stdc++.h>
using namespace std;
string convert(string s, int numRows)
{
    // Boundary case
    if (numRows <= 1)
        return s;

    // Caculate the width (a is the 商)
    int set = 2 * numRows - 2;
    int i = 0, a = 0;
    // Calculate how many set
    while (i < s.size())
    {
        i += set;
        if (i > s.size())
            break;
        a++;
    }
    int res = (s.size()) % set;
    int width;
    if (res > numRows)
        width = (numRows - 1) * a + (res - numRows + 1);
    else
        width = (numRows - 1) * a + 1;

    // 宣告二維陣列
    for (int i = 0; i < numRows; i++)
    {
        for (int j = 0; j < width; j++)
            array[i][j] = '#';
    }

    // Fill the string into array into ZigZag type
    int j = 0, k = 0;
    bool flag = true;
    // O(s.size())
    for (int i = 0; i < s.size(); i++)
    {
        array[j][k] = s[i];
        if (j < numRows - 1 && flag)
            j++;
        else
            flag = false;

        if (!flag && j > 0)
        {
            j--;
            k++;
        }
        if (j == 0)
            flag = true;
    }

    string answer = "";
    for (int i = 0; i < numRows; i++)
    {
        for (int j = 0; j < width; j++)
        {
            if (array[i][j] != '#')
                answer += array[i][j];
        }
    }
    return answer;
}

int main()
{
    convert("PAYPALISHIRING", 4);
}