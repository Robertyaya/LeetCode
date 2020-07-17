#include <bits/stdc++.h>
/**
 *  1,2,3->1,3,2
 *  3,2,1->1,2,3
 *  1,1,5->1,5,1
 */
/**
 * Time: O(N), Space: O(1)
 * 解題流程: premutation代表排列組合, 此題是要找出數值比現在input數值還要大一個的排列組合, 若此時input為最大的數值, 則找出最小的排列組合
 * 1. 從背後找過來, 目標是要找到第一個descending的數字. ex: 54361 -> 第一個descending的數字為3, 如果從後面找來一路ascending的話代表此數字數值為此排列組合最大
 * 2. 找到第一個descinding的數字後, 再從後面找來找一個比此數字還要大的數字來交換 (此數字為第一個descending的數字, 其實代表前面都是ascending,因此就是找第一個和其交換)
 * 3. 交換過後, 需要保持此數字後面所有的數字數值保持最小, 因此Reverse此數字後面數組, 大的丟到最後面, 小的丟到最前面, 從小到大排列
 * 4. Reverse: start指向第一個descending數字的後一個, end指向尾巴, 兩兩做交換直到交叉, 即可保持後面數組一定是從小到大排列 
 * ex: 54361 -> swap -> 54631 -> Reverse[3,1] -> 54613
 */
using namespace std;
void Reverse(vector<int> &nums, int start)
{
    int end = nums.size() - 1;
    while (end > start)
    {
        swap(nums[start], nums[end]);
        start++;
        end--;
    }
}
void nextPermutation(vector<int> &nums)
{
    int i = nums.size() - 2;

    // Find the first ascending index in vector from the back of vector
    // O(N)
    while (i >= 0 && nums[i] >= nums[i + 1])
        i--;

    if (i >= 0)
    {
        int j = nums.size() - 1;
        while (j >= 0 && nums[i] >= nums[j])
        {
            j--;
        }
        swap(nums[i], nums[j]);
    }
    // O(N)
    Reverse(nums, i + 1);
}

int main()
{
    vector<int> nums{3, 2, 1};
    nextPermutation(nums);
    for (int i = 0; i < nums.size(); i++)
        cout << nums[i] << " ";
    cout << endl;
}
