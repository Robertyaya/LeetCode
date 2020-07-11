#include <bits/stdc++.h>
using namespace std;
int trap(vector<int> &height)
{
  if (height.empty())
    return 0;

  int total_block = height[0];
  for (int i = 1; i < height.size(); i++)
  {
    if (i == height.size() - 1)
      total_block += height[i];
    else
      total_block += max(height[i], height[i - 1]);
  }

  for (auto v : height)
    total_block -= v;
  return total_block;
}
