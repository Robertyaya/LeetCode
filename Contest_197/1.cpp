#include <bits/stdc++.h>
using namespace std;
int numIdenticalPairs(vector<int> &nums)
{
  int output = 0;
  for (int i = 0; i < nums.size() - 1; i++)
  {
    for (int j = i + 1; j < nums.size(); j++)
    {
      if (nums[i] == num[j])
        output++;
    }
  }
  return output;
}
