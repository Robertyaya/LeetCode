#include <bits/stdc++.h>
using namespace std;
/**
 * Time: O(N), Space: O(1)
 * 解題流程: Traverse t string如果遇到和s相同, 則代表要繼續找s的下一個, 因此移動j index
 */
bool isSubsequence(string s, string t)
{
  if (s.empty() && t.empty())
    return true;
  if (s.length() > t.length())
    return false;
  if (s.empty() == 0)
    return true;

  int j = 0;
  for (int i = 0; i < t.size(); i++)
  {
    if (t[i] == s[j])
      j++;
    if (j == s.size())
      return true;
  }
  return false;
}
