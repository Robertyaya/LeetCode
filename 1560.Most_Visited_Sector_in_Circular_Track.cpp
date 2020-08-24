
/**
 * Time: O(N^2), Space: O(N)
 * 解題流程:
 * [1,2,3,4..n] 分別計算每一站在整個馬拉松過程中會經過幾次, i就是迭代每一站
 * start<i<=end滿足此條件代表有在那一段過程中則加入
 * 比較麻煩的是需要考慮circular問題
 * start<i or i<=end 都是有可能的
 */
vector<int> mostVisited(int n, vector<int> &rounds)
{
  vector<int> res;
  // 紀錄每個點經過幾次
  vector<int> count(n + 1, 0);
  // 紀錄最大經過幾次
  int max_count = 0;

  for (int i = 1; i <= n; i++)
  {
    // 起始點相同的話要先加1
    if (i == rounds[0])
      count[i]++;

    for (int j = 1; j < rounds.size(); j++)
    {
      int start = rounds[j - 1]; // 起始點
      int end = rounds[j];       // 終點
      // 此種狀態最單純, 只要i有在起點和終點中間, 代表一定有經過
      if (end >= start && (i > start && i <= end))
      {
        count[i]++;
      }
      // 要考慮circular的問題
      else if (end < start && (i > start || i <= end))
      {
        count[i]++;
      }
      max_count = max(max_count, count[i]);
    }
  }

  // 找出和max_count相同的放入res中
  for (int i = 0; i < count.size(); i++)
  {
    if (count[i] == max_count)
      res.push_back(i);
  }
  return res;
}
