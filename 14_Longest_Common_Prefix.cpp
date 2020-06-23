#include <bits/stdc++.h>
using namespace std;
/**
 * Time: O(N), Space: O(1)
 * 解題流程: Prefix為前綴詞, 所以從前面比較過來, 如果過程中遇到不相同的則直接return current answer
 * 如果相同則繼續update現在的prefix string
 * 另外如果在update過程中超過了其他string的邊界, 則直接return current answer, 因為代表此時最長的prefix為此超過邊界的string
 * 
 */
string longestCommonPrefix(vector<string> &strs)
{
  if (strs.size() == 0)
    return "";

  string answer;
  for (int i = 0; i < strs[0].size(); i++)
  {
    char ch = strs[0][i];
    for (int j = 1; j < str.size(); j++)
    {
      if (ch != str[j][i] || i > str[j].size() - 1)
        return answer;
    }
    answer += str[0][i];
  }
  return answer;
}
