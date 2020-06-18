#include <bits/stdc++.h>
using namespace std;
/**
 * Time: O(2^N)(數字不能重複選, 因此每個數字就是選或不選兩種可能), Space: O(N)(Recursion stack)
 * 解題流程: 這題和problem 39相似, 差別在於此題input candiates可能為duplicate且數字不能重複選
 * 兩個地方要修改
 * 1. 解決數字不能重複選問題: 進入combinationsum時, begin的數字要迭代到下一個數字
 * 2. candiates為duplicate: ex: 1,1,2,5->會有兩個[1,2,5]其中一個1是從index0得到, 另一個則是從index1得到
 * 因此在每一次push back時, 皆要檢查是否和上一個數字相同(因為已經sorted過)如果相同則前面在begin進入時已經計算相對應的數組
 * 則直接skip進入下一個index
 */
void combinationsum(vector<int> &candiates, int target, vector<vector<int>> &answer,
                    vector<int> &combination, int begin)
{
    if (target == 0)
    {
        answer.push_back(combination);
        return;
    }
    for (int i = begin; i < candiates.size() && target >= candiates[begin]; i++)
    {
        if (i == begin || candiates[i] != candiates[i - 1])
        {
            combination.push_back(candiates[i]);
            combinationsum(candiates, target - candiates[i], answer, combination, i + 1);
            combination.pop_back();
        }
    }
}
vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
{
    sort(candidates.begin(), candidates.end());
    vector<vector<int>> answer;
    vector<int> combination;
    combinationsum(candidates, target, answer, combination, 0);
    return answer;
}
int main()
{
    vector<int> vec{10, 1, 2, 7, 6, 1, 5};
    vector<vector<int>> answer = combinationSum2(vec, 8);
    for (int i = 0; i < answer.size(); i++)
    {
        for (int j = 0; j < answer[i].size(); j++)
            cout << answer[i][j] << " ";
        cout << endl;
    }
}