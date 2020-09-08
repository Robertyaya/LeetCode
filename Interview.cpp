#include <bits/stdc++.h>
using namespace std;

// [[0,1,2],
//  [1,2,3]]  r=1, c=6 [1,2,3,3,4,5]
//                    r=3, c=2 [[1,2], [3,3], [4,5]]
//               traverse=col,  r=3,c=2 [[1,3],[2,4],[3,5]]
// tarverse matrix
// vector<vector<int>> size (r*c)

vector<vector<int>> Reshape(vector<vector<int>> &matrix, int r, int c, string method)
{
  vector<vector<int>> res_matrix;
  vector<int> res;
  int count = 0;

  if (method == "row")
  {
    // Time: O(N*M), Space: O(N*M)
    for (int i = 0; i < matrix.size(); i++)
    {
      for (int j = 0; j < matrix[0].size(); j++)
      {
        res.push_back(matrix[i][j]);
        count++;

        if (count == c)
        {
          res_matrix.push_back(res);
          count = 0;
          res.clear();
        }
      }
    }
  }
  else
  {
    // Time: O(N*M), Space: O(N*M)

    for (int i = 0; i < matrix[0].size(); i++) // col 0~2
    {
      for (int j = 0; j < matrix.size(); j++) // row 0~1
      {
        res.push_back(matrix[j][i]);
        count++;

        if (count == c)
        {
          res_matrix.push_back(res);
          count = 0;
          res.clear();
        }
      }
    }
  }

  return res_matrix;
}

int main()
{
  vector<vector<int>> matrix;
  // [[0,1,2],[1,2,3]]
  int k = 0;
  for (int j = 0; j < 2; j++)
  {
    vector<int> vec;
    for (int i = k; i < k + 3; i++)
    {
      vec.push_back(i);
    }
    matrix.push_back(vec);
    k++;
  }

  cout << matrix[0].size() << " " << matrix.size() << endl;

  vector<vector<int>> res = Reshape(matrix, 3, 2, "col");

  for (int i = 0; i < res.size(); i++)
  {
    for (int j = 0; j < res[0].size(); j++)
      cout << res[i][j] << " ";
    cout << endl;
  }
}
