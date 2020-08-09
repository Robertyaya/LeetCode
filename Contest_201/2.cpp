#include <bits/stdc++.h>
using namespace std;
string invert(string str)
{
  for (auto &v : str)
  {
    if (v == '1')
      v = '0';
    else
      v = '1';
  }
  return str;
}
string Reverse(string str)
{
  reverse(str.begin(), str.end());
  return str;
}
char findKthBit(int n, int k)
{
  string s1 = "0";
  string sn = s1;
  for (int i = 2; i <= n; i++)
  {
    sn = s1 + "1" + Reverse(invert(s1));
    s1 = sn;
  }

  return sn[k - 1];
}
