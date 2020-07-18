#include <bits/stdc++.h>
using namespace std;
// Input: [1,1,2]
// Output:
// [
//   [1,1,2],
//   [1,2,1],
//   [2,1,1]
// ]
/**
 * Time: O(N!), Space: O(N)
 * 解題流程: 關鍵在於for迴圈的兩個判斷式
 * 1. if (!nums_bool[i]): 因為每次都是從0開始搜, 每次都要避開自己, 因此設一個跟nums size相同的bool vector
 * 用來記錄此數值有沒有放到permute vector裡面, 也可用unorder_set去確認是否有相同數值在permute裡面了, 概念一樣
 * 2. 關鍵:  if (i > 0 && nums[i] == nums[i - 1] && !nums_bool[i - 1])
 * i>0是確保後面的nums[i] == nums[i-1]的i-1當在i==0時會out_of_range
 * nums[i]==nums[i-1]是要handle以下情況
 * ex: [1,1,2], 當第一層也就是index=0的1做完要迭代到下一個index=1時, 結果數值還是1, 出來結果會一模一樣， 因此要skip掉 
 * 然後如果只有這行會出現有一種情況無法handle也就是, ex:[1,2,]第三層要填1, index0會先skip掉(因為已放入, 所以bool vector = true), index=1時數值還是1, 因此當判斷nums[i] == nums[i-1]也會被濾掉
 * 然而我們要濾掉的僅僅是"同一層"在做迭代時, 當這次迭代為1下次迭代還是1的話就要濾掉, 而上面那種情況是不同層的時候被拿來判斷nums[i]==nums[i-1]
 * 因此我們在後面需多加一個判斷 "nums_bool[i-1]" 確認是否已經在vector裡面, 如果在的話, 代表是不同層 不需要判斷nums[i] == num[i-1], 然而如果沒有在則需要判斷, 如此可確保我們是在同一層來判斷這件事 
 * ex: [0,1,1,2]
 *         *
 * 1 0 1 2
 * 
 * [0,1,1,2]
 *      *
 * 1 0 這一層時
 * 此時i==1, nums[i]==1 , 且尚未放到裡面, 因此continue
 * 1 0 2 1
 * 此題問題在於因為為排序過, 因此在計算permutation時, 兩種case
 * 1. current_i->不相同->相同->
 * 2. current_i->相同->
 * 因此如果到next_i, 和current_i相同數字, 必須去濾掉說
 * 1. next_i ->不相同->相同 這邊不相同會和上面不相同完全相同, 因此再放相同的話就會和上面一樣數列
 * 因此要改成
 * next_i->不相同->不相同->
 */
void permute_recursive(vector<vector<int>> &answer, vector<int> &permute, vector<int> &nums, vector<bool> &nums_bool)
{
    if (permute.size() == nums.size())
    {
        answer.push_back(permute);
    }

    for (int i = 0; i < nums.size(); i++)
    {
        // very important!!
        if (i > 0 && nums[i] == nums[i - 1] && !nums_bool[i - 1])
            continue;

        if (!nums_bool[i])
        {
            permute.push_back(nums[i]);
            nums_bool[i] = true;

            permute_recursive(answer, permute, nums, nums_bool);

            permute.pop_back();
            nums_bool[i] = false;
        }
    }
}
vector<vector<int>> permuteUnique(vector<int> &nums)
{
    sort(nums.begin(), nums.end());
    vector<vector<int>> answer;
    vector<int> permute;
    vector<bool> nums_bool; // Record whether this value in the permute vector
    nums_bool.resize(nums.size());
    permute_recursive(answer, permute, nums, nums_bool);
    return answer;
}
int main()
{

    vector<int> vec{1, 1, 2};
    vector<vector<int>> answer = permuteUnique(vec);
    for (int i = 0; i < answer.size(); i++)
    {
        for (int j = 0; j < answer[i].size(); j++)
            cout << answer[i][j] << " ";
        cout << endl;
    }
}
