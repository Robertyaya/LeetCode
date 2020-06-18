#include <bits/stdc++.h>
/**
 * Time complexity 參考problem40, 差別在於此題可以重複取, 而重複取的數字多寡又取決於target大小. ex: target=10
 * 2可以取5次, 但5只能取3次, 因此原來數組{2, 3, 4, 5, 6} 共N個數字, target = 10
 * 可以改寫成 {2, 2, 2, 2, 2, 3, 3, 3, 3, 4, 4, 4, 5, 5, 6, 6} 共N'個數字
 * Time: O(2^N')  , Space: O(N) 
 * 解題流程: 此題input為not duplicate, 但每個數字可以重複選, 要找出相等於target的數組
 * 1. 先soring, (這樣後來在recursive可以提早中斷)
 * 2. 
 * target為目標數字(每次會去掉到塞進combination的數字), 
 * combination: save目前塞入合理的數組
 * begin: 紀錄目前遞迴到哪
 * 3. 先塞入目前的數值, (target-此數值)再進去下一層的Recursive, 若此數字不合理則pop_back出來, i會指向下一個數字
 * 4. 關鍵在於此for迴圈!
 */
// Input: candidates = [2,3,5], target = 8,
// A solution set is:
// [
//   [2,2,2,2],
//   [2,3,3],
//   [3,5]
// ]
using namespace std;
void combinationsum(vector<int> &candidates, int target, vector<vector<int>> &answer,
                    vector<int> &combination, int begin)
{
    // Base case, if target == 0, represent the answer in combination is equal to target, pushback into answer vector
    if (target == 0)
    {
        answer.push_back(combination);
        return;
    }

    // target >=candidates is purning.
    for (int i = begin; i < candidates.size() && target >= candidates[i]; i++)
    {
        combination.push_back(candidates[i]);
        combinationsum(candidates, target - candidates[i], answer, combination, i);
        combination.pop_back();
    }
}
vector<vector<int>> combinationSum(vector<int> &candidates, int target)
{
    sort(candidates.begin(), candidates.end());
    vector<vector<int>> answer;
    vector<int> combination;
    combinationsum(candidates, target, answer, combination, 0);
    return answer;
}
int main()
{
    vector<int> vec{2, 3, 5};
    combinationSum(vec, 8);
}