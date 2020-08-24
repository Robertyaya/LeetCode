bool Check(vector<int> &count, int m, vector<int> &index)
{
  int j = 0;
  for (int i = 0; i < count.size(); i++)
  {
    if (count[i] == 1)
      j++;
    else
    {
      if (j == m)
        return true;
      j = 0;
    }
  }
  return j == m;
}
int findLatestStep(vector<int> &arr, int m)
{
  vector<int> count(arr.size(), 1);
  int step = arr.size();
  for (int i = arr.size() - 1; i >= 0; i--)
  {
    if (Check(count, m))
      return step;

    int index = arr[i];
    count[index - 1] = 0;
    step--;
  }
  return -1;
}
