#include <bits/stdc++.h>
using namespace std;
/**
 * Time: O(2^N), Space: O(N)
 * 解題流程: Same as problem 40
 * 這題比較簡單, 就是tranverse所有可能塞入answer裡面, 
 * 而problem 40是要加起來等於特定的target value才能加進去
 */
void subset_recursive(vector<vector<int>> &answer, vector<int> &nums,
                      vector<int> &subset, int begin)
{
    answer.push_back(subset);
    for (int i = begin; i < nums.size(); i++)
    {
        subset.push_back(nums[i]);
        subset_recursive(answer, nums, subset, i + 1);
        subset.pop_back();
    }
}
vector<vector<int>> subsets(vector<int> &nums)
{
    vector<int> subset;
    vector<vector<int>> answer;
    subset_recursive(answer, nums, subset, 0);
    return answer;
}
int main()
{
    vector<int> vec{1, 2, 3};
    vector<vector<int>> answer = subsets(vec);
    for (int i = 0; i < answer.size(); i++)
    {
        for (int j = 0; j < answer[i].size(); j++)
        {
            cout << answer[i][j] << " ";
        }
        cout << endl;
    }
}