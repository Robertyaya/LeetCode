int minOperations(int n)
{
  int mid;
  if (n % 2 == 0)
    mid = 2 * (n / 2);
  else
    mid = 2 * (n / 2) + 1;

  int count = 0;
  int value;
  for (int i = 0; i < n / 2; i++)
  {
    value = 2 * i + 1;
    count += (mid - value);
  }
  return count;
}
