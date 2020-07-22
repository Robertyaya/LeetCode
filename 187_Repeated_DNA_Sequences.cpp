#include <bits/stdc++.h>
using namespace std;
/**
 * Time: O(N), Space: O(N)
 * 解題流程: 和下面相同作法, 只是利用bit opterate可以較省空間且在做sliding window較快, 可以直接利用位元移動來計算
 * bit目的是對應char轉換成int, 轉成int後再用二進位運算
 * ex: ACGT->0,1,2,3->00011011
 * key << 2 | bit[s[i]] 
 * ex: original: 00011011 -> <<2 -> 0001101100 空出後面兩個,  因為要新增新的char進去
 * 接著再取or 0001101100 | 11 -> 0001101111 (or就是其中一個有1就是1)
 * 在做sliding window時, 每次需要刪除最前面以及新增最後面
 * key = key << 2 | bit[s[i]]新增到最後面
 * key & 0xfffff 移除最前面兩個
 * 0xfffff = 1111111111
 */
vector<string> findRepeatedDnaSequences(string s)
{
    if (s.size() < 10)
        return {};
    vector<string> output;
    unordered_map<int, int> map;
    unordered_map<char, int> bit;
    unordered_map<int, int>::iterator iter;
    bit['A'] = 0;
    bit['C'] = 1;
    bit['G'] = 2;
    bit['T'] = 3;
    // Initialize
    int key = 0;
    for (int i = 0; i < 10; i++)
    {
        key = key << 2 | bit[s[i]];
    }
    map[key] = 1;

    for (int i = 10; i < s.size(); i++)
    {
        key = key << 2;        // 空出兩格
        key = key | bit[s[i]]; // 新增進去
        key = key & 0xfffff;   // 移除最前面的兩個
        if (map.count(key))
        {
            if (map[key] < 2)
                output.push_back(s.substr(i - 9, 10));
            map[key]++;
        }
        else
            map[key] = 1;
    }
    return output;
}
/**
 * Time: O(N), Space: O(N)
 * 解題流程: 先建立一個unordered_map, key代表的是sub_string, value代表的是目前此sub_string出現的次數
 * 利用rolling window去取sub_stirng出來, 如果沒有在map中則insert進去, 如果已經在map中還須判斷是否超過2次了
 * 如果超過兩次則代表前面已經push_back in ouput vector, 反之則push_back到ouput中
 */

vector<string> findRepeatedDnaSequences(string s)
{
    // Edge case
    if (s.size() < 10)
        return {};

    vector<string> output;

    // The key is the substring, value 是代表已經遇到多少次
    unordered_map<string, int> map;
    string ini_str = s.substr(0, 10);
    map[ini_str] = 1;

    // Rolling window
    string str = ini_str;
    for (int i = 10; i < s.size(); i++)
    {
        str.erase(str.begin());
        str.push_back(s[i]);

        // Can find the target in map
        if (map.count(str))
        {
            // 代表次數僅有一次, 可以放入output裡面
            if (map[str] < 2)
            {
                output.push_back(str);
            }
            map[str]++;
        }
        else
            map[str] = 1;
    }
    return output;
}
