int minDays(int n)
{
  vector<int> dp(n + 1, 0);
  int count = 0;
  dp[0] = 0;
  dp[1] = 1;
  // Fill the dp
  for (int i = 2; i <= n; i++)
  {
    if (i % 2 == 0 || i % 3 == 0)
    {
      if (i % 3 == 0)
        dp[i] = min(dp.at(i - 1), dp.at(i / 3));
      else
        dp[i] = min(dp.at(i - 1), dp.at(i / 2));
    }
    else
      dp[i] = dp[i - 1];
  }
  return dp[n] + count;
}
