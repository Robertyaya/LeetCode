#include <bits/stdc++.h>
using namespace std;

void func(int a[2][3])
{
  for (int i = 0; i < 2; i++)
  {
    for (int j = 0; j < 3; j++)
    {
      cout << a[i][j] << " ";
    }
    cout << endl;
  }
}

int main()
{
  vector<pair<int, int>> direction = {{0, 1}, {-1, 0}, {0, -1}, {1, 0}};
  for (int i = 0; i < direction.size(); i++)
  {
    cout << direction[i].first << " " << direction[i].second << endl;
  }
}
