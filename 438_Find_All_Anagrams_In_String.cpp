#include <bits/stdc++.h>
using namespace std;
/**
 * Time: O(N), Space: O(1)
 * 解題流程: 此題利用sliding window, 目的是因為這樣就不用重複計算中間已經算過的數值, 只需要扣掉最前面的以及加上最後面的不斷去update, 不用每次都重新計算
 * 建立兩個map一個是p 也就是target map
 * 另外一個則是tranverse s string過程中不斷去update s_map
 * 確認是否和p_map相同， 由於是利用map因此不會管char的順序只管是否存在此char
 * 在建立map的過程中， 之所以要-'a'的原因是直接取s[i]的話會將此char的ASCII放進去, -'a'則是因為我們已確認都是小寫且總共26個字母, 因此扣掉a的ascii 就可將所有char的ascii壓到0~25之間, 這樣我們建立的map就不用建到128, 而是26就好可以省空間
 * 比較s_map == p_map由於size為constant 26, 因此可視為O(1)
 * 
 */
// s.size=N, p.size()=M
vector<int> findAnagrams(string s, string p)
{
  vector<int> answer;
  vector<int> s_map(26, 0);
  vector<int> p_map(26, 0);
  if (p.size() > s.size())
    return {};

  // Initialize, based on p size , so that we can slide the window
  for (int i = 0; i < p.size(); i++)
  {
    s_map[s[i] - 'a']++;
    p_map[p[i] - 'a']++;
  }

  if (s_map == p_map)
  {
    answer.push_back(0);
  }

  // Tranverse s string
  for (int i = p.size(); i < s.size(); i++)
  {
    // Update the s_map, sliding window
    s_map[s[i] - 'a']++;            // Add the new char
    s_map[s[i - p.size()] - 'a']--; // Remove the old char
    // Answer need to push back the start index of string, i is not the start index is the end index
    // O(1)
    if (s_map == p_map)
    {
      // 將start index放入answer中
      answer.push_back(i - p.size() + 1);
    }
  }
  return answer;
}

int main()
{
  vector<int> vec = findAnagrams("cbaebabacd",
                                 "abc");
  for (int i = 0; i < vec.size(); i++)
    cout << vec[i] << endl;
}
