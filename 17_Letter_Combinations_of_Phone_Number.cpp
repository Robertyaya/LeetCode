#include <bits/stdc++.h>
using namespace std;
/**
 * 
 * Time: O(3^N) (N is the size of input string), Space: O(N) (Recursive stack, 每次只會有跟input string相同大小的stack)
 * 解題流程: 要找出所有種可能, 基本上這種題型都是用Recursive去找
 * 首先需建立一個字典dic, 用來查找number所對應到的string
 * string out: 其中一個return 字串
 * vector<string> res: 所有return 字串
 * level: 用來記錄現在進入第幾個號碼了, 當level等於號碼的siZE時, 代表所有號碼都已經打完, 因此將現有的out加到res中
 * 根據號碼找出相對應的string
 * 接著tranverse那個string, 類似於tree的概念, 往下搜, 每個node會有自己的children
 * 並將所有可能塞到res中
 * 
 */
void letterCombinationDFS(string digits, vector<string> &dict, int level,
                          string out, vector<string> &res)
{
  if (level == digits.size())
  {
    res.push_back(out);
    return;
  }

  string str = dict[digits[level] - '0'];
  for (int i = 0; i < str.size(); i++)
  {
    letterCombinationDFS(digits, dict, level + 1, out + str[i], res);
  }
}
vector<string> letterCombinations(string digits)
{
  // Boundary case
  if (digits.empty())
    return {};

  vector<string> res;
  vector<string> dict{"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
  letterCombinationDFS(digits, dict, 0, "", res);
  return res;
}
