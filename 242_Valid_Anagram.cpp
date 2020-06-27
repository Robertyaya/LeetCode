#include <bits/stdc++.h>
using namespace std;
/**
 * Time: O(N), Space: O(1)
 * 解題流程: input皆為小寫字母而且會重複, 因此建立一個大小為128的int map去save各別char出現的次數
 * index為各別char的ASCII code
 * 先tranverse string s建立map, 再tranverse string t to check
 * 當-1之後小於0則代表此char在string s中沒有, 因此此時直接return false
 */
bool isAnagram(string s, string t)
{
  if (s.size() != t.size())
    return false;

  int check[128] = {0};
  // Build the map
  for (int i = 0; i < s.size(); i++)
  {
    check[int(s[i])]++;
  }
  // Check the map
  for (int i = 0; i < t.size(); i++)
  {
    check[int(s[i])]--;
    if (check[int(s[i])] < 0)
      return false;
  }
  return true;
}

/**
 * Time: O(NlogN), Space: O(1)
 * 解題流程: 將input string sorting後做比較
 */
bool isAnagram(string s, string t)
{
  sort(s.begin(), t.begin());
  sort(t.begin(), t.end());
  return s == t;
}
