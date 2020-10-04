#include <bits/stdc++.h>
using namespace std;

void BubbleSort(vector<int> &vec)
{
  for (int i = vec.size() - 1; i > 0; i--)
  {
    for (int j = 0; j < i; j++)
    {
      if (vec[j] > vec[j + 1])
        swap(vec[j], vec[j + 1]);
    }
  }
}
int main()
{
  // 2D matrix initialize
  vector<vector<int>> matrix = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  vector<vector<int>> matrix2(5, vector<int>(5, 1));

  for (int i = 0; i < matrix.size(); i++)
  {
    for (int j = 0; j < matrix[i].size(); j++)
      cout << matrix[i][j] << " ";
    cout << endl;
  }
}
