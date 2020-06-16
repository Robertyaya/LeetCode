#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

/**
  *Time: O(N), Space: O(1)
  * 解題流程: 因為input array is sorted, 所以我們不用另外再建一個hash map浪費空間, 利用sorted的特性
  * 初始化left point and right pointer, left pointer指向初始位置, right pointer指向尾巴
  * 不斷的update left pointer or right pointer
  * 當加起來數值小於target時代表left pointer 要向前一個位置
  * 當加起來數值大於target時代表right pointer要向後一個位置
  * 直到sum = target時則return 此時的left pointer and right pointer
  */
vector<int> twoSum(vector<int> &numbers, int target)
{
    int l = 0;
    int r = numbers.size() - 1;
    while (l < r)
    {
        int sum = numbers[l] + numbers[r];
        if (sum == target)
            return {l + 1, r + 1}; // This problem is 1-based not the 0-based
        else if (sum < target)
            l++;
        else
            r--;
    }
    return {};
}

int main()
{
    int target = 9;
    std::vector<int> input;
    input.push_back(2);
    input.push_back(7);
    input.push_back(11);
    input.push_back(15);
    std::vector<int> temp = twoSum(input, target);
    for (int i = 0; i < temp.size(); i++)
        std::cout << temp[i] << " " << std::endl;
}