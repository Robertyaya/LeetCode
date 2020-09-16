#include <bits/stdc++.h>
using namespace std;

int Partition(vector<int> &vec, int l, int r)
{
  int pivot_index = rand() % (r - l + 1) + l;
  swap(vec[r], vec[pivot_index]);
  int pivot = vec[r];

  int j = l;
  for (int i = l; i < r; i++)
  {
    if (vec[i] < pivot)
    {
      swap(vec[i], vec[l]);
      l++;
    }
  }
  swap(vec[l], vec[r]);
  return l;
}
void QuickSort(vector<int> &vec, int l, int r)
{
  if (l >= r)
    return;

  int index = Partition(vec, l, r);
  QuickSort(vec, l, index - 1);
  QuickSort(vec, index + 1, r);
}
int main()
{
  vector<int> vec = {4, 2, 6, 4, 1, 4, 7, 9};
  QuickSort(vec, 0, vec.size() - 1);
  for (auto v : vec)
    cout << v << " ";
  cout << endl;
}
