#include <bits/stdc++.h>
using namespace std;
int numSub(string s)
{
  vector<int> vec(s.size(), 0);
  int index = 0;
  long long sum = 0;
  for (int i = 0; i < s.length(); i++)
  {
    if (s[i] == '1')
    {
      index++;
      sum += index;
    }
    else
      index = 0;
  }
  return sum % 1000000007;
}
int main()
{
  vector<int> vec(6, 0);
  for (auto v : vec)
    cout << v << endl;
}
