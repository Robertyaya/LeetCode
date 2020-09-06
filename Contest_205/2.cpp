int numTriplets(vector<int> &nums1, vector<int> &nums2)
{
  int count = 0;
  for (auto v : nums1)
  {
    long long t = (long long)v * v;
    unordered_map<int, int> map;
    for (auto k : nums2)
    {
      if (t % k == 0)
      {
        if (map.count(t / k))
        {
          count += map[t / k];
        }
        map[k]++;
      }
    }
  }

  for (auto v : nums2)
  {
    long long t = (long long)v * v;
    unordered_map<int, int> map;
    for (auto k : nums1)
    {
      if (t % k == 0)
      {
        if (map.count(t / k))
        {
          count += map[t / k];
        }
        map[k]++;
      }
    }
  }
  return count;
}
