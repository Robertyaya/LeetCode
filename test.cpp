#include <bits/stdc++.h>
using namespace std;

int main()
{
  vector<int>::iterator iter;
  vector<int> vec = {1, 3, 1, 2, 2, 3};
  iter = vec.begin();
  vec.erase(iter);
  cout << *iter << endl;
}
