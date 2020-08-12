/*
 * @lc app=leetcode id=241 lang=cpp
 *
 * [241] Different Ways to Add Parentheses
 */

// @lc code=start
class Solution
{
public:
    /**
 * 解題流程: 分為左右兩邊， 類似於tree的題型， 分為right subtree and left subtree
 * recursive下去做運算, 之後再return回來合併
 * 此處合併是根據operator來做合併
 * 此題可利用hash map做optimize, key為substring, value為substring的所有可能數值
 */
    vector<int> diffWaysToCompute(string input)
    {
        vector<int> res;
        unordered_map<string, vector<int>> map;
        for (int i = 0; i < input.size(); i++)
        {
            if (input[i] == '*' || input[i] == '+' || input[i] == '-')
            {
                // Left and right代表的是left substring的所有可能數值和right substring的所有可能數值
                // 因此下面要traverse left and right的所有可能去和operator做運算
                vector<int> left, right;
                if (auto iter = map.find(input.substr(0, i)) != map.end())
                    left = map[input.substr(0, i)];
                else
                {
                    left = diffWaysToCompute(input.substr(0, i));
                    map[input.substr(0, i)] = left;
                }

                if (auto iter = map.find(input.substr(i + 1)) != map.end())
                    right = map[input.substr(i + 1)];
                else
                {
                    right = diffWaysToCompute(input.substr(i + 1));
                    map[input.substr(i + 1)] = right;
                }

                for (int j = 0; j < left.size(); j++)
                {
                    for (int k = 0; k < right.size(); k++)
                    {
                        if (input[i] == '*')
                            res.push_back(left[j] * right[k]);
                        else if (input[i] == '+')
                            res.push_back(left[j] + right[k]);
                        else
                            res.push_back(left[j] - right[k]);
                    }
                }
            }
        }

        if (res.empty())
        {
            res.push_back(stoi(input));
            return res;
        }
        return res;
    }
    // ============================================================== //
    vector<int> diffWaysToCompute(string input)
    {
        vector<int> res;
        for (int i = 0; i < input.size(); i++)
        {
            if (input[i] == '*' || input[i] == '+' || input[i] == '-')
            {
                // Left and right代表的是left substring的所有可能數值和right substring的所有可能數值
                // 因此下面要traverse left and right的所有可能去和operator做運算
                vector<int> left, right;
                vector<int> left = diffWaysToCompute(input.substr(0, i));
                vector<int> right = diffWaysToCompute(input.substr(i + 1));

                // Traverse left substring and right substring的所有可能, 根據operator做合併
                for (int j = 0; j < left.size(); j++)
                {
                    for (int k = 0; k < right.size(); k++)
                    {
                        if (input[i] == '*')
                            res.push_back(left[j] * right[k]);
                        else if (input[i] == '+')
                            res.push_back(left[j] + right[k]);
                        else
                            res.push_back(left[j] - right[k]);
                    }
                }
            }
        }

        // 如果res為empty(), 代表substring為只有一個數字, 並沒有可以分成兩半, 因此直接將現在這個數字塞到res中return
        if (res.empty())
        {
            res.push_back(stoi(input));
            return res;
        }
        return res;
    }
};
// @lc code=end
