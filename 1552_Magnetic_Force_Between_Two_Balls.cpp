/**
 * Time: O(NlogN), Space: O(1)
 * 解題流程: 利用binary search去找"max的長度"
 * 因此mid代表的是目標長度
 * 有了目標長度再根據這個長度去放球, 每放一個count++, 如果count>=m代表這個長度是ok的因此update 
 */
int maxDistance(vector<int> &position, int m)
{
  sort(position.begin(), position.end());
  int l = 0;
  int r = position.back();
  int res;
  // O(nlogn)
  while (l <= r)
  {
    // Target length
    int mid = l + (r - l) / 2;
    int count = 0;
    int pivot = -1e9; // 每放一個球則update pivot的位置
    for (int i = 0; i < position.size(); i++)
    {
      // 有超過taget length, 因此放一顆球, update pviot到此位置, 並count++
      if (position[i] - pivot >= mid)
      {
        pivot = position[i];
        count++;
      }
    }
    // 確認是否有將球放完,若大於等於代表此長度可以但不一定是最大
    if (count >= m)
    {
      // 將可以的長度設給res, update 左邊的pointer
      res = mid;
      l = mid + 1;
    }
    else
      r = mid - 1;
  }
  return res;
}
