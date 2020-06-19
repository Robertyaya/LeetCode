#include <bits/stdc++.h>
/**
 * Time: O(N!), Space: O(N)
 * 解題流程: 一樣為Back tracking題型, 這題目的要找出所有的permutation
 * 因此在每一次for迴圈都要從0開始找起, 且遇到已經放在permut vector裡面的值需要跳過
 * 因此在這邊利用unordered_set來確認是否存在於permut vector裡面
 * ex:
 * 1
 * 1,2
 * 1,2,3
 * pop
 * 第二層的for指到下一個
 * 1,3
 * 又從頭開始找, 有在vector裡面跳過
 * 1,3,1(跳過), 1,3,2(push back), 1,3,3(跳過)
 */

using namespace std;
void permute_recursive(vector<vector<int>> &answer, vector<int> &nums,
                       unordered_set<int> &permut_check, vector<int> &permut, int begin)
{
    if (permut.size() == nums.size())
    {
        answer.push_back(permut);
    }

    for (int i = 0; i < nums.size(); i++)
    {
        if (!permut_check.count(nums[i]))
        {
            permut_check.insert(nums[i]);
            permut.push_back(nums[i]);

            permute_recursive(answer, nums, permut_check, permut, i + 1);

            permut.pop_back();
            permut_check.erase(nums[i]);
        }
    }
}

/**
 * Time: O(N!), Space: O(N)
 * 解題流程: 此方法直接in-place switch
 * pos為了紀錄目前進到第幾層recursive, 先進到最底層在一層一層回來
 * 解釋for迴圈那邊的swap
 * ex: [1,2,3]
 * 第一層pos=0, 第二層pos=1, 第三層pos=2
 * push_back 進answer
 * 回到第二層, i++ -> i指向下一個數字3
 * pos 和 i swap 因此此時nums變成[1,3,2]後push_back完再swap回來
 * 基本思路就是每一個i指向的數字會去和pos的數字去做swap
 * 利用swap來求得每一種permutation
 * ex: [1,2,3]
 * 交換順序就是[2,3]換, [1,2]換, [1,3]換
 */
vector<vector<int>> permute(vector<int> &nums)
{
    vector<vector<int>> answer;
    unordered_set<int> permut_check; // Check whether the value has already in the permu
    vector<int> permu;
    permute_recursive(answer, nums, permut_check, permu, 0);
    return answer;
}

void permute_recursive(int pos, vector<vector<int>> &answer, vector<int> &nums)
{
    if (pos == nums.size())
    {
        answer.push_back(nums);
    }
    for (int i = pos; i < nums.size(); i++)
    {
        swap(nums[i], nums[pos]);
        permute_recursive(pos + 1, answer, nums);
        swap(nums[i], nums[pos]);
    }
}
vector<vector<int>> permute(vector<int> &nums)
{
    vector<vector<int>> answer;
    permute_recursive(0, answer, nums);
    return answer;
}

int main()
{
    vector<int> vec{1, 2, 3};
    vector<vector<int>> answer = permute(vec);
    for (int i = 0; i < answer.size(); i++)
    {
        for (int j = 0; j < answer[i].size(); j++)
        {
            cout << answer[i][j] << " ";
        }
        cout << endl;
    }
}