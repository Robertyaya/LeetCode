#include <bits/stdc++.h>
using namespace std;
int countGoodTriplets(vector<int> &arr, int a, int b, int c)
{
  int res = 0;
  for (int i = 0; i < arr.size() - 1; i++)
  {
    for (int j = i + 1; j < arr.size(); j++)
    {
      if (abs(arr[i] - arr[j]) <= a)
      {
        for (int k = j + 1; k < arr.size(); k++)
        {
          if (abs(arr[k] - arr[j]) <= b && abs(arr[k] - arr[i]) <= c)
          {
            res++;
          }
        }
      }
    }
  }
  return res;
}
