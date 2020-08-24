int maxCoins(vector<int> &piles)
{
  sort(piles.begin(), piles.end());
  int count = 0;
  int start = 0;
  int end = piles.size() - 2;
  while (start < end)
  {
    count += (piles[end]);
    end -= 2;
    start++;
  }
  return count;
}
