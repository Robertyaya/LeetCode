#include <bits/stdc++.h>
using namespace std;
void FindBST(vector<bool> &vec, int output)
{
}
int numTrees(int n)
{
  vector<bool> record;
  record.reserve(n);
  vec.reserve(n);
  for (int i = 0; i < n; i++)
  {
    record.push_back(false);
  }
  int output = 0;
  FindBST(record, output);
}
