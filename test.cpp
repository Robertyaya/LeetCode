#include <bits/stdc++.h>
using namespace std;

int main()
{
  list<int> l1;
  list<int> l2 = {1, 2, 3, 4};
  l1.splice(l1.begin(), l1, l2.begin());
  for (auto v : l1)
    cout << v << endl;
}
