#include <bits/stdc++.h>
using namespace std;
/**
 * Time: O(N), Space: O(N) (Need the map to record)
 * 解題流程: 將相同string但不同排列組合的group在一起. ex: eat, aet -> same category
 * Tranverse every string in vector
 * map中save sorting過後的string以及在answer中的index, 可視為存different category
 * 先sorting過的目的是將eat and aet都換成->aet 這樣就可以判斷是不是同一個category
 * 每次迭代過程中先對每個string sorting, 若string沒有很長則視為O(1)
 * 並到map檢查, 如果沒有則代表目前沒有此category, 因此新增一個category加到answer裡面以及map裡面
 * 有的話則取出此category的index, 再根據此index將current string加到目前的answer vector裡面
 * 
 */
vector<vector<string>> groupAnagrams(vector<string> &strs)
{
  // Key is string, value is index in answer
  unordered_map<string, int> map;
  vector<vector<string>> answer;

  // O(N)
  for (int i = 0; i < strs.size(); i++)
  {
    string sort_str = strs[i];
    sort(sort_str.begin(), sort_str.end());
    if (!map.count(sort_str)) // Not in the map, we need to insert new category
    {
      vector<string> new_category;
      new_category.push_back(strs[i]);
      answer.push_back(new_category);    // Push back the new category into answer vector
      map[sort_str] = answer.size() - 1; // Insert the new category into map
    }
    else // Str is in the map
    {
      int index = map[sort_str];
      answer[index].push_back(strs[i]);
    }
  }
  return answer;
}
