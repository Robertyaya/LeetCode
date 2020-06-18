#include <bits/stdc++.h>
/**
 * Time: O(2^N), Space: O(1)
 * 解題流程: Same as problem 40
 * 差別在於最後push_back進answer的解答's size是否有滿足題目設定之條件
 */
// value: 1 ~ 9
// Input: k = 3, n = 9
// Output: [[1,2,6], [1,3,5], [2,3,4]]
using namespace std;
void combinationsum(vector<vector<int>> &answer, vector<int> &combination,
                    int size, int target, int begin)
{
    if (target == 0)
    {
        if (combination.size() == size)
            answer.push_back(combination);
        return;
    }

    for (int i = begin; i <= 9 && target >= i; i++)
    {
        combination.push_back(i);
        combinationsum(answer, combination, size, target - i, i + 1);
        combination.pop_back();
    }
}
vector<vector<int>> combinationSum3(int k, int n)
{
    vector<vector<int>> answer;
    vector<int> combination;
    combinationsum(answer, combination, k, n, 1);
    return answer;
}
int main()
{
    vector<vector<int>> answer = combinationSum3(3, 9);
    for (int i = 0; i < answer.size(); i++)
    {
        for (int j = 0; j < answer[i].size(); j++)
            cout << answer[i][j] << " ";
        cout << endl;
    }
}