#include <bits/stdc++.h>
using namespace std;
int getWinner(vector<int> &arr, int k)
{
  int a = 0;
  int b = 1;
  int size = arr.size();
  int pre_win = INT_MAX;
  int count = k;
  while (count > 0)
  {
    if (arr[a] > arr[b]) // update b
    {
      arr.push_back(arr[b]);
      if (arr[a] == pre_win)
        count--;
      else
      {
        count = k - 1;
        pre_win = arr[a];
      }

      // Update pointer
      if (b > a)
        b++;
      else
        b = a + 1;
    }
    else // update a
    {
      arr.push_back(arr[a]);
      if (arr[b] == pre_win)
        count--;
      else
      {
        count = k - 1;
        pre_win = arr[b];
      }

      if (b > a)
        a = b + 1;
      else
        a++;
    }
    if (k - count > size)
      return pre_win;
  }
  return pre_win;
}
