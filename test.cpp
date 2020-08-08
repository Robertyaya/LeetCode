#include <bits/stdc++.h>
using namespace std;

int main()
{
  multiset<int> set;
  for (int i = 0; i < 10; i++)
  {
    int temp = rand() % 10;
    set.insert(temp);
  }
  for (auto v : set)
    cout << v << " ";
}
