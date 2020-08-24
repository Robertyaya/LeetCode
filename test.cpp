#include <bits/stdc++.h>
using namespace std;

int main()
{
}

void solution(vector<int> nums)
{
  vector<int> dp(nums.size(), 0);
  vector<int> min_record;
  dp[0] = 1;
  for (int i = 1; i < nums.size(); i++)
  {
    if (nums[i] > nums[i - 1])
      dp[i] = dp[i - 1] + 1;
    else
    {
    }
  }
}
