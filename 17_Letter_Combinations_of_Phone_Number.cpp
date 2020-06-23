#include <bits/stdc++.h>
using namespace std;
vector<string> letterCombinations(string digits)
{
  // Ascii a~z; 97~122
  vector<vector<int>> number_vec;
  number_vec.reserve(digits.size());
  for (int i = 0; i < digits.size(); i++)
  {
    vector<int> temp_vec;
    int number = digits[i] - '0';
    if (number == 1)
      continue;
    else
    {
      int m = number - 2;
      if (number <= 7)
      {
        temp_vec.push_back(m * 3 + 97);
        temp_vec.push_back(m * 3 + 98);
        temp_vec.push_back(m * 3 + 99);
        if (number == 7)
          temp_vec.push_back(m * 3 + 99 + 1);
      }
      else
      {
        temp_vec.push_back(m * 3 + 97 + 1);
        temp_vec.push_back(m * 3 + 98 + 1);
        temp_vec.push_back(m * 3 + 99 + 1);
        if (number == 9)
          temp_vec.push_back(m * 3 + 99 + 1 + 1);
      }
    }
    number_vec.push_back(temp_vec);
  }

  vector<string> string_vec;
  for (int i = 0; i < number_vec.size(); i++)
  {
    for (int j = 0; j < number_vec[i].size(); j++)
    {
    }
  }
}
int main()
{
  char c = '4';
  int a = c - '0';
  cout << a << endl;
}
