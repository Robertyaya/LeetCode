int numWaterBottles(int numBottles, int numExchange)
{
  int res = numBottles;
  while (numBottles >= numExchange)
  {
    int a = numBottles / numExchange;
    int b = numBottles % numExchange;
    numBottles = (a + b);
    res += a;
  }
  return res;
}
