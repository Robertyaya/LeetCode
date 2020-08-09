#include <bits/stdc++.h>
using namespace std;
string makeGood(string s)
{
  if (s.empty())
    return s;

  stack<char> sta;
  string str = "";
  int i = 0;
  while (i < s.length())
  {
    if (sta.empty())
    {
      sta.push(s[i]);
      i++;
      continue;
    }

    // 小寫
    if (s[i] >= 97)
    {
      int value = (sta.top() + 32);
      if (value == s[i])
        sta.pop();
      else
        sta.push(s[i]);
    }
    else
    {
      int value = (sta.top() - 32);
      if (value == s[i])
        sta.pop();
      else
        sta.push(s[i]);
    }
    i++;
  }

  while (!sta.empty())
  {
    char ch = sta.top();
    sta.pop();
    str += ch;
  }
  reverse(str.begin(), str.end());

  return str;
}
