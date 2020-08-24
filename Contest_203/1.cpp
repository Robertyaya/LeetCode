vector<int> mostVisited(int n, vector<int> &rounds)
{
  vector<int> res;
  vector<int> count(n + 1, 0);
  int max_count = 0;
  for (int i = 1; i <= n; i++)
  {
    if (i == rounds[0])
      count[i]++;
    for (int j = 1; j < rounds.size(); j++)
    {
      int start = rounds[j - 1];
      int end = rounds[j];
      if (end >= start && (i > start && i <= end))
      {
        count[i]++;
      }
      else if (end < start && (i % n > start || i % n <= end))
      {
        if (i != start)
          count[i]++;
      }

      max_count = max(max_count, count[i]);
    }
  }
  for (int i = 0; i < count.size(); i++)
  {
    cout << count[i] << endl;
    if (count[i] == max_count)
      res.push_back(i);
  }
  return res;
}
