#include <bits/stdc++.h>
using namespace std;
/** 
 * 
 * Time: O(N), Space: O(N)
 * 解題流程: 直接根據numRows去建一個2D array (這邊用string pointer 比vector快)
 * 根本不用管他Z字型, 只需要管每一個要塞到哪一個row vector裡面
 * 第二個解法處理Z字型花很多功夫, 這解法只需要到底之後就step變號, 到頂之後再變號
 * 這樣就可以輪流塞到不同的row vector裡面
 * 
 */

string convert_(string s, int numRows)
{
    // Boundary case
    if (numRows <= 1)
        return s;
    string *str = new string[numRows];
    int row_index = 0;
    int step = 1;
    // O(N)
    for (int i = 0; i < s.size(); i++)
    {
        // Arrive the bottom, change step
        if (row_index == numRows - 1)
        {
            step = -1;
        }
        // Arrive the top, change step
        else if (row_index == 0)
        {
            step = 1;
        }
        str[row_index].push_back(s[i]);
        row_index += step;
    }

    string answer = "";
    for (int i = 0; i < numRows; i++)
        answer += str[i];
    return answer;
}
/**
 * Time: O(N*M), Space: O(N*M)
 * 解題流程: 開一個2D array, 依據題目將string按照z字型填到2D array中
 * 填完之後再一層一層加到answer string中, 過程中遇到#則跳過
 * 基本上就是根據定義, 很直觀的解掉
 * 
 */

string convert(string s, int numRows)
{
    if (numRows <= 1)
        return s;

    // Caculate the width
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
    char array[numRows][width];
    // Initialize
    for (int i = 0; i < numRows; i++)
    {
        for (int j = 0; j < width; j++)
            array[i][j] = '#';
    }

    // Fill the string into array into ZigZag type
    int j = 0, k = 0;
    bool flag = true;
    for (int i = 0; i < s.size(); i++)
    {
        //cout << j << " " << k << endl;
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
    cout << convert_("PAYPALISHIRING", 4) << endl;
}
