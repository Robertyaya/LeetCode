#include <bits/stdc++.h>
using namespace std;

class base
{
public:
  base()
  {
    cout << "base constructor" << endl;
    type = 1;
  }
  ~base()
  {
    cout << "base destructor" << endl;
  }
  virtual void showtype()
  {
    cout << type << endl;
  }

  int type;
};

class derive : public base
{
public:
  derive()
  {
    cout << "derive constructor" << endl;
    type = 2;
  }
  ~derive()
  {
    cout << "derive destructor" << endl;
  }
  void showtype()
  {
    cout << type << endl;
  }

  int type;
};
int main()
{
  char a = 'b';
  char b = 'd';
  char c = 1 + 'a';
  cout << c << endl;
}
