#include <bits/stdc++.h>
using namespace std;
/**
 * Time: O(N+M), Space: O(N+M)
 * 解題流程: 此題利用dp, dp存的是max common length
 * ex: [3,1,2], [1,2,2]
 *   3 1 2
 * 1 0 1 0 
 * 2 0 0 2
 * 2 0 0 1
 * 遇到相同的則取dp[i-1][j-1]+1, 不同的則直接填0
 * 每次都和將dp[i][j]和res做比較, update res value
 * 那之所以不同的直接填0是因為要求連續數組
 * [3,1]和[1] 為1
 * [3,1,2]和[1]此時前面已經update過為1, 此處如果填1
 * [3,1,2,1]和[1]此時又相同因此取[i-1][j-1]在上一步我們填了1, 因此此處會變成2, 則會出現錯誤
 * 
 */

int findLength(vector<int> &A, vector<int> &B)
{
  int m = A.size();
  int n = B.size();
  int dp[n + 1][m + 1];

  int res = 0;
  // O(N+M)
  for (int i = 0; i <= A.size(); i++)
  {
    for (int j = 0; j <= B.size(); j++)
    {
      // 初始化
      if (i == 0 || j == 0)
      {
        dp[i][j] = 0;
        continue;
      }

      dp[i][j] = 0;
      if (A[i - 1] == B[j - 1])
        dp[i][j] = dp[i - 1][j - 1] + 1;

      // 每次都將current dp value和res做比較
      res = max(dp[i][j], res);
    }
  }
  return res;
}
