/**
 * Contest 202
 * 解題流程: Recursive + momorization
 * map[i]代表的意義就是i個橘子時, value為最少的天數
 */
unordered_map<int, int> map;
int DFS(int n)
{
  if (n <= 1)
    return n;

  // 尚未在map裡面
  if (!map.count(n))
  {
    // n%3 and n%2這邊意義是利用1去扣的意思, 扣到可以被2 or 3整除下去繼續DFS
    // +1是代表DFS(n/3)其實是吃掉2/3個橘子, 所以這個算一天的操作
    int a = n % 3 + (DFS(n / 3) + 1);
    int b = n % 2 + (DFS(n / 2) + 1);
    // Insert to map
    map[n] = min(a, b);
  }
  return map[n];
}
int minDays(int n)
{
  return DFS(n);
}
/**
 * Contest 202
 * Time: O(N), Space: O(N)
 * 解題流程: dp[i]代表的是i個橘子時的最短天數
 * 但這題因為n會很大, 因此dp version會超時
 */
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
