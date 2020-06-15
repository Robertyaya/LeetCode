#include <bits/stdc++.h>
std::vector<int> twoSum(std::vector<int> &nums, int target)
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
    return answer;
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