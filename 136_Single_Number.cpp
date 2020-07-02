#include <bits/stdc++.h>
using namespace std;
/**
 * Time: O(N), Space: O(1)
 * 解題流程: 利用XOR
 * 0011
 * 0101
 * ----- XOR
 * 0110 
 * 數字相同的話為0, 不同則為1
 * 因此可利用這性質且XOR有交換律
 * ex: [1,2,3,2,3]
 * 1^2^3^2^3 => 1^(2^2)^(3^3) => 1^(0)^(0) => 1
 */
int singleNumber(vector<int> &nums)
{
    int answer = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        answer = nums[i] ^ answer;
    }
    return answer;
}
/**
 * Time: O(N), Space: O(N)
 * 解題流程: Traverse element in nums, 還沒被加入hash map中則加入, 已經加入的代表為成對的
 * 將其erase掉, 最後剩下的就是singel的那個將其return
 */
int singleNumber(vector<int> &nums)
{
    unordered_set<int> set;
    // O(N)
    for (int i = 0; i < nums.size(); i++)
    {
        if (set.count(nums[i]))
            set.erase(nums[i]);
        else
            set.insert(nums[i]);
    }
    // 取出在set中的最後一個, 因為成對的都已經erase掉了
    auto value = set.cbegin();
    return *value;
}
