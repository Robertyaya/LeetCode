#include <bits/stdc++.h>
using namespace std;
/**
 * Time: O(N), Sapce: O(1)
 * 解題流程: Kadane's Algorithm (Dynamic programming)
 * maxCurrentPrefix: 紀錄的是是否當前這個prefix max value比較大, 或是前面已經加總的Answer + 當前數字比較大
 * 如果前面加總的answer+current較大, 則將current納入, 若沒有則清掉目前的answer直接設為current value就好
 * maxALL: 則是紀錄current max是否有比之前的大, 有的話則update
 * 
 * maxCurrentPrefix: 兩種可能
 * 1. 把current value納入, 此prefix繼續增加
 * 2. current value直接就比納入後的數值大, 那就不用納入直接選current value為current max prefix
 * 而剛剛的那個prefix就結束了, 因為現在已經有一個數值比之前的prefix還大
 * 
 * maxAll:則是update目前的current max prefix是否比較大, 有則update maxAll, 沒有
 * 的話則代表此prefix可以被捨棄掉因為選之前那個就好
 * 
 */
// Dynamic Programming method
int maxSubArray(vector<int> &nums)
{
    int maxALL = nums[0];
    int maxCurrentPrefix = nums[0];
    for (int i = 1; i < nums.size(); i++)
    {
        maxCurrentPrefix = max(maxCurrentPrefix + nums[i], nums[i]);
        maxALL = max(maxCurrentPrefix, maxALL);
    }
    return maxALL;
}

// Divide and Conquer method
/**
 * Time: O(NlogN) (N 是在計算maxCrossSum), Space: O(logN) (N個數字會在recursive放到系統的stack中, 而高為logN)
 * 解題流程: 分為3個部份
 * 1. left max sum 
 * 2. right max sum
 * 3. cross sum
 * left max sum and right max sum都是針對單一數字去return
 * 關鍵在於cross sum!
 * 當只有3個數字時, [a,b,c]
 * left max sum = a, right max sum = max(b,c)
 * 而cross sum則是max(a+b, c, a+b+c)的數值
 * 因此當回傳max(left max sum, right max sum, cross sum)的概念就是去判斷
 * [a], [b,c], [a,b], [c], [a,b,c] 這幾個哪個比較大
 * 在maxCrossSum中計算left sum時, 要從mid開始往左找, 因為要連續的, 如果從左開始往mid找找到的sum不一定是和右邊連續
 * 則在計算left_sum+right_sum時, 則違反定義
 * 
 */
int max(int a, int b, int c)
{
    return std::max(std::max(a, b), c);
}
// O(N)
int maxCrossSum(vector<int> &nums, int left, int mid, int right)
{
    int sum = 0;
    int left_sum = INT_MIN; // Need to be updated

    // Need to search from mid to left!!
    for (int i = mid; i >= left; i--)
    {
        sum += nums[i];
        if (sum > left_sum)
            left_sum = sum;
    }

    sum = 0;
    int right_sum = INT_MIN;
    for (int i = mid + 1; i <= right; i++)
    {
        sum += nums[i];
        if (sum > right_sum)
            right_sum = sum;
    }
    return max(left_sum, right_sum, left_sum + right_sum);
}
int maxSubArraySum(vector<int> &nums, int left, int right)
{
    // Base case: only one value in vector
    if (left == right)
    {
        return nums[left];
    }

    int mid = (left + right) / 2;
    return max(maxSubArraySum(nums, left, mid),
               maxSubArraySum(nums, mid + 1, right), maxCrossSum(nums, left, mid, right));
}
int maxSubArray_(vector<int> &nums)
{
    return maxSubArraySum(nums, 0, nums.size() - 1);
}
int main()
{
    vector<int> vec{-1, -2, -3, 0};
    cout << maxSubArray_(vec) << endl;
}