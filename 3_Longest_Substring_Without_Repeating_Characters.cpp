#include <bits/stdc++.h>
using namespace std;
/** Time: O(N^2), Space: O(N) (Need to build the set to record whether is already exist)
 * 解題流程: 要找出最長的substring在string中, 並且裡面不能有duplicate的數字
 * 想法: 
 * i: 指向substring最右端
 * j: 指向substring最左端
 * i-j+1: current substring length
 * max_length: Global substring length
 * vecotr<int>: Record whether the s[i] is already in the substring (Use unordered map is slower)
 * s[i]is the key, i:is the value(s[i]'s index)
 * Tranverse string, 過程中如果沒有在substring則直接加入set中並且update現在的max_length
 * 
 * 關鍵在如果current char is already in the substring
 * 我們利用set找出duplicate的那個value的index
 * 接著開始從set中刪數字直到到達duplicate的value
 * 因為已經刪除之前那個duplicate的value, 我們可以將現在的value加入set中
 * [a,b,c,d,c,a]
 * 當i = 4(value = c時), j = 0
 * 此時會發現c已經在index2加入了, 代表此substring以結束(因為遇到了duplicate c)
 * 因此開始從j=0刪除直到刪除到index=3(也就是value d), 開始下一個新的substirng
 * 
 */

int lengthOfLongestSubstring(string s)
{
  // Check whether visit yet
  vector<int> set(256, -1);
  int j = 0;          // sub-string left index
  int max_length = 0; // Record the sub-string max length
  for (int i = 0; i < s.size(); i++)
  {
    if (set[int(s[i])] < 0) // Not in the sub-string yet, add it!
    {
      set[int(s[i])] = i;
    }
    else // Already in the sub-string
    {
      int duplicate_index = set[int(s[i])];

      // Remove the value until arrive the duplicate index
      while (j <= duplicate_index)
      {
        set[int(s[j])] = -1;
        j++;
      }

      // Insert this duplicate index
      set[int(s[i])] = i;
    }
    max_length = max(max_length, i - j + 1);
  }
  return max_length;
}
