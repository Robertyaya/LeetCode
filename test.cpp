#include <bits/stdc++.h>
using namespace std;

int main()
{
  stack<int> sta;
  for (int i = 0; i < 10; i++)
    sta.push(i);

  for (int i = 0; i < sta.size(); i++)
    cout << sta[i] << endl;
}
