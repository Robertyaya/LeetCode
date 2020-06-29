#include <bits/stdc++.h>
using namespace std;
int FindBST(int start, int end)
{
  if (start >= end)
    return 1;

  int ans = 0;
  // 不同的tree node當root
  for (int i = start; i <= end; i++)
  {
    int leftTreeNum = FindBST(start, i - 1);
    int rightTreeNum = FindBST(i + 1, end);
    ans += leftTreeNum * rightTreeNum;
  }
  return ans;
}
int numTrees(int n)
{
  if (n == 0)
    return 0;
  return FindBST(1, n);
}
