#include <bits/stdc++.h>
using namespace std;

int main()
{
  vector<int> vec = {1, 2, 4, 5, 6};
  auto it = lower_bound(vec.begin(), vec.end(), 3);
  cout << *it << endl;
}
