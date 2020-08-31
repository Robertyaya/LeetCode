#include <bits/stdc++.h>
using namespace std;
void thread_function()
{
  cout << "thread" << endl;
}

int main()
{
  std::thread t1(thread_function);
  t1.join();
  return 0;
}
