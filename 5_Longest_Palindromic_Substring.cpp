#include <bits/stdc++.h>
using namespace std;

// Manacher's Algorithm
string longestPalindrome_(string s)
{
    string t = "#";
    for (int i = 0; i < s.size(); ++i)
    {
        t += s[i];
        t += '#';
    }

    int Max = 1, Max_id = 0;
    vector<int> radius(s.size(), 0);

    for (int i = 0; i < s.size(); i++)
    {
        if (i < Max_id + radius[Max_id])
        {
            radius[i] = radius[Max_id * 2 - i];
        }
        else
        {
            radius[i] = 1;
        }
    }
    return t;
}

/**
 * Time: O(N^2), Space: O(1)
 * 解題流程: 既然是要找回文, 根據回文定義就是substring兩邊的char相同, 因此tranverse string, 每次都從中間擴張去找
 * 擴張去找又分為兩種, 回文為偶數 aabb, 回文為奇數 aba
 * 在擴張尋找時, 如果沒遇到不同的或是超過範圍, 則繼續往兩邊迭代, 最後要return right-left-1(因為在最後一次會多加一筆)
 * ex: bbabc ->我們要找的是bab, 然而在找的時後left and right會迭代到index 0 and index 4, 或者是邊界的情況也是如此, ex: abadd, 要找到aba, 但會迭代到index -1 and index 3, 因此return 回來要right-left-1
 * 將兩種方式偶數回文為len2, 奇數回文為len1, 比較兩種到底哪個大
 * 最後則是去update longest substring's left index and right index
 * 利用len and current i, 我們可計算出此回文substring的end_index and start_index
 * 
 */
int ExpandFromCenter(string s, int left, int right)
{
    // Record the left index and right index
    vector<int> vec;
    if (left >= 0 && right < s.size() && s[left] == s[right])
    {
        left--;
        right++;
    }
    return right - left - 1;
}
string longestPalindrome(string s)
{
    if (s.size() == 0)
        return "";

    int end = 0;
    int start = 0;
    for (int i = 0; i < s.size(); i++)
    {
        // Odd
        int len1 = ExpandFromCenter(s, i, i);

        // Even
        int len2 = ExpandFromCenter(s, i, i + 1);

        int len = max(len1, len2);
        if (len > end - start + 1)
        {
            if (len % 2 == 0)
                start = i - len / 2 + 1;
            else
                start = i - len / 2;
            end = i + len / 2;
        }
    }
    return s.substr(start, end - start + 1);
}
int main()
{
    string str = "babad";
    cout << longestPalindrome_(str) << endl;
}
