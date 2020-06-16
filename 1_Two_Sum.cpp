#include <bits/stdc++.h>
#include <unordered_map>

// Time: O(N^2), Space: O(1)
std::vector<int> twoSum_Naive(std::vector<int> &nums, int target)
{
    std::vector<int> answer;
    for (int i = 0; i < nums.size() - 1; i++)
    {
        int b = target - nums[i];
        for (int j = i + 1; j < nums.size(); j++)
        {
            if (b == nums[j])
            {
                answer.push_back(i);
                answer.push_back(j);
                return answer;
            }
        }
    }
}

/**
 * Time: O(N), Space: O(N) (因為要build hash table)
 * 解題流程: Use hash table, Key紀錄的是nums[i], value紀錄的是其index
 * 每次都會去從map中找當下nums[i]所對應的差值, 若此差值存在則代表此序列中可以相加成target數值
 * ex: target=9, input:2, 7.  第一個迴圈會先檢查 9-2有沒有在map裡面, 一開始沒有則將2當成key, 其index為value放到map裡面
 * 第二次檢查9-7有沒有在map裡面, 前面已經將2放入迴圈裡面, 因此此時count will return 1因為已經存在
 */
std::vector<int> twoSum(std::vector<int> &nums, int target)
{
    std::unordered_map<int, int> map;
    // Build the map
    for (int i = 0; i < nums.size(); i++)
    {
        int diff = target - nums[i];

        // Key is valid return 1, invalid return 0
        if (map.count(diff))
        {
            return {map[diff], i};
        }
        map[nums[i]] = i;
    }
    return {};
}

int main()
{
    int target = 0;
    std::vector<int> input;
    input.push_back(-3);
    input.push_back(4);
    input.push_back(3);
    input.push_back(90);
    std::vector<int> temp = twoSum(input, target);
    for (int i = 0; i < temp.size(); i++)
        std::cout << temp[i] << " " << std::endl;
}