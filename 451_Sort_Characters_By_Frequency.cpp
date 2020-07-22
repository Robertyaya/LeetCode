#include <bits/stdc++.h>
using namespace std;
/**
 * Time: O(N), Space: O(N)
 * 解題流程: 此處邏輯跟下面方法一樣, 但這邊用priority_queue, which is built by heap
 * The time complexity of "push" is O(logN)
 * pop() and top() are O(1)
 * 寫priority compare function時, 有可能沒支援auto, 因此可以用templete的方式達到相同效果
 * 
 */

// template <typename T, typename U>
// bool cmp(T &l, U &r)
// {
//   return l.first > r.first;
// }
string frequencySort(string s)
{
  auto compare = [](auto a, auto b) {
    return a.first < b.first;
  };

  priority_queue<pair<int, char>, vector<pair<int, char>>, decltype(compare)> que(compare);
  unordered_map<char, int> map;

  // Build the map O(N),初始化為0, 因此直接++就好
  for (char c : s)
    map[c]++;

  // Insert into priority_queue O(logN)
  for (auto a : map)
    que.push({a.second, a.first});

  // Append to string O(N)
  string output = "";
  while (!que.empty())
  {
    pair<int, char> temp = que.top(); // O(1)
    que.pop();
    output.append(temp.first, temp.second); //append (size_t, char)
  }
  return output;
}
/**
 * Time: O(NlogN), Space: O(N)
 * 解題流程: 
 * Step1: 統計char出現次數
 * Step2: move to vector (為了要根據出現次數做sorting)
 * Step3: Sorting
 * Step4: Append to string
 */
string frequencySort(string s)
{
  unordered_map<char, int> map;
  unordered_map<char, int>::iterator iter;
  vector<pair<int, char>> vec;

  // Build the map O(N)
  for (int i = 0; i < s.size(); i++)
  {
    if ((iter = map.find(s[i])) != map.end())
      map[s[i]]++;
    else
      map[s[i]] = 1;
  }

  // Traverse the map and move to the vector O(N)
  for (iter = map.begin(); iter != map.end(); iter++)
  {
    pair<int, char> temp;
    temp.first = iter->second;
    temp.second = iter->first;
    vec.push_back(temp);
  }

  // Sorting O(NlogN) 根據出現次數大小做排序
  sort(vec.begin(), vec.end(), [](const auto &l, const auto &r) { return l.first > r.first; });

  // Append to new string O(N)
  string output = "";
  for (int i = 0; i < vec.size(); i++)
  {
    // str(size, char)
    string str(vec[i].first, vec[i].second);
    output += str;
  }
  return output;
}
