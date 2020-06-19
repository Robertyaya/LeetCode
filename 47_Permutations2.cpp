#include <bits/stdc++.h>
using namespace std;
// Input: [1,1,2]
// Output:
// [
//   [1,1,2],
//   [1,2,1],
//   [2,1,1]
// ]
void permute_recursive(int pos, vector<vector<int>> &answer, vector<int> &nums)
{
    if (pos == nums.size())
    {
        answer.push_back(nums);
    }
    for (int i = pos; i < nums.size(); i++)
    {
        if (i == pos || (nums[i] != nums[pos] && nums[i] != nums[i - 1]))
        {
            swap(nums[i], nums[pos]);
            permute_recursive(pos + 1, answer, nums);
            swap(nums[i], nums[pos]);
        }
    }
}
vector<vector<int>> permuteUnique(vector<int> &nums)
{
    sort(nums.begin(), nums.end());
    vector<vector<int>> answer;
    permute_recursive(0, answer, nums);
    return answer;
}
int main()
{

    vector<int> vec{-1, 2, 0, -1, 1, 0, 1};
    vector<vector<int>> answer = permuteUnique(vec);
    for (int i = 0; i < answer.size(); i++)
    {
        for (int j = 0; j < answer[i].size(); j++)
            cout << answer[i][j] << " ";
        cout << endl;
    }
}
