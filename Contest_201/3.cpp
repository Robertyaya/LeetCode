#include <bits/stdc++.h>
using namespace std;
void Find(vector<int> &nums, int target, int level, vector<vector<int>> &total, vector<int> &ans)
{
  if (target < 0 || level >= nums.size())
    return;
  if (target == 0)
  {
    total.push_back(ans);
    return;
  }

  ans.push_back(nums[level]);
  Find(nums, target - nums[i], i + 1, total, ans);
  ans.pop_back();
}
int maxNonOverlapping(vector<int> &nums, int target)
{
  vector<vector<int>> total;
  vector<int> ans;
  Find(nums, target, 0, total, ans);

  cout << total.size() << " " << total[0].size() << endl;

  for (int i = 0; i < total.size(); i++)
  {
    for (int j = 0; j < total[i].size(); j++)
    {
      cout << total[i][j] << " ";
    }
    cout << endl;
  }
  return 1;
}
