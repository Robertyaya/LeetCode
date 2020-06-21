#include <bits/stdc++.h>
using namespace std;
int lengthOfLongestSubstring(string s)
{
  vector<int> set(256, -1);
  int start_index = 0;
  int end_index = 0;
  int max_length = 0;
  while (end_index <= s.size() - 1)
  {
    if (set[int(s[i])] < 0)
    {
      set[int(s[i])] = i;
      end_index++;
    }
  }
}
