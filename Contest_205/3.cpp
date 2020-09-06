int minCost(string s, vector<int> &cost)
{
  long long total = 0;
  for (auto v : cost)
    total += v;

  int l = 0, r = 0;
  int max_cost = 0;
  while (r < s.lenth())
  {
    if (s[l] == s[r])
    {
      max_cost = max(max_cost, cost[r]);
      r++;
    }
    else
    {
      l = r;
      total -= max_cost;
      max_cost = 0;
    }
  }
  return total - max_cost;
}
