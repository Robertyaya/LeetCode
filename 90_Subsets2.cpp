#include <bits/stdc++.h>
using namespace std;
/**
 * Time: O(2^N), Space: O(N)
 * 解題流程: Same as problem 40, input vector中會有duplicate value
 * ex:[1,2,2]->如果沒有在recursive中那個for迴圈前面加那個判斷式
 * 會找出兩個[1,2]一個是從index 1, 一個是從index 2
 * 因此加那個判斷式可以確保只有第一個遇到的i==begin會被塞入, 第二個相同的數字則不會進入
 * 但為了做這件事, 前面一定要先sorting過, 不然相同的數字就不會放在一起
 * 
 */
void subset_recursive(vector<vector<int>> &answer, vector<int> &nums,
                      vector<int> &subset, int begin)
{
    answer.push_back(subset);
    for (int i = begin; i < nums.size(); i++)
    {
        if(i == begin || nums[i]!=nums[i-1]
        {
            subset.push_back(nums[i]);
            suset(answer, nums, subset, i + 1);
            subset.pop_back();
        }
    }
}

vector<vector<int>> subsetsWithDup(vector<int> &nums)
{
    sort(nums.begin(), nums.end());
    vector<vector<int>> answer;
    vector<int> subset;
    subset_recursive(answe, nums, subset, 0);
    return answer;
}
int main()
{
}