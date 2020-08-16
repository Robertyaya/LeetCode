bool threeConsecutiveOdds(vector<int> &arr)
{
  int count = 0;
  for (auto v : arr)
  {
    if (v % 2 == 0)
      count = 0;
    else
      count++;
    if (count == 3)
      return true;
  }
  return false;
}
