#include <bits/stdc++.h>
using namespace std;
/**
 * Time: O(logN), Space: O(1)
 * 解題流程: 一般的binary search, 若是沒找到則基於Nums[mid]比target大或nums[mid]比target小做判斷
 * 當nums[mid]比target大時, 代表要插在前面, 因此直接return mid現在的index
 * 當nums[mid]比target小時, 代表要插在後面, 因此return mid+1;
 * 之所以要用mid數值來判斷的原因在於left or right會在邊界處若沒找到則會形成交叉 r<l的情況, 而就會發生存取越界或是並不是在insert位置旁邊, 可能會差兩個
 * 因此採mid來做判斷可以確保insert位置不是在mid的左邊就是在右邊
 */
int searchInsert(vector<int> &nums, int target)
{
    int l = 0;
    int r = nums.size();
    while (l < r)
    {
        int mid = l + (r - l) / 2;
        if (nums[mid] >= target)
            r = mid;
        else
            l = mid + 1;
    }
    return l;
}
int main()
{
    vector<int> vec{1, 3};
    cout << searchInsert(vec, 2) << endl;
}
