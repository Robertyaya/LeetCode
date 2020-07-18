#include <bits/stdc++.h>
using namespace std;

/**
 * 
 * Manacher's Algorithm [http://dino4cat.blogspot.com/2019/06/manacher.html]
 * Time: O(N), Space: O(1)
 * 解題流程: 作法跟expand from center很像 (while迴圈部份 radius就是expand from center概念)
 * 之所以可以從O(N^2)降到O(N)的原因在於利用回文的特性
 * 不用每次都從頭expand from center去計算最大的回文substring
 * 可以根據回文左邊的數值來取得一個基礎值, 接著往右移在繼續update
 * 
 */

string longestPalindrome(string s)
{
    string t = "#";
    for (int i = 0; i < s.size(); ++i)
    {
        t += s[i];
        t += '#';
    }

    int Max = 1, Max_id = 0;
    vector<int> radius(t.size(), 0);
    radius.push_back(1);

    for (int i = 1; i < t.size(); i++)
    {
        // 判斷這個點有沒有在最長回文裡面
        // Max_id + radius[Max_id]: 中心+半徑
        if (i < Max_id + radius[Max_id])
        {
            // 右邊的長度會(大於或等於左邊的長度)
            // radius[Max_id*2-i]此為在Max回文中和右邊對稱位置的radius
            // 然而左邊那個對稱位置不一定是完全在此Max回文中, 可能會更大超過邊界
            // Max_id+radkus[Max_id]-i指的就是左邊指到邊界的那個index的radius數值
            // 關鍵: 如果左邊越界了， Radius[i']會大於 i 到右邊界，而使用 min 就只會取到 i 到右邊界的距離 (此部份利用回文特性來思考)
            radius[i] = min(radius[Max_id * 2 - i], Max_id + radius[Max_id] - i);
        }
        else
        {
            radius[i] = 1;
        }

        while (i - radius[i] >= 0 && i + radius[i] < t.size() && t.at(i - radius[i]) == t.at(i + radius[i]))
            radius[i]++;
        if (radius[i] > Max)
        {
            Max = radius[i];
            Max_id = i;
        }
    }

    // Find right index
    int max_radius = Max;
    int i = 1;
    int right_index = Max_id;
    int left_index = Max_id;
    while (i < max_radius)
    {
        right_index++;
        left_index--;
        i++;
    }
    string answer = "";

    for (int i = left_index; i <= right_index; i++)
    {
        if (t[i] != '#')
            answer += t[i];
    }
    return answer;
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

        // Find the range of substring base on len
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
