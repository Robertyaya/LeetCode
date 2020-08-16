int maxDistance(vector<int> &position, int m)
{
  sort(position.begin(), postion.end());
  if (m == 1)
    return 0;
  if (m == 2)
    return position[position.size() - 1] - position[0];

  m -= 2;
}
