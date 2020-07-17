#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;

/**
 * Time: O(N^2), Space: O(1)
 * 解題流程: 
 * 1. Soring first (O（NlogN)）
 * 2. 先固定一個value, 計算出target value將three sum 問題降為two sum (the input is sorted problem)
 * 3. left pointer 指向起始點, right pointer 指向結束點 開始update (因為已經sorting 過)
 * 4. 當小於target則update left pointer, 當大於target則update right pointer
 * 5. 關鍵一步在於要如何skip掉相同的數組 ex: (-1, 0, 1), (0, -1, 1) 沒處理的話這兩個都會被放入answer裡面
 * 6. 分別迭代left and right pointer直到指向的數字和push_back進answer的數字不同, 才代表維新的一組數組
 * 7. 因為在此步i為固定, 因此若left or right指向的數字和前一步相同, 則所對應的數組"一定"為相同
 * 8. 最後再迭代i 如果此處也不能和上一步一樣, 因為和上一步一樣則又會找到相同的right and left 因此最後要迭代i直到不相同的數字
 */

vector<vector<int>> threeSum(vector<int> &nums)
{
    vector<vector<int>> answer;

    // Soring first O(NlogN)
    sort(nums.begin(), nums.end());

    // O(N^2), 輪流當constant value
    for (int i = 0; i < nums.size(); i++)
    {
        // The target is same as two sum problem the input is sorted
        if (nums[i] > 0)
            return answer;

        int target = -nums[i];
        int left = i + 1;
        int right = nums.size() - 1;
        while (right > left)
        {
            if (nums[left] + nums[right] < target)
                left++;
            else if (nums[left] + nums[right] > target)
                right--;
            else
            {
                vector<int> temp = {nums[i], nums[left], nums[right]};
                answer.push_back(temp);

                // Skip the same value, 要繼續找下一個可能
                while (left < right && nums[left] == temp[1])
                    left++;
                while (left < right && nums[right] == temp[2])
                    right--;
            }
        }
        // 越過相同的constan value
        while (i + 1 < nums.size() && nums[i] == nums[i + 1])
            i++;
    }
    return answer;
}

int main()
{
    vector<int> vec;
    vec.push_back(-1);
    vec.push_back(0);
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(-1);
    vec.push_back(4);
    vector<vector<int>> answer = threeSum(vec);

    for (int i = 0; i < answer.size(); i++)
    {
        for (int j = 0; j < 3; j++)
        {
            std::cout << answer[i][j] << " ";
        }
        std::cout << std::endl;
    }
}