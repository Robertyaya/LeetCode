#include <bits/stdc++.h>
/**
 * Time: O(logN), Space: O(1)
 * 解題流程: 此題要找出第一個bad version, 而已經假設有一個API can use 去check current version whether is bad version
 * 可以當作是[0,0,0,1,1] 0 代表good version, 1 代表bad version, 當bad version出現後面的version皆為bad
 * 因此可當作要找出第一個1這樣的題目
 * 1. Array is sorted, use binary search
 * 2. 這邊要注意update r and l, 當檢測到目前version不是bad version, 則代表前面的都一定不是bad version, bad version一定是
 * 在mid的後面, 因此直接update l = mid + 1
 * 3. 然後update r時, 我們確認mid為bad version, 但此可能為first bad version or not we can't ensure, 因此update r = mid
 * 將right point to the current mid
 */
// The API isBadVersion is defined for you.
// bool isBadVersion(int version);
using namespace std;
int firstBadVersion(int n)
{
    int l = 0;
    int r = n;
    while (r > l)
    {
        int mid = l + (r - l) / 2;
        if (isBadVersion(mid))
            r = mid;
        else
            l = mid + 1;
    }
    return l;
}

int main()
{
}