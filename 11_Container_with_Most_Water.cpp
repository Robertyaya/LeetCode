#include <bits/stdc++.h>
using namespace std;

/**
 * Time: O(N), Space: O(1)
 * 解題流程: 先取寬度最寬的情況設為initial area, 因此如果要大於此寬度最寬的initial area, 目標找出
 * height較高的邊, "height又取決於左右兩邊較短的那一邊, 因此只要有一邊的heigth較短, 則整體的area一定較小"
 * 因此要找出較大的area的話, 兩邊的height一定都要較大
 * 當左邊的hegiht小於current height, 則update到下一個
 * 當右邊的height小於current height, 則也要update到下一個
 */

int maxArea(vector<int> &height)
{
    int max_area = 0;
    int r = height.size() - 1;
    int l = 0;
    while (r > l)
    {
        // Choose the minimum height set as the height
        int h = std::min(height[l], height[r]);

        // Update the area
        max_area = std::max(max_area, (r - l) * h);
        // Update l, until we find the higher height
        while (height[l] <= h && l < r)
            l++;
        // Update r, until we find the higher height
        while (height[r] <= h && l < r)
            r--;
    }
    return max_area;
}

int main()
{
    std::vector<int> vec;
    vec.push_back(1);
    vec.push_back(8);
    vec.push_back(6);
    vec.push_back(2);
    vec.push_back(5);
    vec.push_back(4);
    vec.push_back(8);
    vec.push_back(9);
    vec.push_back(7);

    std::cout << maxArea(vec) << std::endl;
}