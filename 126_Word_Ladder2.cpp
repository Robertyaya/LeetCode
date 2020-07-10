#include <bits/stdc++.h>
using namespace std;
vector<vector<string>> findLadders(string beginWord, string endWord, vector<string> &wordList)
{
  // Build the map
  unordered_set<string> set;
  for (auto v : wordList)
    set.insert(v);

  // endWord not in the wordlist
  if (!set.count(endWord))
    return {};

  vector<vector<string>> res;
  queue<string> que;
  que.push(endWord);
  while (!que.empty())
  {
  }
}
